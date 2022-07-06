#include <gtest/gtest.h>
#include "listdouble.h"

TEST(ListDoubleTests, StoreAndGetValue) {
    List* double_list = new_double_list(5);

    const double value1 = 0.1;
    const double value2 = 3.45;
    const double value3 = 9.9995;


    push_double_list(double_list, value1);
    push_double_list(double_list, value2);
    push_double_list(double_list, value3);

    EXPECT_EQ(value1, get_value_from_double_list(double_list, 0));
    EXPECT_EQ(value2, get_value_from_double_list(double_list, 1));
    EXPECT_EQ(value3, get_value_from_double_list(double_list, 2));
}
