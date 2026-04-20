cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME synchro_client) 			 # задать значение PROJECT_NAME		 
project("${PROJECT_NAME}")           # установить имя проекта


set(CMAKE_CXX_STANDARD 20)			 # устанавливаем 17 стандарт языка
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

include_directories("../ext/asio/include")

# Сказать программе, что должен быть исполняемый файл
add_executable("${PROJECT_NAME}" client.cpp)