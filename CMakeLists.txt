cmake_minimum_required(VERSION 3.15)
project(NextNeighbor)

add_subdirectory(src)

option(RUN_TESTS "Running tests..." OFF)

IF(!RUN_TESTS)
    add_subdirectory(app)
ELSE()
    message(STATUS "Building tests")
    add_subdirectory(tests)
ENDIF()
