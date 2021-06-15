//
// Created by Admin on 2021/6/15.
//

#ifndef NATIVECALCULATORDEMO_STRING_UTIL_H
#define NATIVECALCULATORDEMO_STRING_UTIL_H

#include <string.h>

/*
 * std::string -> jstring
 *
 */

jstring str2Jstring(JNIEnv* env,const char* str) {
    jclass strClz = env->FindClass("java/lang/String");

    //get String's constructor  String(byte[],String)
    jmethodID strCid = env->GetMethodID(strClz,"<init>","([BLjava/lang/String;)V");

    //init a byte array ,size = str.len;
    jbyteArray bytes = env->NewByteArray(strlen(str));

    //transform *str to byte array
    env->SetByteArrayRegion(bytes,0,strlen(str),(jbyte*)str);

    jstring encoding = env->NewStringUTF("GB2312");

    return (jstring)env->NewObject(strClz,strCid,bytes,encoding);

}

/*
 * jstring -> std::string
 *
 */

std::string jstring2String(JNIEnv* env,jstring jstr) {
    char*   rtn         =   NULL;
    jclass  strClz      =   env->FindClass("java/lang/String");
    jstring strEncode   =   env->NewStringUTF("GB2312");
    jmethodID mid       =   env->GetMethodID(strClz,"getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr     =   (jbyteArray)env->CallObjectMethod(jstr,mid,strEncode);
    jsize  alen         =   env->GetArrayLength(barr);
    jbyte *ba           =   env->GetByteArrayElements(barr,JNI_FALSE);
    if(alen  >  0) {
        //allocate memory space
        rtn     =   (char *)malloc(alen+1);
        memcpy(rtn,ba,alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr,ba,0);
    std::string stringTemp(rtn);
    free(rtn);
    return stringTemp;
}


#endif //NATIVECALCULATORDEMO_STRING_UTIL_H






