#include <jni.h>
#include "Triangle.h"
#include <string>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedLocalVariable"
#pragma ide diagnostic ignored "UnusedGlobalDeclarationInspection"
using namespace std;

extern "C" JNIEXPORT jdouble JNICALL
Java_com_norman_trycpp_NativeMethods_square(
        JNIEnv *env,
        jclass clazz,
        jdouble base) {
    return base * base;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_norman_trycpp_NativeMethods_toLowerCase(
        JNIEnv *env,
        jclass clazz,
        jstring s) {
    char *c = const_cast<char *>(env->GetStringUTFChars(s, nullptr));
    char *start = c;

    while (*c != '\0') {
        if (*c <= 'Z' && *c >= 'A')
            (*c) += 'z' - 'Z';
        c++;
    }

    return env->NewStringUTF(start);
}

extern "C" JNIEXPORT jdouble JNICALL
Java_com_norman_trycpp_NativeMethods_triangleArea(
        JNIEnv *env,
        jclass clazz,
        jdoubleArray array) {
    double *c = env->GetDoubleArrayElements(array, nullptr);
    Triangle triangle = Triangle::of(c);
    return triangle.area();
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_norman_trycpp_NativeMethods_getDistance(JNIEnv *env, jclass clazz, jobject a, jobject b) {
    _jmethodID *methodID = env->GetStaticMethodID(env->GetObjectClass(a), "getDistance",
                                                  "(Lcom/norman/trycpp/Point;Lcom/norman/trycpp/Point;)D");
    auto *args = new jvalue[2];
    args[0].l = a;
    args[1].l = b;
    jdouble ret = env->CallStaticDoubleMethodA(env->GetObjectClass(a), methodID, args);
    delete[] args;
    return ret;
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_norman_trycpp_NativeMethods_getAverage(JNIEnv *env, jclass clazz, jdoubleArray nums) {
    int length = env->GetArrayLength(nums);
    auto *p = env->GetDoubleArrayElements(nums, nullptr);
    double sum = 0;
    for (int i = 0; i < length; ++i)sum += p[i];
    return sum / length;
}

#pragma clang diagnostic pop