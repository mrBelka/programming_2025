#define ASIO_STANDALONE

#include <asio.hpp>
#include <iostream>
#include <chrono>
#include <thread>

#include <meteo/formats.hpp>

meteo::MeteoInfo prepare_meteo_info(const size_t id)
{
    meteo::MeteoInfo info;
    info.id = id;
    info.datetime.year = 2026;
    info.datetime.month = 4;
    info.datetime.day = 1;
    info.datetime.hour = 23;
    info.datetime.min = 15;
    info.datetime.sec = 45;
    info.temp = 12.34f + (rand() % 100) * 0.1;
    info.humidity = 65.f;
    info.wind_velocity = 1.5f;

    return info;
}

std::vector<char> to_bytes_array(const meteo::MeteoInfo& info)
{
    const char* ptr = reinterpret_cast<const char*>(&info);
    std::vector<char> vec(sizeof(meteo::MeteoInfo));
    for (size_t i = 0; i < sizeof(meteo::MeteoInfo); ++i) {
        vec[i] = *(ptr + i);
    }
    return vec;
}

using namespace std::chrono_literals;

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cout << "Usage: sychro_server.exe <port> <id>" << std::endl;
        return -1;
    }

    try {
        unsigned short port = std::stoi(argv[1]);
        const size_t id = std::stoull(argv[2]);

        asio::io_context io_context;
        
        // Создаём endpoint (слушаем все интерфейсы, порт 12345)
        asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), port);
        
        // Создаём и открываем acceptor
        asio::ip::tcp::acceptor acceptor(io_context, endpoint);
        
        std::cout << "Server starter on port " << port << "..." << std::endl;
        
        while(true) {
            // Ожидаем подключения клиента
            asio::ip::tcp::socket socket(io_context);
            acceptor.accept(socket);
            
            std::cout << "Client connected!" << std::endl;
            
            // Буфер для приёма данных
            char data[1024];
            
            // Читаем данные от клиента
            std::error_code ec;
            size_t length = socket.read_some(asio::buffer(data), ec);
            
            if (!ec) {
                std::cout << "Recieve: " 
                        << std::string(data, length) << std::endl;
            } else {
                std::cout << "Error: " << ec.message() << std::endl;
            }
            
            // Отправляем ответ
            const auto info = prepare_meteo_info(id);
            const auto output_buf = to_bytes_array(info);

            std::string reply = "Hello from server!";
            asio::write(socket, asio::buffer(output_buf));
            
            std::cout << "Answer sended" << std::endl;

            std::this_thread::sleep_for(100ms);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unhandled exception" << std::endl;
    }
    
    return 0;
}