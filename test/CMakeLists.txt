cmake_minimum_required(VERSION 3.10)
project(color-test)

set(CMAKE_CXX_STANDARD 17)

add_executable(test testmain.cpp)
target_link_libraries(test PRIVATE color catch)