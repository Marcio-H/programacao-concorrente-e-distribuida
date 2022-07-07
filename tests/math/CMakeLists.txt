cmake_minimum_required(VERSION 3.15)
project(MathTests)

message(STATUS "Build math tests...")

enable_testing()

find_package(OpenMP REQUIRED)
if (OPENMP_FOUND)
    message("OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif ()

add_executable(
        euclidean_tests
        euclidean_tests.cpp
)

target_link_libraries(euclidean_tests PRIVATE gtest_main)
target_link_libraries(euclidean_tests PRIVATE utils::lists)
target_link_libraries(euclidean_tests PRIVATE utils::math)

include(GoogleTest)
gtest_discover_tests(euclidean_tests)
