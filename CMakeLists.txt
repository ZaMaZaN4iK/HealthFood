cmake_minimum_required(VERSION 3.6)
project(Cooker)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp Recipe.cpp Recipe.hpp Composition.hpp Ingredient.hpp Reader.cpp Reader.hpp Filter.cpp Filter.hpp)
add_executable(Cooker ${SOURCE_FILES})