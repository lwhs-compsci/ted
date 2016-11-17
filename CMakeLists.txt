cmake_minimum_required(VERSION 2.8)

project(ted)

include_directories(inc/)
file(GLOB SOURCES src/*.cpp inc/*/*.h)
add_executable(ted ${SOURCES})
