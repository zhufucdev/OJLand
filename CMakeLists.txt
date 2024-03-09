cmake_minimum_required(VERSION 3.23)
project(Playground)

set(CMAKE_CXX_STANDARD 14)
add_compile_definitions(DEBUG)

add_executable(Playground main.cpp)

add_executable(How how.cpp)
