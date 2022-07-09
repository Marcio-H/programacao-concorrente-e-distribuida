cmake_minimum_required(VERSION 3.15)
project(MathTests)

message(STATUS "Build math tests...")

enable_testing()

add_executable(
        math_tests
        euclidean_tests.cpp
        math_lib_tests.cpp
)

target_link_libraries(math_tests PRIVATE gtest_main)
target_link_libraries(math_tests PRIVATE utils::lists)
target_link_libraries(math_tests PRIVATE utils::math)

include(GoogleTest)
gtest_discover_tests(math_tests)
