#ifndef JNI_LOG_H
#define JNI_LOG_H
#include <android/log>
#define TAG "JULY"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__);
#endif //JNI_LOG_H
