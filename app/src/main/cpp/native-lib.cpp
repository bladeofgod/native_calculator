#include <jni.h>
#include <string>

#include "string_util.h"
#include "native_calculator.h"
#include "operation_symbol.h"

typedef std::string String;

typedef struct android_context{
    JavaVM      *javaVm;
    JNIEnv      *env;
    jclass      jniHelperClz;
    jobject     jniHelperObj;
    jmethodID   jniHelperCallback;
    jmethodID   jniHelperRefreshTV;

} AppContext;

AppContext appContext;

//first init
extern "C" JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm,void* reserved) {



    appContext.javaVm = vm;

    if((*vm).GetEnv((void**)&appContext.env,JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }

    appContext.jniHelperObj = NULL;

    return JNI_VERSION_1_6;
}


extern "C" {

    Calculator calculator(0.0,0.0);


/*
 * c++ call app's toast
 */
void toastMsgToApp(String message) {

    char* cMsg = new char[256];
    strcpy(cMsg,message.c_str());
    jstring msg = appContext.env->NewStringUTF(cMsg);
    appContext.env->CallVoidMethod(appContext.jniHelperObj,
                                   appContext.jniHelperCallback,
                                   msg);
}

/*
 * refresh main activity's text view
 */

void refreshResultView(String content) {
    jstring msg = appContext.env->NewStringUTF(content.c_str());
    appContext.env->CallVoidMethod(appContext.jniHelperObj,
                                   appContext.jniHelperRefreshTV,
                                   msg);
}


JNIEXPORT jstring JNICALL
Java_com_bedrock_nativecalculatordemo_JniHelper_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}




/*
 * native init
 * get jniHelper clz/obj/callback
 *
 */

JNIEXPORT void JNICALL
Java_com_bedrock_nativecalculatordemo_JniHelper_nativeInit(
        JNIEnv* env,
        jobject instance) {
    jclass clz                      = (*env).GetObjectClass(instance);
    appContext.jniHelperClz         = (jclass) (*env).NewGlobalRef(clz);
    appContext.jniHelperObj         = (*env).NewGlobalRef(instance);
    appContext.jniHelperCallback    = env->GetMethodID(clz,"toastMsg","(Ljava/lang/String;)V");
    appContext.jniHelperRefreshTV   = env->GetMethodID(clz,"refreshResultView"
                                                       ,"(Ljava/lang/String;)V");
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
    //kind rough...
    char* cPtr = new char[128];
    strcpy(cPtr,jstring2String(env,c).c_str());
    calculator.inputExpression(cPtr);

    refreshResultView(calculator.getExpressionStr());
}

// do calculate
JNIEXPORT jdouble JNICALL
Java_com_bedrock_nativecalculatordemo_JniHelper_nativeCalculate(
        JNIEnv* env,
        jobject /* this */) {

    double result;

    try {
        result = calculator.doCalculate();
    } catch (CalculateException exception) {
        toastMsgToApp(exception.msg);
    }

    return result;
}



//add
JNIEXPORT void JNICALL
Java_com_bedrock_nativecalculatordemo_JniHelper_add(
        JNIEnv* env,
        jobject /* this */) {

    if(calculator.checkOperationExist()) {
        //already has operation symbol
        toastMsgToApp("already has operation symbol");
    } else {
        calculator.setOperationSymbol(OperationSymbol::ADD);
        refreshResultView(calculator.getExpressionStr());
    }

}

//reduce
JNIEXPORT void JNICALL
Java_com_bedrock_nativecalculatordemo_JniHelper_reduce(
        JNIEnv* env,
        jobject /* this */) {
    if(calculator.checkOperationExist()) {
        //already has operation symbol
        toastMsgToApp("already has operation symbol");
    } else {
        calculator.setOperationSymbol(OperationSymbol::REDUCE);
        refreshResultView(calculator.getExpressionStr());
    }

}

//multiply
JNIEXPORT void JNICALL
Java_com_bedrock_nativecalculatordemo_JniHelper_multiply(
        JNIEnv* env,
        jobject /* this */) {
    if(calculator.checkOperationExist()) {
        //already has operation symbol
        toastMsgToApp("already has operation symbol");
    } else {
        calculator.setOperationSymbol(OperationSymbol::MULTIPLY);
        refreshResultView(calculator.getExpressionStr());
    }

}

//divide
JNIEXPORT void JNICALL
Java_com_bedrock_nativecalculatordemo_JniHelper_divide(
        JNIEnv* env,
        jobject /* this */) {
    if(calculator.checkOperationExist()) {
        //already has operation symbol
        toastMsgToApp("already has operation symbol");
    } else {
        calculator.setOperationSymbol(OperationSymbol::DIVIDE);
        refreshResultView(calculator.getExpressionStr());
    }

}









}