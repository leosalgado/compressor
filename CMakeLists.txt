cmake_minimum_required(VERSION 3.10)
project(compressor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

include_directories(${INCLUDE_DIR})

file(GLOB ALGORITHM_SOURCES "${SRC_DIR}/algorithms/*.cpp")

add_executable(${PROJECT_NAME}
  ${SRC_DIR}/main.cpp
  ${SRC_DIR}/utils.cpp
  ${ALGORITHM_SOURCES}
)

