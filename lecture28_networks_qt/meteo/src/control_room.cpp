#define ASIO_STANDALONE

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

#include <asio.hpp>

#include <meteo/control_room.hpp>
#include <meteo/formats.hpp>

namespace {
constexpr unsigned short SSH_PORT = 22;
} // namespace

namespace meteo {
using namespace std::chrono_literals;
ControlRoom::ControlRoom(const Params& params) : params_(params) 
{
  for (const auto meteostation : params_.meteostations) {
    if(meteostation.port == 0 || meteostation.port == SSH_PORT) {
      throw std::invalid_argument("[ControlRoom::ctor]: invalid port value");
    }
    if(meteostation.ip.empty()) {
      throw std::invalid_argument("[ControlRoom::ctor]: ip have to be not empty");
    }
    // TODO: check all params
  }
}

void ControlRoom::run()
{
  asio::io_context io_context;

  while(true) {
    for (const auto& meteo : params_.meteostations) {
        // Адрес и порт сервера
        asio::ip::tcp::endpoint endpoint(
            asio::ip::make_address(meteo.ip), 
            meteo.port
        );
        
        // Создаём сокет
        asio::ip::tcp::socket socket(io_context);
        
        try {
            std::cout << "Connecting to server " << meteo.description << std::endl;
            
            // Подключаемся
            socket.connect(endpoint);
            
            std::cout << "Connected!" << std::endl;
        }
        catch (const std::exception& ex) {
            std::cout << "Server is unavailable" << std::endl;
            continue;
        }
        
        // Отправляем сообщение
        std::string message = "Hello from client!";
        asio::write(socket, asio::buffer(message));
        
        std::cout << "Sended: " << message << std::endl;
        
        // Получаем ответ
        char reply[sizeof(meteo::MeteoInfo)];
        std::error_code ec;
        size_t length = socket.read_some(asio::buffer(reply), ec);

        if (!ec) {
            std::cout << "Server reply: " << std::endl;

            meteo::MeteoInfo info = *reinterpret_cast<meteo::MeteoInfo*>(reply);
            std::cerr << info << std::endl;
        } else {
            std::cout << "Ошибка получения ответа: " << ec.message() << std::endl;
        }
    }
    std::this_thread::sleep_for(1s);
  }
}

std::vector<meteo::MeteoInfo> ControlRoom::run_once()
{
  std::vector<meteo::MeteoInfo> meteoinfo;
  meteoinfo.reserve(params_.meteostations.size());

  asio::io_context io_context;
  for (const auto& meteo : params_.meteostations) {
      // Адрес и порт сервера
      asio::ip::tcp::endpoint endpoint(
          asio::ip::make_address(meteo.ip), 
          meteo.port
      );
      
      // Создаём сокет
      asio::ip::tcp::socket socket(io_context);
      
      try {
          std::cout << "Connecting to server " << meteo.description << std::endl;
          
          // Подключаемся
          socket.connect(endpoint);
          
          std::cout << "Connected!" << std::endl;
      }
      catch (const std::exception& ex) {
          std::cout << "Server is unavailable" << std::endl;
          continue;
      }
      
      // Отправляем сообщение
      std::string message = "Hello from client!";
      asio::write(socket, asio::buffer(message));
      
      std::cout << "Sended: " << message << std::endl;
      
      // Получаем ответ
      char reply[sizeof(meteo::MeteoInfo)];
      std::error_code ec;
      size_t length = socket.read_some(asio::buffer(reply), ec);

      if (!ec) {
          std::cout << "Server reply: " << std::endl;

          meteo::MeteoInfo info = *reinterpret_cast<meteo::MeteoInfo*>(reply);
          meteoinfo.emplace_back(info);
          std::cerr << info << std::endl;
      } else {
          std::cout << "Ошибка получения ответа: " << ec.message() << std::endl;
      }
  }
  return meteoinfo;
}
} // namespace meteo