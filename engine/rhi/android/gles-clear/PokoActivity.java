package com.poko.glesclear;

import android.app.Activity;
import android.os.Bundle;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

// Minimal shell probe: hands a real Surface to native code which runs the
// Vulkan-primary / GLES-fallback clear probe off the UI thread.
public class PokoActivity extends Activity implements SurfaceHolder.Callback {
    static { System.loadLibrary("poko_shell"); }

    private SurfaceView view;

    private native void nativeInit(String filesDir);
    private native void nativeSetSurface(Surface surface, int width, int height);
    private native void nativeSurfaceDestroyed();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        view = new SurfaceView(this);
        view.getHolder().addCallback(this);
        setContentView(view);
        nativeInit(getFilesDir().getAbsolutePath());
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        Surface s = holder.getSurface();
        android.graphics.Rect r = holder.getSurfaceFrame();
        nativeSetSurface(s, r.width(), r.height());
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
        nativeSetSurface(holder.getSurface(), width, height);
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        nativeSurfaceDestroyed();
    }

    @Override
    protected void onDestroy() {
        nativeSurfaceDestroyed();
        super.onDestroy();
    }
}
