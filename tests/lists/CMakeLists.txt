cmake_minimum_required(VERSION 3.15)
project(ListsTests)

message(STATUS "Build lists tests...")

enable_testing()

add_executable(
        list_int_tests
        list_double_tests.cpp
)

target_link_libraries(list_int_tests PRIVATE gtest_main)
target_link_libraries(list_int_tests PRIVATE utils::lists)

include(GoogleTest)
gtest_discover_tests(list_int_tests)
