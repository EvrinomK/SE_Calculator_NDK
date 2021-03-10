#include <gtest/gtest.h>
#include "calculatorUtils.h"

TEST(calculatorUtils, calculateImpl_returns_int_for_str_only_with_int) {
    ASSERT_EQ(4, calculateImpl("4"));
}

TEST(calculatorUtils, calculateImpl_returns_double_for_str_only_with_double) {
    ASSERT_EQ(4.02, calculateImpl("4.02"));
}

TEST(calculatorUtils, calculateImpl_returns_negative_number_for_str_only_with_negative_number) {
    ASSERT_EQ(-4, calculateImpl("-4"));
}

TEST(calculatorUtils, calculateImpl_returns_ambigous_number) {
    ASSERT_EQ(4827, calculateImpl("4827"));
}

TEST(calculatorUtils, calculateImpl_returns_sum_natural_numbers) {
    ASSERT_EQ(5, calculateImpl("2+3"));
}

TEST(calculatorUtils, calculateImpl_returns_sum_double_numbers) {
    ASSERT_EQ(5.5, calculateImpl("2.3+3.2"));
}

TEST(calculatorUtils, calculateImpl_returns_diff_numbers_when_left_value_more_then_right) {
    ASSERT_DOUBLE_EQ(1.2, calculateImpl("5.5-4.3"));
}