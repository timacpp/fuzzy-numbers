cmake_minimum_required(VERSION 3.20)
project(fuzzy)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_FLAGS "-std=c++2a -Wall -Wextra")

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif ()

set_property(GLOBAL PROPERTY RULE_MESSAGES OFF)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)

set(SOURCE_FILES src/fuzzy_num.cc src/fuzzy_num.h src/fuzzy_set.cc src/fuzzy_set.h)

add_executable(fuzzy src/main.cpp ${SOURCE_FILES} test/set_test.cpp)
add_executable(num_test test/num_test.cpp src/fuzzy_num.cc src/fuzzy_num.h)
add_executable(set_test test/set_test.cpp src/fuzzy_set.cc src/fuzzy_set.h)