#!/usr/bin/env bash
# Builds and signs the pokox_gles_clear NativeActivity probe APK for
# aarch64-linux-android. Requires Android SDK build-tools, platforms/android-35,
# NDK (r25 tested), a JDK keytool and adb. Run from anywhere; paths are
# MSYS2/Git-Bash style under C:\Android.
set -euo pipefail
SDK=${ANDROID_SDK_ROOT:-/c/Android}
NDK_BIN=$(ls -d "$SDK"/ndk-bundle/toolchains/llvm/prebuilt/*/bin | head -1)
NDK_SRC=$(ls -d "$SDK"/ndk-bundle/sources/android/native_app_glue | head -1)
BT=$(ls -d "$SDK"/build-tools/*/ | sort -V | tail -1)
JAR=$(ls -d "$SDK"/platforms/android-*/android.jar | sort -V | tail -1)
ROOT="$(cd "$(dirname "$0")/../../../.." && pwd)"
WORK=$(mktemp -d)
trap 'rm -rf "$WORK"' EXIT
mkdir -p "$WORK/lib/arm64-v8a"
"$NDK_BIN/aarch64-linux-android30-clang" -O2 -fPIC -c "$NDK_SRC/android_native_app_glue.c" -o "$WORK/glue.o" -I"$NDK_SRC"
"$NDK_BIN/aarch64-linux-android30-clang++" -std=c++2a -O2 -fPIC -shared \
  -I"$ROOT/engine/rhi/include" -I"$NDK_SRC" \
  "$ROOT/engine/rhi/src/device/opengles_native_activity.cpp" \
  "$ROOT/engine/rhi/src/device/opengles_clear_renderer.cpp" \
  "$WORK/glue.o" -o "$WORK/lib/arm64-v8a/libpoko_gles.so" \
  -lEGL -lGLESv3 -llog -landroid
cp "$NDK_BIN/../sysroot/usr/lib/aarch64-linux-android/libc++_shared.so" "$WORK/lib/arm64-v8a/"
"$BT/aapt2" link -o "$WORK/app-unsigned.apk" -I "$JAR" --manifest "$ROOT/engine/rhi/android/gles-clear/AndroidManifest.xml"
"$BT/aapt" add "$WORK/app-unsigned.apk" lib/arm64-v8a/libpoko_gles.so lib/arm64-v8a/libc++_shared.so
"$BT/zipalign" -f 4 "$WORK/app-unsigned.apk" "$WORK/app-aligned.apk"
if [ ! -f "$WORK/debug.keystore" ]; then
  keytool -genkeypair -keystore "$WORK/debug.keystore" -alias androiddebugkey \
    -keyalg RSA -keysize 2048 -validity 10000 -storepass android -keypass android \
    -dname "CN=Android Debug,O=Android,C=US"
fi
"$BT/apksigner" sign --ks "$WORK/debug.keystore" --ks-pass pass:android \
  --key-pass pass:android --out "$WORK/app-signed.apk" "$WORK/app-aligned.apk"
cp "$WORK/app-signed.apk" "$ROOT/engine/rhi/android/gles-clear/pokox_gles_clear.apk"
echo "APK: $ROOT/engine/rhi/android/gles-clear/pokox_gles_clear.apk"
