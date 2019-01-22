cmake_minimum_required(VERSION 3.12)
project(poly-pet-factory-self-register)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra")

# add_executable("${PROJECT_NAME}-mac.exe" main.cpp horse.cpp horse.h pet.cpp pet.h)

add_executable(poly-pet-factory-self-register
        # include/exclude Horse class
        horse.cpp horse.h
        main.cpp pet.cpp pet.h)