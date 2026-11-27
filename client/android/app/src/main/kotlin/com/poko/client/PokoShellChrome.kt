package com.poko.client

import android.view.MotionEvent
import android.view.SurfaceHolder
import android.view.SurfaceView
import androidx.compose.foundation.background
import androidx.compose.foundation.border
import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.width
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.LaunchedEffect
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableIntStateOf
import androidx.compose.runtime.mutableLongStateOf
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.runtime.withFrameNanos
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.compose.ui.viewinterop.AndroidView

/**
 * SHL-16: Jetpack Compose chrome layered over the embedded SDL3/GLES game surface.
 */
@Composable
fun PokoShellScreen(nativeHandle: Long) {
    var selectedTab by remember { mutableIntStateOf(0) }
    var classicTheme by remember { mutableStateOf(true) }
    var frameCount by remember { mutableLongStateOf(0L) }
    var inputCount by remember { mutableLongStateOf(0L) }
    val tabs = listOf("Library", "Store", "Social")

    val chromeBg = if (classicTheme) Color(0xFFECE9D8) else Color(0xFF1E2024)
    val chromeText = if (classicTheme) Color(0xFF121214) else Color(0xFFF0F2F5)
    val borderDark = if (classicTheme) Color(0xFF808078) else Color(0xFF484C56)
    val accent = if (classicTheme) Color(0xFF316AC5) else Color(0xFF4C8EF5)

    LaunchedEffect(nativeHandle) {
        var lastNanos = 0L
        while (nativeHandle != 0L) {
            withFrameNanos { nanos ->
                val dt = if (lastNanos == 0L) 0.016 else (nanos - lastNanos) / 1_000_000_000.0
                lastNanos = nanos
                PokoNativeBridge.nativeFrame(nativeHandle, dt)
                frameCount = PokoNativeBridge.nativeFrameCount(nativeHandle)
                inputCount = PokoNativeBridge.nativeInputCount(nativeHandle)
            }
        }
    }

    Box(modifier = Modifier.fillMaxSize()) {
        // Bottom layer: embedded native game surface.
        AndroidView(
            modifier = Modifier.fillMaxSize(),
            factory = { ctx ->
                SurfaceView(ctx).apply {
                    holder.addCallback(object : SurfaceHolder.Callback {
                        override fun surfaceCreated(holder: SurfaceHolder) {
                            PokoNativeBridge.nativeSetSurface(nativeHandle, holder.surface)
                        }

                        override fun surfaceChanged(
                            holder: SurfaceHolder,
                            format: Int,
                            width: Int,
                            height: Int,
                        ) {
                            PokoNativeBridge.nativeSetSurface(nativeHandle, holder.surface)
                        }

                        override fun surfaceDestroyed(holder: SurfaceHolder) {
                            PokoNativeBridge.nativeSetSurface(nativeHandle, null)
                        }
                    })
                    setOnTouchListener { _, ev ->
                        val pressed = if (ev.actionMasked == MotionEvent.ACTION_UP) 0 else 1
                        PokoNativeBridge.nativeInput(
                            nativeHandle,
                            ev.actionMasked,
                            ev.x,
                            ev.y,
                            0,
                            pressed,
                        )
                        true
                    }
                }
            },
        )

        // Top layer: Jetpack Compose shell chrome.
        Column(
            modifier = Modifier
                .fillMaxSize()
                .padding(top = 36.dp, start = 12.dp, end = 12.dp, bottom = 16.dp),
            verticalArrangement = Arrangement.SpaceBetween,
        ) {
            Row(
                modifier = Modifier
                    .fillMaxWidth()
                    .background(chromeBg)
                    .border(1.dp, borderDark)
                    .padding(8.dp),
                verticalAlignment = Alignment.CenterVertically,
            ) {
                Text(
                    text = "PokoX",
                    color = chromeText,
                    fontSize = 16.sp,
                    fontWeight = FontWeight.Bold,
                )
                Spacer(modifier = Modifier.width(12.dp))
                tabs.forEachIndexed { idx, title ->
                    val active = idx == selectedTab
                    Box(
                        modifier = Modifier
                            .padding(end = 6.dp)
                            .border(1.dp, if (active) accent else borderDark)
                            .background(if (active) accent else chromeBg)
                            .clickable { selectedTab = idx }
                            .padding(horizontal = 10.dp, vertical = 6.dp),
                    ) {
                        Text(
                            text = title,
                            color = if (active) Color.White else chromeText,
                            fontSize = 13.sp,
                        )
                    }
                }
                Spacer(modifier = Modifier.weight(1f))
                Box(
                    modifier = Modifier
                        .border(1.dp, borderDark)
                        .clickable { classicTheme = !classicTheme }
                        .padding(horizontal = 10.dp, vertical = 6.dp),
                ) {
                    Text(
                        text = if (classicTheme) "Classic" else "Flat",
                        color = chromeText,
                        fontSize = 13.sp,
                    )
                }
            }

            Row(
                modifier = Modifier
                    .fillMaxWidth()
                    .background(chromeBg.copy(alpha = 0.92f))
                    .border(1.dp, borderDark)
                    .padding(horizontal = 10.dp, vertical = 6.dp),
                horizontalArrangement = Arrangement.SpaceBetween,
            ) {
                Text(
                    text = "Tab: ${tabs[selectedTab]} | Handle: 0x${nativeHandle.toString(16)}",
                    color = chromeText,
                    fontSize = 12.sp,
                )
                Text(
                    text = "Frames: $frameCount | Touch: $inputCount",
                    color = chromeText,
                    fontSize = 12.sp,
                )
            }
        }
    }
}
