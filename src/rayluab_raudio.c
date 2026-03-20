#include "rayluab_raudio.h"

int rll_InitAudioDevice(lua_State *L){
	InitAudioDevice();
	return 0;
}

int rll_CloseAudioDevice(lua_State *L){
	CloseAudioDevice();
	return 0;
}

int rll_IsAudioDeviceReady(lua_State *L){
	int b = IsAudioDeviceReady();
	lua_pushboolean(L, b);
	return 1;
}

int rll_SetMasterVolume(lua_State *L){
	float volume = (float)luaL_checknumber(L, 1);
	SetMasterVolume(volume);
	return 0;
}

int rll_GetMasterVolume(lua_State *L){
	lua_Number volume = (lua_Number)GetMasterVolume();
	lua_pushnumber(L, volume);
	return 1;
}

int rll_LoadWave(lua_State *L){
	const char* filename = luaL_checkstring(L, 1);
	Wave w = LoadWave(filename);
	if(!IsWaveValid(w)){
		lua_pushnil(L);
		return 0;
	}
	rll_newuserdata(L, WAVE_USERDATA, &w, sizeof(w));
	return 1;
}

int rll_LoadWaveFromMemory(lua_State *L){
	const char* filetype = luaL_checkstring(L, 1);
	size_t dataSize = 0;
	const unsigned char* filedata = (const unsigned char*)luaL_checklstring(L, 2, &dataSize);
	Wave w = LoadWaveFromMemory(filetype, filedata, dataSize);
	rll_newuserdata(L, WAVE_USERDATA, &w, sizeof(w));
	return 1;
}

int rll_IsWaveValid(lua_State *L){
	Wave *wave = (Wave*)rll_getuserdata_data(L, 1, WAVE_USERDATA);
	int b = IsWaveValid(*wave);
	lua_pushboolean(L, b);
	return 1;
}

int rll_LoadSound(lua_State *L){
	const char* filename = luaL_checkstring(L, 1);
	Sound s = LoadSound(filename);
	if(!IsSoundValid(s)){
		lua_pushnil(L);
		return 0;
	}
	rll_newuserdata(L, SOUND_USERDATA, &s, sizeof(s));
	return 1;
}

int rll_LoadSoundFromWave(lua_State *L){
	Wave *w = rll_getuserdata_data(L, 1, WAVE_USERDATA);
	Sound s = LoadSoundFromWave(*w);
	rll_newuserdata(L, SOUND_USERDATA, &s, sizeof(s));
	return 1;
}

int rll_LoadSoundAlias(lua_State *L){
	Sound *source = rll_getuserdata_data(L, 1, SOUND_USERDATA);
	Sound s = LoadSoundAlias(*source);
	rll_newuserdata(L, SOUND_USERDATA, &s, sizeof(s));
	return 1;
}

int rll_IsSoundValid(lua_State *L){
	Sound *source = rll_getuserdata_data(L, 1, SOUND_USERDATA);
	int b = IsSoundValid(*source);
	lua_pushboolean(L, b);
	return 1;
}

int rll_UpdateSound(lua_State *L){
	Sound *source = rll_getuserdata_data(L, 1, SOUND_USERDATA);
	size_t size = 0;
	void *data = (void *)luaL_checklstring(L, 2, &size);
	int sampleCount = (int)luaL_checkinteger(L, 3);
	UpdateSound(*source, data, sampleCount);
	return 0;
}

int rll_UnloadWave(lua_State *L){
	Wave *w = rll_getuserdata_data(L, 1, WAVE_USERDATA);
	UnloadWave(*w);
	return 0;
}

int rll_UnloadSound(lua_State *L){
	Sound *s = rll_getuserdata_data(L, 1, SOUND_USERDATA);
	UnloadSound(*s);
	return 0;
}

int rll_UnloadSoundAlias(lua_State *L){
	Sound *s = rll_getuserdata_data(L, 1, SOUND_USERDATA);
	UnloadSoundAlias(*s);
	return 0;
}

int rll_ExportWave(lua_State *L){
	Wave *w = rll_getuserdata_data(L, 1, WAVE_USERDATA);
	size_t size = 0;
	const char* filename = luaL_checklstring(L, 2, &size);
	lua_pushboolean(L, ExportWave(*w, filename));
	return 1;
}

