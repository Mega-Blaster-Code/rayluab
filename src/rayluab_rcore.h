#ifndef __RAYLUAB_RCORE_H
#define __RAYLUAB_RCORE_H

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

int rll_InitWindow(lua_State *L);

int rll_CloseWindow(lua_State *L);

int rll_WindowShouldClose(lua_State *L);

int rll_IsWindowReady(lua_State *L);

int rll_IsWindowFullscreen(lua_State *L);

int rll_IsWindowHidden(lua_State *L);

int rll_IsWindowMinimized(lua_State *L);

int rll_IsWindowMaximized(lua_State *L);

int rll_IsWindowFocused(lua_State *L);

int rll_IsWindowResized(lua_State *L);

int rll_IsWindowState(lua_State *L);

int rll_SetWindowState(lua_State *L);

int rll_ClearWindowState(lua_State *L);

int rll_ToggleFullscreen(lua_State *L);

int rll_ToggleBorderlessWindowed(lua_State *L);

int rll_MaximizeWindow(lua_State *L);

int rll_MinimizeWindow(lua_State *L);

int rll_RestoreWindow(lua_State *L);

int rll_SetWindowIcon(lua_State *L);

int rll_SetWindowTitle(lua_State *L);

int rll_SetWindowPosition(lua_State *L);

int rll_SetWindowMonitor(lua_State *L);

int rll_SetWindowMinSize(lua_State *L);

int rll_SetWindowMaxSize(lua_State *L);

int rll_SetWindowSize(lua_State *L);

int rll_SetWindowOpacity(lua_State *L);

int rll_SetWindowFocused(lua_State *L);

//int rll_GetWindowHandle(lua_State *L);

int rll_GetScreenWidth(lua_State *L);

int rll_GetScreenHeight(lua_State *L);

int rll_GetRenderWidth(lua_State *L);

int rll_GetRenderHeight(lua_State *L);

int rll_GetMonitorCount(lua_State *L);

int rll_GetCurrentMonitor(lua_State *L);

int rll_GetMonitorPosition(lua_State *L);

int rll_GetMonitorWidth(lua_State *L);

int rll_GetMonitorHeight(lua_State *L);

int rll_GetMonitorPhysicalWidth(lua_State *L);

int rll_GetMonitorPhysicalHeight(lua_State *L);

int rll_GetMonitorRefreshRate(lua_State *L);

int rll_GetWindowPosition(lua_State *L);

int rll_GetWindowScaleDPI(lua_State *L);

int rll_GetMonitorName(lua_State *L);

int rll_SetClipboardText(lua_State *L);

int rll_GetClipboardText(lua_State *L);

int rll_EnableEventWaiting(lua_State *L);

int rll_DisableEventWaiting(lua_State *L);

int rll_ShowCursor(lua_State *L);

int rll_HideCursor(lua_State *L);

int rll_IsCursorHidden(lua_State *L);

int rll_EnableCursor(lua_State *L);

int rll_DisableCursor(lua_State *L);

int rll_IsCursorOnScreen(lua_State *L);

int rll_ClearBackground(lua_State *L);

int rll_BeginDrawing(lua_State *L);

int rll_EndDrawing(lua_State *L);

int rll_BeginScissorMode(lua_State *L);

int rll_EndScissorMode(lua_State *L);

int rll_SetTargetFPS(lua_State *L);

int rll_GetFrameTime(lua_State *L);

int rll_GetTime(lua_State *L);

int rll_GetFPS(lua_State *L);

int rll_SwapScreenBuffer(lua_State *L);

int rll_PollInputEvents(lua_State *L);

int rll_WaitTime(lua_State *L);

int rll_SetRandomSeed(lua_State *L);

int rll_GetRandomValue(lua_State *L);

int rll_TakeScreenshot(lua_State *L);

int rll_SetConfigFlags(lua_State *L);

int rll_OpenURL(lua_State *L);

int rll_TraceLog(lua_State *L);

int rll_SetTraceLogLevel(lua_State *L);

int rll_CompressData(lua_State *L);

int rll_DecompressData(lua_State *L);

int rll_EncodeDataBase64(lua_State *L);

int rll_DecodeDataBase64(lua_State *L);

int rll_ComputeCRC32(lua_State *L);

int rll_ComputeMD5(lua_State *L);

int rll_ComputeSHA1(lua_State *L);

int rll_IsKeyPressed(lua_State *L);

int rll_IsKeyPressedRepeat(lua_State *L);

int rll_IsKeyDown(lua_State *L);

int rll_IsKeyReleased(lua_State *L);

int rll_IsKeyUp(lua_State *L);

int rll_GetKeyPressed(lua_State *L);

int rll_GetCharPressed(lua_State *L);

int rll_SetExitKey(lua_State *L);

int rll_IsMouseButtonPressed(lua_State *L);

int rll_IsMouseButtonDown(lua_State *L);

int rll_IsMouseButtonReleased(lua_State *L);

int rll_IsMouseButtonUp(lua_State *L);

int rll_GetMouseX(lua_State *L);

int rll_GetMouseY(lua_State *L);

int rll_GetMousePosition(lua_State *L);

int rll_GetMouseDelta(lua_State *L);

int rll_SetMousePosition(lua_State *L);

int rll_SetMouseOffset(lua_State *L);

int rll_SetMouseScale(lua_State *L);

int rll_GetMouseWheelMove(lua_State *L);

int rll_GetMouseWheelMoveV(lua_State *L);

int rll_SetMouseCursor(lua_State *L);

#endif //__RAYLUAB_RCORE_H