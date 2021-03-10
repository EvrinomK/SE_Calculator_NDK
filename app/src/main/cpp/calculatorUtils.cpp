#include "calculatorUtils.h"

namespace {
    const std::string operators = "+";

    Operators convertString2Operator(char symbol) {
        if (symbol == '+') {
            return Operators::Sum;
        } else if (symbol == '-') {
            return Operators::Minus;
        } else if (symbol == '*') {
            return Operators::Multiplication;
        } else if (symbol == '/') {
            return Operators::Div;
        } else {
            throw std::runtime_error("Cannot parse operator");
        }
    }
}

double calculateImpl(const std::string &expr) {
    double left_value = std::stod(expr);
    size_t index_of_operator = expr.find_first_of(operators);

    if (index_of_operator == std::string::npos) {
        return left_value;
    } else {
        double right_value = std::stod(expr.substr(index_of_operator));
        Operators operation = convertString2Operator(expr[index_of_operator]);
        switch (operation) {
            case Operators::Sum:
                return left_value + right_value;
            default:
                throw std::runtime_error("Unexpected operation");
        }
    }

}