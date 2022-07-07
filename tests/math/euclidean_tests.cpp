#include <gtest/gtest.h>
#include <random>
extern "C" {
    #include "euclidean.h"
    #include "listdouble.h"
}

TEST(EuclideanTests, CalculateDistance) {
    List *l1 = new_double_list(4);
    List *l2 = new_double_list(4);

    push_double_list(l1, 0);
    push_double_list(l1, 1);
    push_double_list(l1, 3);
    push_double_list(l1, 2);
    push_double_list(l2, 3);
    push_double_list(l2, 2);
    push_double_list(l2, 9);
    push_double_list(l2, 1);

    EXPECT_NEAR(6.9, distance(l1, l2), 0.1);
}

TEST(EuclideanTests, CalculateDistanceParallel) {
    List *l1 = new_double_list(100);
    List *l2 = new_double_list(100);

    push_double_list(l1, 0);
    push_double_list(l1, 1);
    push_double_list(l1, 3);
    push_double_list(l1, 2);
    push_double_list(l2, 3);
    push_double_list(l2, 2);
    push_double_list(l2, 9);
    push_double_list(l2, 1);

    EXPECT_NEAR(6.9, distance(l1, l2), 0.1);
}
