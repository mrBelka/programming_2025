cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME mylib_shared) 			 # задать значение PROJECT_NAME	
# set(CMAKE_INSTALL_PREFIX ".." CACHE PATH "Installation directory")	 
project("${PROJECT_NAME}")           # установить имя проекта

set(CMAKE_CXX_STANDARD 20)			 # устанавливаем 17 стандарт языка

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

#if(MSVC)
#    add_compile_options(/MDd)  # Статическая линковка CRT
#endif()

add_library("${PROJECT_NAME}" SHARED inc/functions.hpp src/functions.cpp)

#set_property(TARGET "${PROJECT_NAME}" PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

target_include_directories("${PROJECT_NAME}" PUBLIC inc)

# Intsallation
#set_target_properties(mylib PROPERTIES
#    PUBLIC_HEADER inc/functions.hpp
#)

#install(TARGETS mylib
#    ARCHIVE DESTINATION "${PROJECT_NAME}" # lib
#    LIBRARY DESTINATION "${PROJECT_NAME}" # dll
#	PUBLIC_HEADER DESTINATION "${PROJECT_NAME}/inc" # headers
#)
