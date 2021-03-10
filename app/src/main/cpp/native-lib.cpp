#include <jni.h>
#include <string>
#include "calculatorUtils.h"

namespace {
    std::string jstring2string(JNIEnv *env, jstring jStr) {
        if (!jStr)
            return "";

        const jclass stringClass = env->GetObjectClass(jStr);
        const jmethodID getBytes = env->GetMethodID(stringClass, "getBytes", "(Ljava/lang/String;)[B");
        const jbyteArray stringJbytes = (jbyteArray) env->CallObjectMethod(jStr, getBytes, env->NewStringUTF("UTF-8"));

        size_t length = (size_t) env->GetArrayLength(stringJbytes);
        jbyte* pBytes = env->GetByteArrayElements(stringJbytes, NULL);

        std::string ret = std::string((char *)pBytes, length);
        env->ReleaseByteArrayElements(stringJbytes, pBytes, JNI_ABORT);

        env->DeleteLocalRef(stringJbytes);
        env->DeleteLocalRef(stringClass);
        return ret;
    }
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_se_1calculator_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_example_se_1calculator_MainActivity_claclulate(JNIEnv *env, jobject thiz,
                                                        jstring expression) {
    std::string expr = jstring2string(env, expression);
    return calculateImpl(expr);
}

