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

static int rll_InitWindow(lua_State *L);

static int rll_CloseWindow(lua_State *L);

static int rll_WindowShouldClose(lua_State *L);

static int rll_IsWindowReady(lua_State *L);

static int rll_IsWindowFullscreen(lua_State *L);

static int rll_IsWindowHidden(lua_State *L);

static int rll_IsWindowMinimized(lua_State *L);

static int rll_IsWindowMaximized(lua_State *L);

static int rll_IsWindowFocused(lua_State *L);

static int rll_IsWindowResized(lua_State *L);

static int rll_IsWindowState(lua_State *L);

static int rll_SetWindowState(lua_State *L);

static int rll_ClearWindowState(lua_State *L);

static int rll_ToggleFullscreen(lua_State *L);

static int rll_ToggleBorderlessWindowed(lua_State *L);

static int rll_MaximizeWindow(lua_State *L);

static int rll_MinimizeWindow(lua_State *L);

static int rll_RestoreWindow(lua_State *L);

static int rll_SetWindowIcon(lua_State *L);

static int rll_SetWindowTitle(lua_State *L);

static int rll_SetWindowPosition(lua_State *L);

static int rll_SetWindowMonitor(lua_State *L);

static int rll_SetWindowMinSize(lua_State *L);

static int rll_SetWindowMaxSize(lua_State *L);

static int rll_SetWindowSize(lua_State *L);

static int rll_SetWindowOpacity(lua_State *L);

static int rll_SetWindowFocused(lua_State *L);

static int rll_GetWindowHandle(lua_State *L);

static int rll_GetScreenWidth(lua_State *L);

static int rll_GetScreenHeight(lua_State *L);

static int rll_GetRenderWidth(lua_State *L);

static int rll_GetRenderHeight(lua_State *L);

static int rll_GetMonitorCount(lua_State *L);

static int rll_GetCurrentMonitor(lua_State *L);

static int rll_GetMonitorPosition(lua_State *L);

static int rll_GetMonitorWidth(lua_State *L);

static int rll_GetMonitorHeight(lua_State *L);

static int rll_GetMonitorPhysicalWidth(lua_State *L);

static int rll_GetMonitorPhysicalHeight(lua_State *L);

static int rll_GetMonitorRefreshRate(lua_State *L);

static int rll_GetWindowPosition(lua_State *L);

static int rll_GetWindowScaleDPI(lua_State *L);

static int rll_GetMonitorName(lua_State *L);

static int rll_SetClipboardText(lua_State *L);

static int rll_GetClipboardText(lua_State *L);

static int rll_EnableEventWaiting(lua_State *L);

static int rll_DisableEventWaiting(lua_State *L);

static int rll_ShowCursor(lua_State *L);

static int rll_HideCursor(lua_State *L);

static int rll_IsCursorHidden(lua_State *L);

static int rll_EnableCursor(lua_State *L);

static int rll_DisableCursor(lua_State *L);

static int rll_IsCursorOnScreen(lua_State *L);

static int rll_ClearBackground(lua_State *L);

static int rll_BeginDrawing(lua_State *L);

static int rll_EndDrawing(lua_State *L);

static int rll_BeginScissorMode(lua_State *L);

static int rll_EndScissorMode(lua_State *L);

static int rll_SetTargetFPS(lua_State *L);


static int rll_GetFrameTime(lua_State *L);

static int rll_GetTime(lua_State *L);

static int rll_GetFPS(lua_State *L);

static int rll_SwapScreenBuffer(lua_State *L);

static int rll_PollInputEvents(lua_State *L);

static int rll_WaitTime(lua_State *L);

static int rll_SetRandomSeed(lua_State *L);

static int rll_GetRandomValue(lua_State *L);

static int rll_TakeScreenshot(lua_State *L);

static int rll_SetConfigFlags(lua_State *L);

static int rll_OpenURL(lua_State *L);

/*

void rll_TraceLog(int logLevel, const char *text, ...);

void rll_SetTraceLogLevel(int logLevel);

unsigned char *rll_LoadFileData(const char *fileName, int *dataSize);

void rll_UnloadFileData(unsigned char *data);

bool rll_SaveFileData(const char *fileName, void *data, int dataSize);

bool rll_ExportDataAsCode(const unsigned char *data, int dataSize, const char *fileName);

char *rll_LoadFileText(const char *fileName);

void rll_UnloadFileText(char *text);

bool rll_SaveFileText(const char *fileName, char *text);

bool rll_FileExists(const char *fileName);

bool rll_DirectoryExists(const char *dirPath);

bool rll_IsFileExtension(const char *fileName, const char *ext);

int rll_GetFileLength(const char *fileName);

const char *rll_GetFileExtension(const char *fileName);

const char *rll_GetFileName(const char *filePath);

const char *rll_GetFileNameWithoutExt(const char *filePath);

const char *rll_GetDirectoryPath(const char *filePath);

const char *rll_GetPrevDirectoryPath(const char *dirPath);

const char *rll_GetWorkingDirectory(lua_State *L);

const char *rll_GetApplicationDirectory(lua_State *L);

int rll_MakeDirectory(const char *dirPath);

bool rll_ChangeDirectory(const char *dir);

bool rll_IsPathFile(const char *path);

bool rll_IsFileNameValid(const char *fileName);

bool rll_IsFileDropped(lua_State *L);

long rll_GetFileModTime(const char *fileName);

*/

static int rll_CompressData(lua_State *L);

static int rll_DecompressData(lua_State *L);

static int rll_EncodeDataBase64(lua_State *L);

static int rll_DecodeDataBase64(lua_State *L);

static int rll_ComputeCRC32(lua_State *L);

static int rll_ComputeMD5(lua_State *L);

static int rll_ComputeSHA1(lua_State *L);

static int rll_IsKeyPressed(lua_State *L);

static int rll_IsKeyPressedRepeat(lua_State *L);

static int rll_IsKeyDown(lua_State *L);

static int rll_IsKeyReleased(lua_State *L);

static int rll_IsKeyUp(lua_State *L);

static int rll_GetKeyPressed(lua_State *L);

static int rll_GetCharPressed(lua_State *L);

static int rll_SetExitKey(lua_State *L);

static int rll_IsMouseButtonPressed(lua_State *L);

static int rll_IsMouseButtonDown(lua_State *L);

static int rll_IsMouseButtonReleased(lua_State *L);

static int rll_IsMouseButtonUp(lua_State *L);

static int rll_GetMouseX(lua_State *L);

static int rll_GetMouseY(lua_State *L);

static int rll_GetMousePosition(lua_State *L);

static int rll_GetMouseDelta(lua_State *L);

static int rll_SetMousePosition(lua_State *L);

static int rll_SetMouseOffset(lua_State *L);

static int rll_SetMouseScale(lua_State *L);

static int rll_GetMouseWheelMove(lua_State *L);

static int rll_GetMouseWheelMoveV(lua_State *L);

static int rll_SetMouseCursor(lua_State *L);

#endif //__RAYLUAB_RCORE_H