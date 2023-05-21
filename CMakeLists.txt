cmake_minimum_required(VERSION 3.25)
project(schiffeversenken)

SET(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

add_executable(schiffeversenken main.cpp schiffeversenken/battlefield.cpp schiffeversenken/ship.cpp schiffeversenken/point.cpp schiffeversenken/point.h)

add_definitions(-DC_LION)
#include_directories("${CMAKE_CURRENT_LIST_DIR}/include")
#include_directories("${CMAKE_CURRENT_LIST_DIR}/src")
include_directories("${CMAKE_CURRENT_LIST_DIR}/schiffeversenken")
