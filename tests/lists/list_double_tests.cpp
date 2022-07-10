#include <gtest/gtest.h>
extern "C" {
    #include "listdouble.h"
}

TEST(ListDoubleTests, StoreAndGetValueTest)
{
    List* double_list = new_double_list(5);
    const double value1 = 0.1;
    const double value2 = 3.45;
    const double value3 = 9.9995;

    push_value_to_double_list(double_list, value1);
    push_value_to_double_list(double_list, value2);
    push_value_to_double_list(double_list, value3);

    EXPECT_EQ(value1, get_value_from_double_list(double_list, 0));
    EXPECT_EQ(value2, get_value_from_double_list(double_list, 1));
    EXPECT_EQ(value3, get_value_from_double_list(double_list, 2));
}

TEST(ListDoubleTests, GetValueStressTest) {
    List* double_list = new_double_list(1);
    const double value1 = 0.1;

    push_value_to_double_list(double_list, value1);
    for (int i = 0; i < 5000; ++i)
    {
        get_value_from_double_list(double_list, 0);
    }
    SUCCEED();
}

TEST(ListDoubleTests, StoreValueStressTest)
{
    List* double_list = new_double_list(1);
    const double value1 = 0.1;

    for (int i = 0; i < 5000; ++i)
    {
        push_value_to_double_list(double_list, value1);
    }
    SUCCEED();
}
