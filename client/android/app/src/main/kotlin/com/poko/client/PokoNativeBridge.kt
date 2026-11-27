package com.poko.client

import android.view.Surface
import java.nio.ByteBuffer
import java.nio.ByteOrder

interface PokoHost {
    fun onStateChanged(state: Int)
    fun onError(code: Int, message: String)
    fun onReplayReady(replayId: Long)
}

object PokoNativeBridge {
    const val ABI_VERSION: Int = 1

    init {
        System.loadLibrary("poko_client")
    }

    fun encodeConfig(width: Int, height: Int, dpiScale: Float): ByteArray {
        return ByteBuffer.allocate(16)
            .order(ByteOrder.LITTLE_ENDIAN)
            .putInt(ABI_VERSION)
            .putInt(width)
            .putInt(height)
            .putFloat(dpiScale)
            .array()
    }

    external fun nativeCreate(configBytes: ByteArray): Long
    external fun nativeLastError(): Int
    external fun nativeDestroy(handle: Long)
    external fun nativeIsValidHandle(handle: Long): Boolean
    external fun nativeSetSurface(handle: Long, surface: Surface?): Int
    external fun nativeFrame(handle: Long, dt: Double): Int
    external fun nativeInput(
        handle: Long,
        kind: Int,
        x: Float,
        y: Float,
        buttonOrKey: Int,
        pressed: Int,
    ): Int
    external fun nativeFrameCount(handle: Long): Long
    external fun nativeInputCount(handle: Long): Long
    external fun nativePause(handle: Long): Int
    external fun nativeResume(handle: Long): Int
    external fun nativeIsPaused(handle: Long): Boolean
}
