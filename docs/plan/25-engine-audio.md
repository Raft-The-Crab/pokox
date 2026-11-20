# 25 — Engine audio

## Architecture

A pull-based mixer graph evaluated once per frame on the audio thread. Sources are voices; voices feed buses; buses feed the master output. The graph is declarative data built from developer settings, not arbitrary code, so it cannot affect validated state.

```
voice -> group bus -> master bus -> output
         (music, sfx, voice, ui)
```

Four buses: master, music, sfx, voice. Each has volume, mute and an optional effect chain. Bus settings are saved per user.

## Voices

A voice is one playing instance of an audio asset. Properties: asset handle, gain, pitch, spatial mode, loop, start offset and fade. Voices are pooled; acquiring one returns a handle, and releasing it returns the voice to the pool after the fade completes. Max 256 voices Windows, 128 Android. Exceeding the cap steals the quietest non-critical voice.

## Codecs

Opus in Ogg is the only runtime codec. Assets over 10 seconds stream from a chunk in 256 KB blocks with a two-block buffer; shorter assets decode fully into memory at load. Music loops use precomputed loop points from import. No MP3 or WAV decoding in the runtime.

## Spatial audio

Spatial voices carry position, velocity, min and max distance, rolloff model and cone angles. Distance attenuation is inverse with a rolloff factor. Panning uses equal-power for stereo. HRTF is an AA feature enabled on Windows and high-end Android; the A-tier fallback is stereo panning. Obstruction and occlusion are driven by developer-authored portal volumes, not physics raycasts, to keep cost predictable and avoid touching sim state.

## Effects

A tier: gain, pan, low-pass filter, reverb send on music and sfx buses. AA adds 3-band EQ, compressor and a per-voice high-pass. AAA adds convolution reverb with developer-supplied impulses. Effects are chosen from a fixed set of typed nodes; developers cannot author arbitrary DSP, which keeps the sandbox intact.

## Mixer loop

1. Audio thread pulls the next buffer from sources
2. Streaming voices refill blocks from the asset system on the IO queue
3. Effects process in declared bus order
4. Master applies limiter and outputs to SDL3 audio
5. Frame stats report voice count, buffer underruns and CPU time

Buffer underruns increment a counter shown in the profiler and in ImGui during development. Three underruns in 10 seconds on Android trigger a sample-rate reduction.

## Voice chat

Live voice is not a stored asset. It uses the control plane's reliable channel with Opus encoding at 20 ms frames. Rooms are scoped to a party or a game session. Proximity mode uses each player's validated position and the same distance curve as spatial voices. Mute is local; a player cannot be forced to transmit. Voice data is never written to replay rings or logs.

## Asset integration

Audio assets are content-addressed chunks from the asset pipeline with `.meta` settings for quality and streaming. A change to import settings changes the CID, so audio can be deduped like textures. Loading is async; a missing voice asset falls back to silence with a warning rather than stalling.

## Platform

SDL3 audio is the output on Windows and Android. The platform layer reports the device sample rate and buffer size; the mixer resamples with a fixed linear interpolator to a canonical 48 kHz internal rate. Android audio focus loss pauses the mixer and resumes on focus gain, matching the app lifecycle.

## Determinism boundary

Audio is entirely presentational. No audio event writes validated state, and Mute audio hostcalls are capability-gated and marked `Trusted`. A developer who tries to derive a gameplay outcome from audio playback gets a determinism lint error.

## Budgets

128 MB decoded audio Windows, 64 MB Android; 256/128 voices; 20 ms voice-chat frames; under 2 ms mixer CPU on Windows and under 4 ms on Android.

## Debug features

Voice pool occupancy, bus gain meters, underrun counters, spatial voice positions drawn in debug view, and a solo or mute control per bus. All available in the ImGui harness and the Studio profiler.
