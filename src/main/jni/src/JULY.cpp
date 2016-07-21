#include <jni.h>
#include <string.h>
#include <stdio.h>
#include "../header/Common.h"
//#include "../header/alog.h"

extern "C" void hello(JNIEnv *env, jobject thiiz);
extern "C" jstring obtainString(JNIEnv *env, jobject thiz);
JNINativeMethod mthd[] = {
        {"hey",       "()V",                  (void *) hello},
        {"obtainStr", "()Ljava/lang/String;", (void *) obtainString}
};

void hello(JNIEnv *env, jobject thiiz) {
 // LOGE("what=%s", "jni demo invoking.......................");
}

jstring obtainString(JNIEnv *env, jobject thiz) {
    return env->NewStringUTF("hey!!!,我来之c/c++的世界,你好java世界!----");
}

int registerNative(JNIEnv *env) {
    jclass clazz;
    clazz = env->FindClass(javaClassName);
    if (clazz == NULL) {
        return JNI_FALSE;
    }
    if (env->RegisterNatives(clazz, mthd, sizeof(mthd) / sizeof(mthd[0])) < 0) {
        return JNI_FALSE;
    }
    return JNI_TRUE;
}

jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    jint result = JNI_ERR;
    JNIEnv *env = NULL;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_4) != JNI_OK) {
        return result;
    }
    if (!registerNative(env)) {
        return result;
    }
    result = JNI_VERSION_1_4;
    return result;
}