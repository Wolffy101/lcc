cmake_minimum_required(VERSION 3.10)
set(MAIN_NAME c100)
set(MAIN_LIB c100_lib)
project(${MAIN_NAME})

enable_testing()
set(CMAKE_CXX_STANDARD 17)


include_directories(include)

aux_source_directory(src SRC_LIST)

add_library("${MAIN_LIB}" ${SRC_LIST})

message("${SRC_LIST}")

add_executable(${MAIN_NAME} main.cpp ${SRC_LIST})

add_subdirectory(test)