int rll_ExportWaveAsCode(lua_State *L){
	Wave *w = rll_getuserdata_data(L, 1, WAVE_USERDATA);
	size_t size = 0;
	const char* filename = luaL_checklstring(L, 2, &size);
	lua_pushboolean(L, ExportWaveAsCode(*w, filename));
	return 1;
}

int rll_PlaySound(lua_State *L){
	Sound *s = rll_getuserdata_data(L, 1, SOUND_USERDATA);
	PlaySound(*s);
	return 0;
}

int rll_StopSound(lua_State *L){
	Sound *s = rll_getuserdata_data(L, 1, SOUND_USERDATA);
	StopSound(*s);
	return 0;
}

int rll_PauseSound(lua_State *L){
	Sound *s = rll_getuserdata_data(L, 1, SOUND_USERDATA);
	PauseSound(*s);
	return 0;
}

int rll_ResumeSound(lua_State *L){
	Sound *s = rll_getuserdata_data(L, 1, SOUND_USERDATA);
	ResumeSound(*s);
	return 0;
}


int rll_IsSoundPlaying(lua_State *L){
	Sound *s = rll_getuserdata_data(L, 1, SOUND_USERDATA);
	int b = IsSoundPlaying(*s);
	lua_pushboolean(L, b);
	return 1;
}

int rll_SetSoundVolume(lua_State *L){
	Sound *s = rll_getuserdata_data(L, 1, SOUND_USERDATA);
	float volume = (float)luaL_checknumber(L, 2);
	SetSoundVolume(*s, volume);
	return 0;
}

int rll_SetSoundPitch(lua_State *L){
	Sound *s = rll_getuserdata_data(L, 1, SOUND_USERDATA);
	float pitch = (float)luaL_checknumber(L, 2);
	SetSoundPitch(*s, pitch);
	return 0;
}

int rll_SetSoundPan(lua_State *L){
	Sound *s = rll_getuserdata_data(L, 1, SOUND_USERDATA);
	float pan = (float)luaL_checknumber(L, 2);
	SetSoundPitch(*s, pan);
	return 0;
}

int rll_WaveCopy(lua_State *L){
	Wave *w = rll_getuserdata_data(L, 1, WAVE_USERDATA);
	Wave nw = WaveCopy(*w);
	rll_newuserdata(L, WAVE_USERDATA, &nw, sizeof(nw));
	return 1;
}

int rll_WaveCrop(lua_State *L){
	Wave *w = rll_getuserdata_data(L, 1, WAVE_USERDATA);
	int initFrame = (int)luaL_checkinteger(L, 2);
	int finalFrame = (int)luaL_checkinteger(L, 3);
	WaveCrop(w, initFrame, finalFrame);
	return 0;
}

int rll_WaveFormat(lua_State *L){
	Wave *w = rll_getuserdata_data(L, 1, WAVE_USERDATA);
	int sampleRate = (int)luaL_checkinteger(L, 2);
	int sampleSize = (int)luaL_checkinteger(L, 3);
	int channels = (int)luaL_checkinteger(L, 4);
	WaveFormat(w, sampleRate, sampleSize, channels);
	return 0;
}

int rll_LoadWaveSamples(lua_State *L){
    Wave *w = rll_getuserdata_data(L, 1, WAVE_USERDATA);

    float *samples = LoadWaveSamples(*w);

    rll_newuserdata(L, FLOATARRAY_USERDATA, samples, sizeof(float*));

    return 1;
}

int rll_WaveSamplesGet(lua_State *L){
	float *samples = rll_getuserdata_data(L, 1, FLOATARRAY_USERDATA);
	lua_Integer index = luaL_checkinteger(L, 2);
	lua_pushnumber(L, (lua_Number)samples[index]);
	return 1;
}

int rll_WaveSamplesSet(lua_State *L){
	float *samples = rll_getuserdata_data(L, 1, FLOATARRAY_USERDATA);
	lua_Integer index = luaL_checkinteger(L, 2);
	lua_Number value = luaL_checknumber(L, 3);
	samples[index] = (float)value;
	return 0;
}

int rll_UnloadWaveSamples(lua_State *L){
    float *samples = rll_getuserdata_data(L, 1, FLOATARRAY_USERDATA);

    UnloadWaveSamples(samples);

    return 0;
}

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

/*
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