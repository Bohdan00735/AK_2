
cmake_minimum_required(VERSION 3.10.2)

project("Lab2_Computer_Arch" VERSION 0.0.1)

add_library(cppproj STATIC calculator.cpp)
add_executable("${PROJECT_NAME}" main.cpp)
target_link_libraries("${PROJECT_NAME}" calculator_lab)
