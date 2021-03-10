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