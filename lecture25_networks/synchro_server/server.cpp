#define ASIO_STANDALONE

#include <asio.hpp>
#include <iostream>

int main() {
    try {
        asio::io_context io_context;
        
        // Создаём endpoint (слушаем все интерфейсы, порт 12345)
        asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), 12345);
        
        // Создаём и открываем acceptor
        asio::ip::tcp::acceptor acceptor(io_context, endpoint);
        
        std::cout << "Server starter 12345" << std::endl;
        
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
        std::string reply = "Hello from server!";
        asio::write(socket, asio::buffer(reply));
        
        std::cout << "Answer sended" << std::endl;
        
    } catch (std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    
    return 0;
}