cmake_minimum_required(VERSION 3.15)
project(BINGO)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "C:/LIbs/SFML/include")
set(SFML_LIBRARY_DIR "C:/LIbs/SFML/lib")
set(SFML_DIR "C:/LIbs/SFML/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(BINGO main.cpp Button.h Textbox.h)
target_link_libraries (BINGO sfml-graphics sfml-window sfml-system)