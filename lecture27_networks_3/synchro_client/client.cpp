#define ASIO_STANDALONE

#include <asio.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <nlohmann/json.hpp>

#include <meteo/formats.hpp>

using json = nlohmann::json;
using namespace std::chrono_literals;

struct Params {
    std::string ip;
    std::string description;
    unsigned short port;
};

std::vector<Params> read_configuration(const std::string& filename) {
    std::ifstream in(filename);
    if (!in.is_open()) {
        throw std::runtime_error("Config.json not found");
    }
    json data = json::parse(in);

    std::vector<Params> params;
    params.reserve(data.size());

    for(const auto& elem : data) {
        Params param;
        param.ip = elem["ip"];
        param.port = elem["port"].get<unsigned short>();
        param.description = elem["description"];
        
        params.emplace_back(param);
    }
    return params;
}

int main() {
    try {
        const auto meteostations = read_configuration("config.json");

        asio::io_context io_context;

        while(true) {
        
            for (const auto& meteo : meteostations) {
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
        
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unhandled exception!" << std::endl;
    }
    
    return 0;
}