LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
#注释掉android log,不知道为什么 在 as 中编译不过,adt编译无压力啊!!!1百思不得姐
#LOCAL_LDLIBS   := -lm -llog -landroid
#LOCAL_LDLIBS := -landroid
LOCAL_MODULE    := test
#========================src list===========================
#LOCAL_SRC_FILES := readAssets.cpp
#LOCAL_SRC_FILES := hello-jni.c

SRC_LIST := $(wildcard $(LOCAL_PATH)/src/*.cpp)
LOCAL_SRC_FILES += $(SRC_LIST:$(LOCAL_PATH)/%=%)
#========================src list===========================

include $(BUILD_SHARED_LIBRARY)
