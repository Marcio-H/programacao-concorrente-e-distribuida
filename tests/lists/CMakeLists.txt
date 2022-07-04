enable_testing()

add_executable(
        list_int_tests
        list_int_tests.cpp
)
target_link_libraries(
        list_int_tests
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(list_int_tests)
