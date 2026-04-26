#define ASIO_STANDALONE

#include <asio.hpp>
#include <iostream>

#include <meteo/formats.hpp>

int main() {
    try {
        asio::io_context io_context;
        
        // Адрес и порт сервера
        asio::ip::tcp::endpoint endpoint(
            asio::ip::make_address("127.0.0.1"), 
            12345
        );
        
        // Создаём сокет
        asio::ip::tcp::socket socket(io_context);
        
        std::cout << "Connecting to server..." << std::endl;
        
        // Подключаемся
        socket.connect(endpoint);
        
        std::cout << "Connected!" << std::endl;
        
        // Отправляем сообщение
        std::string message = "Hello from client!";
        asio::write(socket, asio::buffer(message));
        
        std::cout << "Sended: " << message << std::endl;
        
        // Получаем ответ
        char reply[sizeof(meteo::MeteoInfo)];
        std::error_code ec;
        size_t length = socket.read_some(asio::buffer(reply), ec);
        
        meteo::MeteoInfo info = *reinterpret_cast<meteo::MeteoInfo*>(reply);

        std::cerr << info.datetime.year << std::endl;

        if (!ec) {
            std::cout << "Server reply: " 
                      << std::string(reply, length) << std::endl;
        } else {
            std::cout << "Ошибка получения ответа: " << ec.message() << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unhandled exception!" << std::endl;
    }
    
    return 0;
}