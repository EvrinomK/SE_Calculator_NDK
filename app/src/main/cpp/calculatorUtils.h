#pragma once
#include <jni.h>
#include <string>

enum Operators {
    Sum,
    Diff,
    Mult,
    Div
};

double calculateImpl(const std::string& expr);
