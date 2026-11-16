cmake_minimum_required(VERSION 3.16)

project(LogAnalyzer
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(log_analyzer
    src/main.cpp
    src/log_parser.cpp
    src/log_analyzer.cpp
)

target_include_directories(log_analyzer PRIVATE
    inc
)

target_compile_options(log_analyzer PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)