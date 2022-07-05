project(NextNeighbor)

enable_testing()

add_executable(
        list_int_tests
        list_int_tests.cpp
)
target_link_libraries(
        list_int_tests
        PRIVATE
        gtest_main
)
target_link_libraries(
        list_int_tests
        PRIVATE
        mlists
)

include(GoogleTest)
gtest_discover_tests(list_int_tests)
