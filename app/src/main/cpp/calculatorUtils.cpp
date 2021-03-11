#include <vector>
#include "calculatorUtils.h"

namespace {
    Operators convertString2Operator(char symbol) {
        switch (symbol) {
            case '+':
                return Operators::Sum;
            case '-':
                return Operators::Minus;
            case '*':
                return Operators::Multiplication;
            case '/':
                return Operators::Div;
            default:
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

    bool isUnarMinus(const std::vector<std::pair<size_t, Operators>> &operatorsIndexes,
                     int currentOperIndex) {
        return operatorsIndexes[currentOperIndex].second == Minus &&
               (operatorsIndexes[currentOperIndex].first == 0 ||
                operatorsIndexes[currentOperIndex - 1].first ==
                operatorsIndexes[currentOperIndex].first - 1);
    }

    int findIndexNextLessPriorityOperator(
            const std::vector<std::pair<size_t, Operators>> &operatorsIndexes,
            int currentOperIndex) {
        for (int i = currentOperIndex + 1; i < operatorsIndexes.size(); ++i) {
            if (operatorsIndexes[i].second == Sum ||
                (operatorsIndexes[i].second == Minus && !isUnarMinus(operatorsIndexes, i))) {
                return i;
            }
        }

        return currentOperIndex;
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
                    int nextLessOpIndex = findIndexNextLessPriorityOperator(operatorsIndexes, i);
                    if (nextLessOpIndex == i) {
                        return result + calculateImpl(expr.substr(operatorsIndexes[i].first + 1));
                    } else {
                        result += calculateImpl(expr.substr(operatorsIndexes[i].first + 1,
                                                            operatorsIndexes[nextLessOpIndex].first - operatorsIndexes[i].first - 1));
                        i = nextLessOpIndex - 1;
                    }
                } else {
                    result += std::stod(expr.substr(operatorsIndexes[i].first));
                }

                break;
            case Operators::Minus:
                if (operatorsIndexes[i].first == 0 ||
                    operatorsIndexes[i - 1].first == operatorsIndexes[i].first - 1) {
                    //ignore first minus because stod already parsed it
                    continue;
                } else if (rightValueIsComplexExpr(operatorsIndexes, i)) {
                    int nextLessOpIndex = findIndexNextLessPriorityOperator(operatorsIndexes, i);
                    if (nextLessOpIndex == i) {
                        return result - calculateImpl(expr.substr(operatorsIndexes[i].first + 1));
                    } else {
                        std::string complexExpr = expr.substr(operatorsIndexes[i].first + 1,
                                                              operatorsIndexes[nextLessOpIndex].first - operatorsIndexes[i].first - 1);
                        result -= calculateImpl(complexExpr);
                        i = nextLessOpIndex - 1;
                    }
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