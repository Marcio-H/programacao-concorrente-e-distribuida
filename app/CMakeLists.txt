cmake_minimum_required(VERSION 3.22)
project(NextNeighbor)

message(STATUS "Build app...")

find_package(OpenMP REQUIRED)

set(CMAKE_C_STANDARD 17)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")

add_executable(app app.c)

target_link_libraries(app utils::lists)
target_link_libraries(app utils::math)
target_link_libraries(app OpenMP::OpenMP_C)

target_compile_definitions(app PRIVATE RESOURCE_OUTPUT_PATH="${RESOURCES_PATH}/output.txt")
