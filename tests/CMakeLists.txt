cmake_minimum_required(VERSION 3.15)
project(Tests)

message(STATUS "Building tests...")

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(CMakePackageConfigHelpers)

add_subdirectory(lists)
add_subdirectory(math)
