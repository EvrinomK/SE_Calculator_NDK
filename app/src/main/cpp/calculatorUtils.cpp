#include <vector>
#include "calculatorUtils.h"

namespace {
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

    bool isOperator(char symbol) {
        return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
    }

    bool rightValueIsComplexExpr(const std::vector<std::pair<size_t, Operators>> &operatorsIndexes,
                                 int currentOperIndex) {
        return currentOperIndex + 1 < operatorsIndexes.size() &&
               (operatorsIndexes[currentOperIndex + 1].second == Multiplication ||
                operatorsIndexes[currentOperIndex + 1].second == Div);
    }
}

std::vector<std::pair<size_t, Operators>> parseOperatorsFromExpr(const std::string &expr) {
    std::vector<std::pair<size_t, Operators>> operatorsIndexes = {};

    for (size_t i = 0; i < expr.size(); ++i) {
        try {
            Operators oper = convertString2Operator(expr[i]);
            operatorsIndexes.emplace_back(i, oper);
        } catch (const std::exception &ex) {
            //ignore
        }
    }

    return operatorsIndexes;
}

double calculateImpl(const std::string &expr) {
    const std::vector<std::pair<size_t, Operators>> operatorsIndexes = parseOperatorsFromExpr(expr);
    double result = std::stod(expr);
    for (int i = 0; i < operatorsIndexes.size(); ++i) {

        switch (operatorsIndexes[i].second) {
            case Operators::Sum:
                if (rightValueIsComplexExpr(operatorsIndexes, i)) {
                    return result + calculateImpl(expr.substr(operatorsIndexes[i].first + 1));
                } else {
                    result += std::stod(expr.substr(operatorsIndexes[i].first));
                }

                break;
            case Operators::Minus:
                if (operatorsIndexes[i].first == 0 ||
                    isOperator(expr[operatorsIndexes[i].first - 1])) {
                    //ignore first minus because stod already parsed it
                    continue;
                } else if (rightValueIsComplexExpr(operatorsIndexes, i)) {
                    return result - calculateImpl(expr.substr(operatorsIndexes[i].first + 1));
                } else {
                    result -= std::stod(expr.substr(operatorsIndexes[i].first + 1));
                }
                break;
            case Operators::Multiplication:
                result *= std::stod(expr.substr(operatorsIndexes[i].first + 1));
                break;
            default:
                throw std::runtime_error("Unexpected operation");

        }
    }
    return result;
}