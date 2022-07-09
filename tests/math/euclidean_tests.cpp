#include <gtest/gtest.h>
#include <random>
extern "C" {
    #include "euclidean.h"
    #include "listdouble.h"
}

TEST(EuclideanTests, CalculateDistanceTest) {
    List *l1 = new_double_list(4);
    List *l2 = new_double_list(4);

    push_value_to_double_list(l1, 0);
    push_value_to_double_list(l1, 1);
    push_value_to_double_list(l1, 3);
    push_value_to_double_list(l1, 2);
    push_value_to_double_list(l2, 3);
    push_value_to_double_list(l2, 2);
    push_value_to_double_list(l2, 9);
    push_value_to_double_list(l2, 1);

    EXPECT_NEAR(6.9, distance(l1, l2), 0.1);
}

TEST(EuclideanTests, CalculateDistanceParallelTest) {
    List *l1 = new_double_list(100);
    List *l2 = new_double_list(100);

    push_value_to_double_list(l1, 0);
    push_value_to_double_list(l1, 1);
    push_value_to_double_list(l1, 3);
    push_value_to_double_list(l1, 2);
    push_value_to_double_list(l2, 3);
    push_value_to_double_list(l2, 2);
    push_value_to_double_list(l2, 9);
    push_value_to_double_list(l2, 1);

    EXPECT_NEAR(6.9, distance_parallel(l1, l2), 0.1);
}

TEST(EuclideanTests, DistanceStressTest) {
    List *l1 = new_double_list(100);
    List *l2 = new_double_list(100);

    push_value_to_double_list(l1, 0);
    push_value_to_double_list(l1, 1);
    push_value_to_double_list(l1, 3);
    push_value_to_double_list(l1, 2);
    push_value_to_double_list(l2, 3);
    push_value_to_double_list(l2, 2);
    push_value_to_double_list(l2, 9);
    push_value_to_double_list(l2, 1);
    for (int i = 0; i < 9706340; ++i) {
        distance(l1, l2);
    }
    SUCCEED();
}
