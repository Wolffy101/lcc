cmake_minimum_required(VERSION 3.10)
project(c100)
enable_testing()
set(CMAKE_CXX_STANDARD 17)
include_directories(include)

aux_source_directory(src SRC_LIST)

message("${SRC_LIST}")

add_executable(${PROJECT_NAME} main.cpp ${SRC_LIST})