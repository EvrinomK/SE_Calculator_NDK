cmake_minimum_required(VERSION 3.6.0)

project(se_calculator LANGUAGES CXX)

add_library(app
        SHARED
        src/main/cpp/native-lib.cpp
        src/main/cpp/calculatorUtils.cpp
        )

add_library(nativehelper
        INTERFACE
        )

target_include_directories(nativehelper
        INTERFACE
        src/main/cpp
        )

set(GTEST_PATH ${ANDROID_NDK}/sources/third_party/googletest)

add_library(gtest
        STATIC
        ${GTEST_PATH}/src/gtest-all.cc
        )

target_include_directories(gtest
        PRIVATE
        ${GTEST_PATH}
        PUBLIC
        ${GTEST_PATH}/include
        )

add_library(gtest_wrapper
        STATIC
        src/main/cpp/gtest_wrapper.cpp
        )

target_link_libraries(gtest_wrapper
        PRIVATE
        gtest
        nativehelper
        PUBLIC
        -uJava_com_example_se_1calculator_GtestRunner_nInitialize
        -uJava_com_example_se_1calculator_GtestRunner_nRun
        )

add_library(se_calculator_test
        SHARED
        src/main/cpp/calculatorUtilsTest.cpp
        )

target_link_libraries(se_calculator_test
        PRIVATE
        app
        gtest
        gtest_wrapper
        )