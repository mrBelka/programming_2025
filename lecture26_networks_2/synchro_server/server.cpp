#define ASIO_STANDALONE

#include <asio.hpp>
#include <iostream>

#include <meteo/formats.hpp>

int main() {
    try {
        asio::io_context io_context;
        
        // Создаём endpoint (слушаем все интерфейсы, порт 12345)
        asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), 12345);
        
        // Создаём и открываем acceptor
        asio::ip::tcp::acceptor acceptor(io_context, endpoint);
        
        std::cout << "Server starter on port 12345 ..." << std::endl;
        
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

        meteo::Datetime dt;
        dt.year = 2026;
        dt.month = 4;

        meteo::MeteoInfo info;
        info.datetime.year = 2026;
        info.datetime.month = 4;
        info.temp = 12.34f;
        info.humidity = 65.f;
        info.wind_velocity = 1.5f;

        char* ptr = reinterpret_cast<char*>(&info);
        std::vector<char> vec(sizeof(meteo::MeteoInfo));
        for (size_t i = 0; i < sizeof(meteo::MeteoInfo); ++i) {
            vec[i] = *(ptr + i);
        }

        std::string reply = "Hello from server!";
        asio::write(socket, asio::buffer(vec));
        
        std::cout << "Answer sended" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unhandled exception" << std::endl;
    }
    
    return 0;
}