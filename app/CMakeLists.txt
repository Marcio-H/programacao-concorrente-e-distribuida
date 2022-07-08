cmake_minimum_required(VERSION 3.22)
project(NextNeighbor)

message(STATUS "Build app...")

set(CMAKE_C_STANDARD 17)

add_executable(app app.c)

target_link_libraries(app utils::lists)
target_link_libraries(app utils::math)
