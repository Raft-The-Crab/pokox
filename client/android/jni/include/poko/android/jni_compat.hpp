#pragma once

#if defined(__has_include) && __has_include(<jni.h>)
#include <jni.h>
#else
#include <cstdint>

struct JNIEnv;
using jclass = void*;
using jobject = void*;
using jboolean = std::uint8_t;
using jint = std::int32_t;
using jlong = std::int64_t;
using jbyte = std::int8_t;
using jfloat = float;
using jdouble = double;
struct _jbyteArray;
using jbyteArray = _jbyteArray*;
inline constexpr jboolean JNI_FALSE = 0;
inline constexpr jboolean JNI_TRUE = 1;
#define JNIEXPORT
#define JNICALL
#endif
