cmake_minimum_required(VERSION 3.22)
project(NextNeighbor)

message(STATUS "Build app...")

set(CMAKE_C_STANDARD 17)

add_executable(src app.c)
