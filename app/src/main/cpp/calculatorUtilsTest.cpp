#include <gtest/gtest.h>
#include "calculatorUtils.h"

TEST(calculatorUtils, calculateImpl_returns_int_for_str_only_with_int) {
    ASSERT_EQ(4, calculateImpl("4"));
}

TEST(calculatorUtils, calculateImpl_returns_double_for_str_only_with_double) {
    ASSERT_DOUBLE_EQ(4.02, calculateImpl("4.02"));
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
    ASSERT_DOUBLE_EQ(5.5, calculateImpl("2.3+3.2"));
}

TEST(calculatorUtils, calculateImpl_returns_diff_numbers_when_left_value_more_then_right) {
    ASSERT_DOUBLE_EQ(1.2, calculateImpl("5.5-4.3"));
}

TEST(calculatorUtils, calculateImpl_returns_diff_numbers_when_left_value_less_then_right) {
    ASSERT_DOUBLE_EQ(-1.2, calculateImpl("4.3-5.5"));
}

TEST(calculatorUtils, calculateImpl_returns_diff_numbers_when_left_number_is_negative) {
    ASSERT_DOUBLE_EQ(-9.8, calculateImpl("-4.3-5.5"));
}

TEST(calculatorUtils, calculateImpl_returns_sum_of_few_numbers) {
    ASSERT_DOUBLE_EQ(9, calculateImpl("2+3+4"));
}

TEST(calculatorUtils, calculateImpl_returns_sum_and_diff_numbers) {
    ASSERT_DOUBLE_EQ(1, calculateImpl("2+3-4"));
}

TEST(calculatorUtils,
     calculateImpl_returns_valid_number_for_complex_epression_with_first_negative_number) {
    ASSERT_DOUBLE_EQ(4, calculateImpl("-2+3+4-1"));
}

TEST(calculatorUtils, calculateImpl_returns_multiple_possitive_numbers) {
    ASSERT_DOUBLE_EQ(6, calculateImpl("2*3"));
}

TEST(calculatorUtils, calculateImpl_returns_multiple_few_possitive_numbers) {
    ASSERT_DOUBLE_EQ(24, calculateImpl("2*3*4"));
}

TEST(calculatorUtils, calculateImpl_returns_multiple_with_negative_number) {
    ASSERT_DOUBLE_EQ(-24, calculateImpl("2*-3*4"));
}

TEST(calculatorUtils, calculateImpl_returns_result_of_complex_expr_with_sum_and_mult) {
    ASSERT_DOUBLE_EQ(14, calculateImpl("2+3*4"));
}

TEST(calculatorUtils, calculateImpl_returns_result_of_complex_expr_with_diff_and_mult) {
    ASSERT_DOUBLE_EQ(10, calculateImpl("22-3*4"));
}

TEST(calculatorUtils,
     calculateImpl_returns_result_of_complex_expr_with_diff_and_mult_negative_numbers) {
    ASSERT_DOUBLE_EQ(-2, calculateImpl("22-3*-4*-2"));
}

TEST(calculatorUtils, calculateImpl_returns_result_of_complex_expr_with_few_operations) {
    ASSERT_DOUBLE_EQ(17, calculateImpl("22-3*-4*-2+23-2*2"));
}

TEST(calculatorUtils, calculateImpl_returns_div_numbers) {
    ASSERT_DOUBLE_EQ(2, calculateImpl("4/2"));
}

TEST(calculatorUtils, calculateImpl_returns_div_negative_numbers) {
    ASSERT_DOUBLE_EQ(2, calculateImpl("-4/-2"));
}

TEST(calculatorUtils, calculateImpl_returns_result_of_complex_expr_sum_div_negative) {
    ASSERT_DOUBLE_EQ(1, calculateImpl("3+4/-2"));
}

TEST(calculatorUtils, calculateImpl_returns_result_of_complex_expr_diff_div) {
    ASSERT_DOUBLE_EQ(1, calculateImpl("3-12/6"));
}

TEST(calculatorUtils, calculateImpl_returns_result_of_complex_expr_mult_div) {
    ASSERT_DOUBLE_EQ(2, calculateImpl("3*4/6"));
}

TEST(calculatorUtils, calculateImpl_returns_result_of_complex_expr_div_mult) {
    ASSERT_DOUBLE_EQ(6, calculateImpl("12/6*3"));
}

TEST(calculatorUtils, calculateImpl_returns_result_of_complex_expr_div_sum_div) {
    ASSERT_DOUBLE_EQ(5, calculateImpl("12/6+3/1"));
}

TEST(calculatorUtils, calculateImpl_returns_result_of_complex_expr_div_diff_div) {
    ASSERT_DOUBLE_EQ(-1, calculateImpl("12/6-3/1"));
}

TEST(calculatorUtils, calculateImpl_returns_result_of_complex_expr_div_div_div) {
    ASSERT_DOUBLE_EQ(5, calculateImpl("100/5/4"));
}

TEST(calculatorUtils, calculateImpl_returns_result_of_classic) {
    ASSERT_DOUBLE_EQ(6, calculateImpl("2+2*2"));
}

TEST(calculatorUtils, calculateImpl_fail_of_div_null) {
    ASSERT_ANY_THROW(calculateImpl("2/0"));
}