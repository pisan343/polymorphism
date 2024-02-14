#!/bin/bash

# shortcut to compile and run the program

echo "========================="
echo "* Compiling without horse.cpp"
rm -f a.out
g++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare main.cpp pet.cpp cat.cpp dog.cpp
./a.out 

echo "========================="
echo "* Compiling with horse.cpp"
rm -f a.out
g++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare main.cpp pet.cpp cat.cpp dog.cpp horse.cpp
./a.out 
