#include <gtest/gtest.h>
#include "calculatorUtils.h"

TEST(calculatorUtils, calculateImpl_returns_numer_for_str_only_with_number) {
    ASSERT_EQ(4, calculateImpl("4"));
}