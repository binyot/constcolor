cmake_minimum_required(VERSION 3.10)
project(catch)

set(CMAKE_CXX_STANDARD 17)

add_library(catch INTERFACE)
target_include_directories(catch INTERFACE include/)