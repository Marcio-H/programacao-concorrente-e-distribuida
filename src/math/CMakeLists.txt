cmake_minimum_required(VERSION 3.22.3)
project(Math VERSION 0.0.1 LANGUAGES C)

message(STATUS "Build utils/math...")

file(
        GLOB
        source_files
        "${PROJECT_SOURCE_DIR}/*.c"
)

file(
        GLOB
        headers_files
        "${PROJECT_SOURCE_DIR}/include/*.h"
)

set(CMAKE_C_STANDARD 99)
find_package(OpenMP REQUIRED)
if (OPENMP_FOUND)
    message("OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif ()

add_library(${PROJECT_NAME} ${source_files})
add_library(utils::math ALIAS ${PROJECT_NAME})

target_include_directories(
        ${PROJECT_NAME}
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/
)

target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE utils::lists
)
