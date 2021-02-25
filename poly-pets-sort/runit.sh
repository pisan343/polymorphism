#!/bin/bash

# shortcut to compile and run the program

rm -f a.out
g++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare *.cpp
./a.out 

