#include <gtest/gtest.h>
#include "calculatorUtils.h"

TEST(sum, pass) {
    ASSERT_EQ(42, sum(40, 2));
}

TEST(sum, fail) {
    printf("Start test");
    ASSERT_EQ(42, sum(42, 1));
}