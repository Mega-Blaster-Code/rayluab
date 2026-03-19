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
#include "rayluab_rcore.h"
#include "rayluab_rshapes.h"
#include "rayluab_raudio.h"
/**

*/

 void set_cfunction(lua_State *L, luaL_Reg*funcs){
	int i = 0;
	while(funcs[i].name != NULL && funcs[i].func != NULL){
		lua_pushcfunction(L, funcs[i].func);
		lua_setfield(L, -2, funcs[i].name);
		i++;
	}
}

 void set_logs(lua_State *L){
	lua_newtable(L);

	lua_pushinteger(L, LOG_ALL);
	lua_setfield(L, -2, "LOG_ALL");

	lua_pushinteger(L, LOG_TRACE);
	lua_setfield(L, -2, "LOG_TRACE");

	lua_pushinteger(L, LOG_DEBUG);
	lua_setfield(L, -2, "LOG_DEBUG");

	lua_pushinteger(L, LOG_INFO);
	lua_setfield(L, -2, "LOG_INFO");

	lua_pushinteger(L, LOG_WARNING);
	lua_setfield(L, -2, "LOG_WARNING");

	lua_pushinteger(L, LOG_ERROR);
	lua_setfield(L, -2, "LOG_ERROR");

	lua_pushinteger(L, LOG_FATAL);
	lua_setfield(L, -2, "LOG_FATAL");

	lua_pushinteger(L, LOG_NONE);
	lua_setfield(L, -2, "LOG_NONE");

	lua_pushinteger(L, LOG_NONE);
	lua_setfield(L, -2, "LOG_NONE");

	lua_setfield(L, -2, "Logs");

	return;
}

 void set_keys(lua_State *L){
	lua_newtable(L);

	lua_pushinteger(L, KEY_NULL);
	lua_setfield(L, -2, "null");

	lua_pushinteger(L, KEY_APOSTROPHE);
	lua_setfield(L, -2, "apostrophe");

	lua_pushinteger(L, KEY_COMMA);
	lua_setfield(L, -2, "comma");

	lua_pushinteger(L, KEY_MINUS);
	lua_setfield(L, -2, "minus");

	lua_pushinteger(L, KEY_PERIOD);
	lua_setfield(L, -2, "period");

	lua_pushinteger(L, KEY_SLASH);
	lua_setfield(L, -2, "slash");

	lua_pushinteger(L, KEY_ZERO);
	lua_setfield(L, -2, "zero");

	lua_pushinteger(L, KEY_ONE);
	lua_setfield(L, -2, "one");

	lua_pushinteger(L, KEY_TWO);
	lua_setfield(L, -2, "two");

	lua_pushinteger(L, KEY_THREE);
	lua_setfield(L, -2, "three");

	lua_pushinteger(L, KEY_FOUR);
	lua_setfield(L, -2, "four");

	lua_pushinteger(L, KEY_FIVE);
	lua_setfield(L, -2, "five");

	lua_pushinteger(L, KEY_SIX);
	lua_setfield(L, -2, "six");

	lua_pushinteger(L, KEY_SEVEN);
	lua_setfield(L, -2, "seven");

	lua_pushinteger(L, KEY_EIGHT);
	lua_setfield(L, -2, "eight");

	lua_pushinteger(L, KEY_NINE);
	lua_setfield(L, -2, "nine");

	lua_pushinteger(L, KEY_SEMICOLON);
	lua_setfield(L, -2, "semicolon");

	lua_pushinteger(L, KEY_EQUAL);
	lua_setfield(L, -2, "equal");

	lua_pushinteger(L, KEY_A); lua_setfield(L, -2, "a");
	lua_pushinteger(L, KEY_B); lua_setfield(L, -2, "b");
	lua_pushinteger(L, KEY_C); lua_setfield(L, -2, "c");
	lua_pushinteger(L, KEY_D); lua_setfield(L, -2, "d");
	lua_pushinteger(L, KEY_E); lua_setfield(L, -2, "e");
	lua_pushinteger(L, KEY_F); lua_setfield(L, -2, "f");
	lua_pushinteger(L, KEY_G); lua_setfield(L, -2, "g");
	lua_pushinteger(L, KEY_H); lua_setfield(L, -2, "h");
	lua_pushinteger(L, KEY_I); lua_setfield(L, -2, "i");
	lua_pushinteger(L, KEY_J); lua_setfield(L, -2, "j");
	lua_pushinteger(L, KEY_K); lua_setfield(L, -2, "k");
	lua_pushinteger(L, KEY_L); lua_setfield(L, -2, "l");
	lua_pushinteger(L, KEY_M); lua_setfield(L, -2, "m");
	lua_pushinteger(L, KEY_N); lua_setfield(L, -2, "n");
	lua_pushinteger(L, KEY_O); lua_setfield(L, -2, "o");
	lua_pushinteger(L, KEY_P); lua_setfield(L, -2, "p");
	lua_pushinteger(L, KEY_Q); lua_setfield(L, -2, "q");
	lua_pushinteger(L, KEY_R); lua_setfield(L, -2, "r");
	lua_pushinteger(L, KEY_S); lua_setfield(L, -2, "s");
	lua_pushinteger(L, KEY_T); lua_setfield(L, -2, "t");
	lua_pushinteger(L, KEY_U); lua_setfield(L, -2, "u");
	lua_pushinteger(L, KEY_V); lua_setfield(L, -2, "v");
	lua_pushinteger(L, KEY_W); lua_setfield(L, -2, "w");
	lua_pushinteger(L, KEY_X); lua_setfield(L, -2, "x");
	lua_pushinteger(L, KEY_Y); lua_setfield(L, -2, "y");
	lua_pushinteger(L, KEY_Z); lua_setfield(L, -2, "z");

	lua_pushinteger(L, KEY_SPACE); lua_setfield(L, -2, "space");
	lua_pushinteger(L, KEY_ENTER); lua_setfield(L, -2, "enter");
	lua_pushinteger(L, KEY_ESCAPE); lua_setfield(L, -2, "escape");
	lua_pushinteger(L, KEY_TAB); lua_setfield(L, -2, "tab");
	lua_pushinteger(L, KEY_BACKSPACE); lua_setfield(L, -2, "backspace");

	lua_pushinteger(L, KEY_UP); lua_setfield(L, -2, "up");
	lua_pushinteger(L, KEY_DOWN); lua_setfield(L, -2, "down");
	lua_pushinteger(L, KEY_LEFT); lua_setfield(L, -2, "left");
	lua_pushinteger(L, KEY_RIGHT); lua_setfield(L, -2, "right");

	lua_pushinteger(L, KEY_F1); lua_setfield(L, -2, "f1");
	lua_pushinteger(L, KEY_F2); lua_setfield(L, -2, "f2");
	lua_pushinteger(L, KEY_F3); lua_setfield(L, -2, "f3");
	lua_pushinteger(L, KEY_F4); lua_setfield(L, -2, "f4");
	lua_pushinteger(L, KEY_F5); lua_setfield(L, -2, "f5");
	lua_pushinteger(L, KEY_F6); lua_setfield(L, -2, "f6");
	lua_pushinteger(L, KEY_F7); lua_setfield(L, -2, "f7");
	lua_pushinteger(L, KEY_F8); lua_setfield(L, -2, "f8");
	lua_pushinteger(L, KEY_F9); lua_setfield(L, -2, "f9");
	lua_pushinteger(L, KEY_F10); lua_setfield(L, -2, "f10");
	lua_pushinteger(L, KEY_F11); lua_setfield(L, -2, "f11");
	lua_pushinteger(L, KEY_F12); lua_setfield(L, -2, "f12");
	lua_setfield(L, -2, "Keys");
	return;
}

