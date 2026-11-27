package com.poko.client

import android.os.Bundle
import android.util.Log
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent

/**
 * SHL-15/16/17: Main Android client Activity owning the opaque JNI engine
 * handle, Jetpack Compose chrome over the embedded game surface, and
 * pause/resume/destroy lifecycle mapping.
 */
class PokoActivity : ComponentActivity() {
    var nativeHandle: Long = 0L
        private set

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        val metrics = resources.displayMetrics
        val width = metrics.widthPixels.coerceAtLeast(1)
        val height = metrics.heightPixels.coerceAtLeast(1)
        val config = PokoNativeBridge.encodeConfig(width, height, metrics.density)
        nativeHandle = PokoNativeBridge.nativeCreate(config)
        check(nativeHandle != 0L && PokoNativeBridge.nativeIsValidHandle(nativeHandle)) {
            "Failed to create native Poko handle: error=${PokoNativeBridge.nativeLastError()}"
        }
        Log.i("PokoX", "onCreate handle=0x${nativeHandle.toString(16)}")
        setContent {
            PokoShellScreen(nativeHandle = nativeHandle)
        }
    }

    override fun onPause() {
        if (nativeHandle != 0L) {
            PokoNativeBridge.nativePause(nativeHandle)
            Log.i("PokoX", "onPause paused=${PokoNativeBridge.nativeIsPaused(nativeHandle)}")
        }
        super.onPause()
    }

    override fun onResume() {
        super.onResume()
        if (nativeHandle != 0L) {
            PokoNativeBridge.nativeResume(nativeHandle)
            Log.i("PokoX", "onResume paused=${PokoNativeBridge.nativeIsPaused(nativeHandle)}")
        }
    }

    override fun onDestroy() {
        if (nativeHandle != 0L) {
            Log.i("PokoX", "onDestroy handle=0x${nativeHandle.toString(16)}")
            PokoNativeBridge.nativeDestroy(nativeHandle)
            nativeHandle = 0L
        }
        super.onDestroy()
    }
}
