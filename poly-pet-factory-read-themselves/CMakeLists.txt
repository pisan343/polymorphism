cmake_minimum_required(VERSION 3.12)
project(poly-pet-factory-read-themselves)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra")

add_executable("${PROJECT_NAME}-mac.exe" pets.cpp)
