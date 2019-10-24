cmake_minimum_required(VERSION 3.10)
project(color)

set(CMAKE_CXX_STANDARD 17)

add_library(color STATIC color.hpp)

set_target_properties(color PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(color PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
