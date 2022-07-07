cmake_minimum_required(VERSION 3.22.3)
project(MLists VERSION 0.0.1 LANGUAGES C)

message(STATUS "Build utils/lists...")

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

add_library(${PROJECT_NAME} ${source_files})
add_library(utils::lists ALIAS ${PROJECT_NAME})

target_include_directories(
        ${PROJECT_NAME}
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/
)
