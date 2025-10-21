cmake_minimum_required(VERSION 3.10)
project(compressor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(ALGORITHMS_DIR ${CMAKE_SOURCE_DIR}/src/algorithms)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

include_directories(${INCLUDE_DIR})

set(ALGORITHM_SOURCES
  ${ALGORITHMS_DIR}/rle.cpp
)

add_executable(${PROJECT_NAME}
  ${SRC_DIR}/main.cpp
  ${SRC_DIR}/utils.cpp
  ${ALGORITHM_SOURCES}
)

