cmake_minimum_required(VERSION 3.10)
project(compressor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(rle STATIC src/rle.cpp)
target_include_directories(rle PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC rle)
