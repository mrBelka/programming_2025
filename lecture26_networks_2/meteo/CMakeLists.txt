cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME meteo) 			 # задать значение PROJECT_NAME	
project("${PROJECT_NAME}" LANGUAGES CXX)           # установить имя проекта

set(CMAKE_CXX_STANDARD 20)			 # устанавливаем 17 стандарт языка

# Сказать программе, что должен быть исполняемый файл
add_library("${PROJECT_NAME}" STATIC inc/meteo/formats.hpp src/test.cpp)

target_include_directories("${PROJECT_NAME}" PUBLIC inc)