int luaopen_rayluab(lua_State *L){
	rll_createMT(L);
	luaL_Reg window_funcs[] = {
		{"InitWindow", rll_InitWindow},
		{"CloseWindow", rll_CloseWindow},
		{"WindowShouldClose", rll_WindowShouldClose},
		{"IsWindowReady", rll_IsWindowReady},
		{"IsWindowFullscreen", rll_IsWindowFullscreen},
		{"IsWindowHidden", rll_IsWindowHidden},
		{"IsWindowMinimized", rll_IsWindowMinimized},
		{"IsWindowMaximized", rll_IsWindowMaximized},
		{"IsWindowFocused", rll_IsWindowFocused},
		{"IsWindowResized", rll_IsWindowResized},
		{"IsWindowState", rll_IsWindowState},
		{"SetWindowState", rll_SetWindowState},
		{"ClearWindowState", rll_ClearWindowState},
		{"ToggleFullscreen", rll_ToggleFullscreen},
		{"ToggleBorderlessWindowed", rll_ToggleBorderlessWindowed},
		{"MaximizeWindow", rll_MaximizeWindow},
		{"MinimizeWindow", rll_MinimizeWindow},
		{"RestoreWindow", rll_RestoreWindow},
		{"SetWindowIcon", rll_SetWindowIcon},
		{"SetWindowTitle", rll_SetWindowTitle},
		{"SetWindowPosition", rll_SetWindowPosition},
		{"SetWindowMonitor", rll_SetWindowMonitor},
		{"SetWindowMinSize", rll_SetWindowMinSize},
		{"SetWindowMaxSize", rll_SetWindowMaxSize},
		{"SetWindowSize", rll_SetWindowSize},
		{"SetWindowOpacity", rll_SetWindowOpacity},
		{"SetWindowFocused", rll_SetWindowFocused},
		{"GetScreenWidth", rll_GetScreenWidth},
		{"GetScreenHeight", rll_GetScreenHeight},
		{"GetRenderWidth", rll_GetRenderWidth},
		{"GetRenderHeight", rll_GetRenderHeight},
		{"GetMonitorCount", rll_GetMonitorCount},
		{"GetCurrentMonitor", rll_GetCurrentMonitor},
		{"GetMonitorPosition", rll_GetMonitorPosition},
		{"GetMonitorWidth", rll_GetMonitorWidth},
		{"GetMonitorHeight", rll_GetMonitorHeight},
		{"GetMonitorPhysicalWidth", rll_GetMonitorPhysicalWidth},
		{"GetMonitorPhysicalHeight", rll_GetMonitorPhysicalHeight},
		{"GetMonitorRefreshRate", rll_GetMonitorRefreshRate},
		{"GetWindowPosition", rll_GetWindowPosition},
		{"GetWindowScaleDPI", rll_GetWindowScaleDPI},
		{"GetMonitorName", rll_GetMonitorName},
		{"SetClipboardText", rll_SetClipboardText},
		{"GetClipboardText", rll_GetClipboardText},
		{"EnableEventWaiting", rll_EnableEventWaiting},
		{"DisableEventWaiting", rll_DisableEventWaiting},
		{"ClearBackground", rll_ClearBackground},
		{"BeginDrawing", rll_BeginDrawing},
		{"EndDrawing", rll_EndDrawing},
		{"BeginScissorMode", rll_BeginScissorMode},
		{"EndScissorMode", rll_EndScissorMode},
		{"SetTargetFPS", rll_SetTargetFPS},
		{"GetFrameTime", rll_GetFrameTime},
		{"GetTime", rll_GetTime},
		{"GetFPS", rll_GetFPS},
		{"SwapScreenBuffer", rll_SwapScreenBuffer},
		{"PollInputEvents", rll_PollInputEvents},
		{"WaitTime", rll_WaitTime},
		{"SetRandomSeed", rll_SetRandomSeed},
		{"GetRandomValue", rll_GetRandomValue},
		{"TakeScreenshot", rll_TakeScreenshot},
		{"SetConfigFlags", rll_SetConfigFlags},
		{"OpenURL", rll_OpenURL},
		{"TraceLog",rll_TraceLog},
		{"SetTraceLogLevel",rll_SetTraceLogLevel},
		{"CompressData", rll_CompressData},
		{"DecompressData", rll_DecompressData},
		{"EncodeDataBase64", rll_EncodeDataBase64},
		{"DecodeDataBase64", rll_DecodeDataBase64},
		{"ComputeCRC32", rll_ComputeCRC32},
		{"ComputeMD5", rll_ComputeMD5},
		{"ComputeSHA1", rll_ComputeSHA1},
		{NULL, NULL}
	};

	luaL_Reg shape_funcs[] = {
		{"SetColor", rll_SetColor},
		{"DrawPixel", rll_DrawPixel},
		{"DrawLine", rll_DrawLine},
		{"DrawLineEx", rll_DrawLineEx},
		{"DrawLineBezier", rll_DrawLineBezier},
		{"DrawCircle", rll_DrawCircle},
		{"DrawCircleSector", rll_DrawCircleSector},
		{"DrawCircleSectorLines", rll_DrawCircleSectorLines},
		{"DrawCircleGradient", rll_DrawCircleGradient},
		{"DrawCircleLines", rll_DrawCircleLines},
		{"DrawEllipse", rll_DrawEllipse},
		{"DrawEllipseLines", rll_DrawEllipseLines},
		{"DrawRing", rll_DrawRing},
		{"DrawRingLines", rll_DrawRingLines},
		{"DrawRectangle", rll_DrawRectangle},
		{"DrawRectanglePro", rll_DrawRectanglePro},
		{"DrawRectangleGradientV", rll_DrawRectangleGradientV},
		{"DrawRectangleGradientH", rll_DrawRectangleGradientH},
		{"DrawRectangleGradientEx", rll_DrawRectangleGradientEx},
		{"DrawRectangleLines",rll_DrawRectangleLines},
		{"DrawRectangleLinesEx", rll_DrawRectangleLinesEx},
		{"DrawRectangleRounded", rll_DrawRectangleRounded},
		{"DrawRectangleRoundedLines", rll_DrawRectangleRoundedLines},
		{"DrawRectangleRoundedLinesEx", rll_DrawRectangleRoundedLinesEx},
		{"DrawTriangle", rll_DrawTriangle},
		{"DrawTriangleLines", rll_DrawTriangleLines},
		{"DrawPoly", rll_DrawPoly},
		{"DrawPolyLines", rll_DrawPolyLines},
		{"DrawPolyLinesEx", rll_DrawPolyLinesEx},
		{"CheckCollisionRecs", rll_CheckCollisionRecs},
		{"CheckCollisionCircles", rll_CheckCollisionCircles},
		{"CheckCollisionCircleRec", rll_CheckCollisionCircleRec},
		{"CheckCollisionCircleLine", rll_CheckCollisionCircleLine},
		{"CheckCollisionPointRec", rll_CheckCollisionPointRec},
		{"CheckCollisionPointCircle", rll_CheckCollisionPointCircle},
		{"CheckCollisionPointTriangle", rll_CheckCollisionPointTriangle},
		{"CheckCollisionPointLine", rll_CheckCollisionPointLine},
		{"CheckCollisionLines", rll_CheckCollisionLines},
		{"GetCollisionRec", rll_GetCollisionRec},
		{NULL, NULL},
	};

	luaL_Reg mouse_funcs[] = {
		{"ShowCursor", rll_ShowCursor},
		{"HideCursor", rll_HideCursor},
		{"IsCursorHidden", rll_IsCursorHidden},
		{"EnableCursor", rll_EnableCursor},
		{"DisableCursor", rll_DisableCursor},
		{"IsCursorOnScreen", rll_IsCursorOnScreen},
		{"IsMouseButtonPressed", rll_IsMouseButtonPressed},
		{"IsMouseButtonDown", rll_IsMouseButtonDown},
		{"IsMouseButtonReleased", rll_IsMouseButtonReleased},
		{"IsMouseButtonUp", rll_IsMouseButtonUp},
		{"GetMouseX", rll_GetMouseX},
		{"GetMouseY", rll_GetMouseY},
		{"GetMousePosition", rll_GetMousePosition},
		{"GetMouseDelta", rll_GetMouseDelta},
		{"SetMousePosition", rll_SetMousePosition},
		{"SetMouseOffset", rll_SetMouseOffset},
		{"SetMouseScale", rll_SetMouseScale},
		{"GetMouseWheelMove", rll_GetMouseWheelMove},
		{"GetMouseWheelMoveV", rll_GetMouseWheelMoveV},
		{"SetMouseCursor", rll_SetMouseCursor},
		{NULL, NULL}
	};

	luaL_Reg keyboard_funcs[] = {
		{"IsKeyPressed", rll_IsKeyPressed},
		{"IsKeyPressedRepeat", rll_IsKeyPressedRepeat},
		{"IsKeyDown", rll_IsKeyDown},
		{"IsKeyReleased", rll_IsKeyReleased},
		{"IsKeyUp", rll_IsKeyUp},
		{"GetKeyPressed", rll_GetKeyPressed},
		{"GetCharPressed", rll_GetCharPressed},
		{"SetExitKey", rll_SetExitKey},
		{NULL, NULL}
	};

	luaL_Reg audio_funcs[] = {
		{"InitAudioDevice", rll_InitAudioDevice},
		{"CloseAudioDevice", rll_CloseAudioDevice},
		{"IsAudioDeviceReady", rll_IsAudioDeviceReady},
		{"SetMasterVolume", rll_SetMasterVolume},
		{"GetMasterVolume", rll_GetMasterVolume},
		{"LoadWave", rll_LoadWave},
		{"LoadWaveFromMemory", rll_LoadWaveFromMemory},
		{"IsWaveValid", rll_IsWaveValid},
		{"LoadSound", rll_LoadSound},
		{"LoadSoundFromWave", rll_LoadSoundFromWave},
		{"LoadSoundAlias", rll_LoadSoundAlias},
		{"IsSoundValid", rll_IsSoundValid},
		{"UpdateSound", rll_UpdateSound},
		{"UnloadWave", rll_UnloadWave},
		{"UnloadSound", rll_UnloadSound},
		{"UnloadSoundAlias", rll_UnloadSoundAlias},
		{"ExportWave", rll_ExportWave},
		{"ExportWaveAsCode", rll_ExportWaveAsCode},
		{"PlaySound", rll_PlaySound},
		{"StopSound", rll_StopSound},
		{"PauseSound", rll_PauseSound},
		{"ResumeSound", rll_ResumeSound},
		{NULL, NULL},
	};

	lua_newtable(L); // rayluab
	lua_newtable(L); // window

	set_cfunction(L, window_funcs);

	set_logs(L);

	lua_setfield(L, -2, "Window"); // window

	lua_newtable(L); // shapes

	set_cfunction(L, shape_funcs);

	lua_setfield(L, -2, "Shapes"); // shapes

	lua_newtable(L); // mouse

	set_cfunction(L, mouse_funcs);

	lua_setfield(L, -2, "Mouse"); // mouse

	lua_newtable(L); // keyboard

	set_cfunction(L, keyboard_funcs);

	set_keys(L);

	lua_setfield(L, -2, "Keyboard"); // keyboard

	lua_newtable(L);

	set_cfunction(L, audio_funcs);

	lua_setfield(L, -2, "Audio"); // keyboard

	//KEY_A
	//luaL_newlib(L, window_funcs);
	return 1;
}