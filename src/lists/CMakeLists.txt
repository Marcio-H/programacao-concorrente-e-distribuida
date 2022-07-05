project(NextNeighbor)

add_subdirectory(include)

add_library(mlists listint.c liststr.c)

target_include_directories(
        mlists
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
