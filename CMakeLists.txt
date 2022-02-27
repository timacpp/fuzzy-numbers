cmake_minimum_required(VERSION 3.20)
project(fuzzy)

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif ()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-std=c++20 -Wall -Wextra")

set_property(GLOBAL PROPERTY RULE_MESSAGES OFF)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)

set(NUM_FILES src/fuzzy_num.cc src/fuzzy_num.h)
set(SET_FILES src/fuzzy_set.h src/fuzzy_set.cc)

add_executable(num_test test/fuzzy_test.cc ${NUM_FILES})
add_executable(example example/fuzzy_example.cc ${NUM_FILES} ${SET_FILES})