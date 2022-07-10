cmake_minimum_required(VERSION 3.22)
project(NextNeighbor)

message(STATUS "Build app...")

set(CMAKE_C_STANDARD 17)

add_executable(app app.c)

target_link_libraries(app utils::lists)
target_link_libraries(app utils::math)

find_package(OpenMP REQUIRED)
if (OPENMP_FOUND)
    message(STATUS "OpenMP found...")
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()
target_link_libraries(app OpenMP::OpenMP_C)
