#include <gtest/gtest.h>
#include <math.h>
#include <random>

TEST(MathTests, SqrtStressTest) {
    for (int i = 0; i < 9706340; ++i) {
        sqrt(i);
    }
    SUCCEED();
}
