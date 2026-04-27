cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
project(meteo_project LANGUAGES CXX)
add_subdirectory(meteo)
add_subdirectory(synchro_client)
add_subdirectory(synchro_server)