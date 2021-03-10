#pragma once
#include <jni.h>
#include <string>

enum Operators {
    Sum,
    Minus,
    Multiplication,
    Div
};

double calculateImpl(const std::string& expr);
