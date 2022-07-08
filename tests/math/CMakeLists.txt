cmake_minimum_required(VERSION 3.15)
project(MathTests)

message(STATUS "Build math tests...")

enable_testing()

add_executable(
        euclidean_tests
        euclidean_tests.cpp
)

target_link_libraries(euclidean_tests PRIVATE gtest_main)
target_link_libraries(euclidean_tests PRIVATE utils::lists)
target_link_libraries(euclidean_tests PRIVATE utils::math)

include(GoogleTest)
gtest_discover_tests(euclidean_tests)
