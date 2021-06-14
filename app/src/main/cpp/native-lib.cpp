#include <jni.h>
#include <string>

#include "native_calculator.h"

typedef struct android_context{
    JavaVM      *javaVm;
    jclass      jniHelperClz;
    jobject     jniHelperObj;
} AppContext;

AppContext appContext;

//first init
extern "C" JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm,void* reserved) {

    JNIEnv* env;

    appContext.javaVm = vm;

    if((*vm).GetEnv((void**)&env,JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }

    appContext.jniHelperObj = NULL;

    return JNI_VERSION_1_6;
}


extern "C" {

    Calculator calculator(0,0);


JNIEXPORT jstring JNICALL
Java_com_bedrock_nativecalculatordemo_JniHelper_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

//reset calculator
JNIEXPORT void JNICALL
Java_com_bedrock_nativecalculatordemo_JniHelper_resetCalculator(
        JNIEnv* env,
        jobject /* this */) {

    calculator.resetStatus();
}

//input char
JNIEXPORT void JNICALL
Java_com_bedrock_nativecalculatordemo_JniHelper_inputChar(
        JNIEnv* env,
        jobject /* this */,
        jstring c) {

    jdouble result = 0.0;
}

// do calculate
JNIEXPORT jdouble JNICALL
Java_com_bedrock_nativecalculatordemo_JniHelper_nativeCalculate(
        JNIEnv* env,
        jobject /* this */) {

    jdouble result = 0.0;
    return result;
}



//add
JNIEXPORT void JNICALL
Java_com_bedrock_nativecalculatordemo_JniHelper_add(
        JNIEnv* env,
        jobject /* this */) {

    jdouble result = 0.0;

}

//reduce
JNIEXPORT void JNICALL
Java_com_bedrock_nativecalculatordemo_JniHelper_reduce(
        JNIEnv* env,
        jobject /* this */) {
    jdouble result = 0.0;

}

//multiply
JNIEXPORT void JNICALL
Java_com_bedrock_nativecalculatordemo_JniHelper_multiply(
        JNIEnv* env,
        jobject /* this */) {
    jdouble result = 0.0;

}

//divide
JNIEXPORT void JNICALL
Java_com_bedrock_nativecalculatordemo_JniHelper_divide(
        JNIEnv* env,
        jobject /* this */) {
    jdouble result = 0.0;

}









}