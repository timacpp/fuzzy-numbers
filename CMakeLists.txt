cmake_minimum_required(VERSION 3.20)
project(fuzzy)

set(CMAKE_CXX_STANDARD 20)

add_executable(fuzzy src/main.cpp src/FuzzyNum.cpp src/FuzzyNum.h
                                  src/FuzzySet.cpp src/FuzzySet.h)
