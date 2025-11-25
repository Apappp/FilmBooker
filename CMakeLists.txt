cmake_minimum_required(VERSION 3.10)

project(FilmBooker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Folder z nagłówkami
include_directories(include)

# Wszystkie pliki .cpp w src/
file(GLOB SOURCES
    src/*.cpp
)

# Tworzymy wykonywalny program
add_executable(${PROJECT_NAME} ${SOURCES})

