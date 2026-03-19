#ifndef __RAYLUAB_RAUDIO_H
#define __RAYLUAB_RAUDIO_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <lua5.4/lua.h>
#include <lua5.4/lauxlib.h>
#include <time.h>
#include "./../raylib/raylib.h"
#include "safema.h"
#include "udata.h"

int rll_InitAudioDevice(lua_State *L);

int rll_CloseAudioDevice(lua_State *L);

int rll_IsAudioDeviceReady(lua_State *L);

int rll_SetMasterVolume(lua_State *L);

int rll_GetMasterVolume(lua_State *L);

int rll_LoadWave(lua_State *L);

int rll_LoadWaveFromMemory(lua_State *L);

int rll_IsWaveValid(lua_State *L);

int rll_LoadSound(lua_State *L);

int rll_LoadSoundFromWave(lua_State *L);

int rll_LoadSoundAlias(lua_State *L);

int rll_IsSoundValid(lua_State *L);

int rll_UpdateSound(lua_State *L);

int rll_UnloadWave(lua_State *L);

int rll_UnloadSound(lua_State *L);

int rll_UnloadSoundAlias(lua_State *L);

int rll_ExportWave(lua_State *L);

int rll_ExportWaveAsCode(lua_State *L);

int rll_PlaySound(lua_State *L);

int rll_StopSound(lua_State *L);

int rll_PauseSound(lua_State *L);

int rll_ResumeSound(lua_State *L);

/*
bool rll_IsSoundPlaying(Sound sound);

int rll_SetSoundVolume(Sound sound, float volume);

int rll_SetSoundPitch(Sound sound, float pitch);

int rll_SetSoundPan(Sound sound, float pan);

Wave rll_WaveCopy(Wave wave);

int rll_WaveCrop(Wave *wave, int initFrame, int finalFrame);

int rll_WaveFormat(Wave *wave, int sampleRate, int sampleSize, int channels);

float *rll_LoadWaveSamples(Wave wave);

int rll_UnloadWaveSamples(float *samples);

Music rll_LoadMusicStream(const char *fileName);

Music rll_LoadMusicStreamFromMemory(const char *fileType, const unsigned char *data, int dataSize);

bool rll_IsMusicValid(Music music);

int rll_UnloadMusicStream(Music music);

int rll_PlayMusicStream(Music music);

bool rll_IsMusicStreamPlaying(Music music);

int rll_UpdateMusicStream(Music music);

int rll_StopMusicStream(Music music);

int rll_PauseMusicStream(Music music);

int rll_ResumeMusicStream(Music music);

int rll_SeekMusicStream(Music music, float position);

int rll_SetMusicVolume(Music music, float volume);

int rll_SetMusicPitch(Music music, float pitch);

int rll_SetMusicPan(Music music, float pan);

float rll_GetMusicTimeLength(Music music);

float rll_GetMusicTimePlayed(Music music);

AudioStream rll_LoadAudioStream(unsigned int sampleRate, unsigned int sampleSize, unsigned int channels);

bool rll_IsAudioStreamValid(AudioStream stream);

int rll_UnloadAudioStream(AudioStream stream);

int rll_UpdateAudioStream(AudioStream stream, const void *data, int frameCount);

bool rll_IsAudioStreamProcessed(AudioStream stream);

int rll_PlayAudioStream(AudioStream stream);

int rll_PauseAudioStream(AudioStream stream);

int rll_ResumeAudioStream(AudioStream stream);

bool rll_IsAudioStreamPlaying(AudioStream stream);

int rll_StopAudioStream(AudioStream stream);

int rll_SetAudioStreamVolume(AudioStream stream, float volume);

int rll_SetAudioStreamPitch(AudioStream stream, float pitch);

int rll_SetAudioStreamPan(AudioStream stream, float pan);

int rll_SetAudioStreamBufferSizeDefault(int size);

int rll_SetAudioStreamCallback(AudioStream stream, AudioCallback callback);

int rll_AttachAudioStreamProcessor(AudioStream stream, AudioCallback processor);

int rll_DetachAudioStreamProcessor(AudioStream stream, AudioCallback processor);

int rll_AttachAudioMixedProcessor(AudioCallback processor);
*/

#endif // __RAYLUAB_RAUDIO_H