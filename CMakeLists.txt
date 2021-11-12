cmake_minimum_required(VERSION 3.20)
project(fuzzy)

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif ()

set(CMAKE_CXX_STANDARD 20)

set_property(GLOBAL PROPERTY RULE_MESSAGES OFF)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_C_FLAGS "-std=c11 -Wall -Wextra")
add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)

set(RELEASE_FILES src/main.cpp src/fuzzy_num.cc src/fuzzy_num.h src/fuzzy_set.cc src/fuzzy_set.h)
set(TEST_FILES test/num_test.cpp src/fuzzy_num.cc src/fuzzy_num.h)

add_executable(fuzzy ${RELEASE_FILES})
add_executable(test ${TEST_FILES})

set_target_properties(test PROPERTIES OUTPUT_NAME fuzzy_test)