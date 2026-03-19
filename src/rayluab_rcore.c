#include "rayluab_rcore.h"

int rll_InitWindow(lua_State *L){
	lua_Integer width = luaL_checkinteger(L, 1);
	lua_Integer height = luaL_checkinteger(L, 2);
	size_t title_size;
	const char* title = luaL_checklstring(L, 3, &title_size);
	InitWindow(width, height, title);
	return 0;
}

int rll_CloseWindow(lua_State *L){
	CloseWindow();
	return 0;
}

int rll_WindowShouldClose(lua_State *L){
	int _b = WindowShouldClose();
	lua_pushboolean(L, _b);
	return 1;
}

int rll_IsWindowReady(lua_State *L){
	int _b = IsWindowReady();
	lua_pushboolean(L, _b);
	return 1;
}

int rll_IsWindowFullscreen(lua_State *L){
	int _b = IsWindowFullscreen();
	lua_pushboolean(L, _b);
	return 1;
}

int rll_IsWindowHidden(lua_State *L){
	int _b = IsWindowHidden();
	lua_pushboolean(L, _b);
	return 1;
}

int rll_IsWindowMinimized(lua_State *L){
	int _b = IsWindowMinimized();
	lua_pushboolean(L, _b);
	return 1;
}

int rll_IsWindowMaximized(lua_State *L){
	int _b = IsWindowMaximized();
	lua_pushboolean(L, _b);
	return 1;
}

int rll_IsWindowFocused(lua_State *L){
	int _b = IsWindowFocused();
	lua_pushboolean(L, _b);
	return 1;
}

int rll_IsWindowResized(lua_State *L){
	int _b = IsWindowResized();
	lua_pushboolean(L, _b);
	return 1;
}

int rll_IsWindowState(lua_State *L){
	unsigned int flag = (unsigned int)luaL_checkinteger(L, 1);
	int _b = IsWindowState(flag);
	lua_pushboolean(L, _b);
	return 1;
}

int rll_SetWindowState(lua_State *L){
	unsigned int flags = (unsigned int)luaL_checkinteger(L, 1);
	SetWindowState(flags);
	return 0;
}

int rll_ClearWindowState(lua_State *L){
	unsigned int flags = (unsigned int)luaL_checkinteger(L, 1);
	SetWindowState(flags);
	return 0;
}

int rll_ToggleFullscreen(lua_State *L){
	ToggleFullscreen();
	return 0;
}

int rll_ToggleBorderlessWindowed(lua_State *L){
	ToggleBorderlessWindowed();
	return 0;
}

int rll_MaximizeWindow(lua_State *L){
	MaximizeWindow();
	return 0;
}

int rll_MinimizeWindow(lua_State *L){
	MinimizeWindow();
	return 0;
}

int rll_RestoreWindow(lua_State *L){
	RestoreWindow();
	return 0;
}

int rll_SetWindowIcon(lua_State *L){
	Image *image = (Image*)rll_getuserdata(L, -1, IMAGE_USERDATA);
	SetWindowIcon(*image);
	return 0;
}

int rll_SetWindowTitle(lua_State *L){
	size_t title_size = 0;
	const char* title = luaL_checklstring(L, 1, &title_size);
	SetWindowTitle(title);
	return 0;
}

int rll_SetWindowPosition(lua_State *L){
	int x = (int)luaL_checkinteger(L, 1);
	int y = (int)luaL_checkinteger(L, 2);
	SetWindowPosition(x, y);
	return 0;
}

int rll_SetWindowMonitor(lua_State *L){
	int monitor = (int)luaL_checkinteger(L, 1);
	SetWindowMonitor(monitor);
	return 0;
}

int rll_SetWindowMinSize(lua_State *L){
	int width = (int)luaL_checkinteger(L, 1);
	int height = (int)luaL_checkinteger(L, 2);
	SetWindowMinSize(width, height);
	return 0;
}

int rll_SetWindowMaxSize(lua_State *L){
	int width = (int)luaL_checkinteger(L, 1);
	int height = (int)luaL_checkinteger(L, 2);
	SetWindowMaxSize(width, height);
	return 0;
}

int rll_SetWindowSize(lua_State *L){
	int width = (int)luaL_checkinteger(L, 1);
	int height = (int)luaL_checkinteger(L, 2);
	SetWindowSize(width, height);
	return 0;
}

int rll_SetWindowOpacity(lua_State *L){
	float opacity = (float)luaL_checknumber(L, 1);
	SetWindowOpacity(opacity);
	return 0;
}

int rll_SetWindowFocused(lua_State *L){
	SetWindowFocused();
	return 0;
}

int rll_GetWindowHandle(lua_State *L){
	void* handler = GetWindowHandle();
	rll_newSelfUserdata(L, WINDOWHANDLER_USERDATA, handler);
	return 1;
}

int rll_GetScreenWidth(lua_State *L){
	int width = GetScreenWidth();
	lua_pushinteger(L, width);
	return 1;
}

int rll_GetScreenHeight(lua_State *L){
	int height = GetScreenHeight();
	lua_pushinteger(L, height);
	return 1;
}

int rll_GetRenderWidth(lua_State *L){
	int height = GetRenderWidth();
	lua_pushinteger(L, height);
	return 1;
}

int rll_GetRenderHeight(lua_State *L){
	int height = GetRenderWidth();
	lua_pushinteger(L, height);
	return 1;
}

int rll_GetMonitorCount(lua_State *L){
	int count = GetMonitorCount();
	lua_pushinteger(L, count);
	return 1;
}

int rll_GetCurrentMonitor(lua_State *L){
	int current = GetCurrentMonitor();
	lua_pushinteger(L, current);
	return 1;
}

int rll_GetMonitorPosition(lua_State *L){
	int monitor = (int)luaL_checkinteger(L, 1);
	Vector2 position = GetMonitorPosition(monitor);
	lua_pushinteger(L, position.x);
	lua_pushinteger(L, position.y);
	return 2;
}

int rll_GetMonitorWidth(lua_State *L){
	int monitor = (int)luaL_checkinteger(L, 1);
	int width = GetMonitorWidth(monitor);
	lua_pushinteger(L, width);
	return 1;
}

int rll_GetMonitorHeight(lua_State *L){
	int monitor = (int)luaL_checkinteger(L, 1);
	int height = GetMonitorHeight(monitor);
	lua_pushinteger(L, height);
	return 1;
}

int rll_GetMonitorPhysicalWidth(lua_State *L){
	int monitor = (int)luaL_checkinteger(L, 1);
	int width = GetMonitorPhysicalWidth(monitor);
	lua_pushinteger(L, width);
	return 1;
}

int rll_GetMonitorPhysicalHeight(lua_State *L){
	int monitor = (int)luaL_checkinteger(L, 1);
	int width = GetMonitorPhysicalHeight(monitor);
	lua_pushinteger(L, width);
	return 1;
}

int rll_GetMonitorRefreshRate(lua_State *L){
	int monitor = (int)luaL_checkinteger(L, 1);
	int rate = GetMonitorRefreshRate(monitor);
	lua_pushinteger(L, rate);
	return 1;
}

int rll_GetWindowPosition(lua_State *L){
	Vector2 position = GetWindowPosition();
	lua_pushinteger(L, position.x);
	lua_pushinteger(L, position.y);
	return 2;
}

int rll_GetWindowScaleDPI(lua_State *L){
	Vector2 scale = GetWindowScaleDPI();
	lua_pushinteger(L, scale.x);
	lua_pushinteger(L, scale.y);
	return 2;
}

int rll_GetMonitorName(lua_State *L){
	int monitor = (int)luaL_checkinteger(L, 1);
	size_t name_size = 0;
	const char* name = GetMonitorName(monitor);
	lua_pushstring(L, name);
	return 1;
}

int rll_SetClipboardText(lua_State *L){
	size_t name_size;
	const char *text = luaL_checklstring(L, 1, &name_size);
	SetClipboardText(text);
	return 0;
}

int rll_GetClipboardText(lua_State *L){
	const char *text = GetClipboardText();
	lua_pushstring(L, text);
	return 1;
}

int rll_EnableEventWaiting(lua_State *L){
	EnableEventWaiting();
	return 0;
}

int rll_DisableEventWaiting(lua_State *L){
	DisableEventWaiting();
	return 0;
}

int rll_ShowCursor(lua_State *L){
	ShowCursor();
	return 0;
}

int rll_HideCursor(lua_State *L){
	HideCursor();
	return 0;
}

int rll_IsCursorHidden(lua_State *L){
	int _b = IsCursorHidden();
	lua_pushboolean(L, _b);
	return 1;
}

int rll_EnableCursor(lua_State *L){
	EnableCursor();
	return 0;
}

int rll_DisableCursor(lua_State *L){
	DisableCursor();
	return 0;
}

int rll_IsCursorOnScreen(lua_State *L){
	int _b = IsCursorOnScreen();
	lua_pushboolean(L, _b);
	return 1;
}

int rll_BeginDrawing(lua_State *L){
	BeginDrawing();
	return 0;
}

int rll_EndDrawing(lua_State *L){
	EndDrawing();
	return 0;
}

int rll_BeginScissorMode(lua_State *L){
	int x = (int)luaL_checkinteger(L, 1);
	int y = (int)luaL_checkinteger(L, 2);
	int width = (int)luaL_checkinteger(L, 3);
	int height = (int)luaL_checkinteger(L, 4);
	BeginScissorMode(x, y, width, height);
	return 0;
}

int rll_EndScissorMode(lua_State *L){
	EndScissorMode();
	return 0;
}

int rll_SetTargetFPS(lua_State *L){
	int fps = (int)luaL_checkinteger(L, 1);
	SetTargetFPS(fps);
	return 0;
}

int rll_GetFrameTime(lua_State *L){
	lua_Number ft = (lua_Number)GetFrameTime();
	lua_pushnumber(L, ft);
	return 1;
}

int rll_GetTime(lua_State *L){
	lua_Number t = (lua_Number)GetTime();
	lua_pushnumber(L, t);
	return 1;
}

int rll_GetFPS(lua_State *L){
	lua_Integer fps = (lua_Integer)GetFPS();
	lua_pushinteger(L, fps);
	return 1;
}

int rll_SwapScreenBuffer(lua_State *L){
	SwapScreenBuffer();
	return 0;
}

int rll_PollInputEvents(lua_State *L){
	PollInputEvents();
	return 0;
}

int rll_WaitTime(lua_State *L){
	double s = (double)luaL_checknumber(L, 1);
	WaitTime(s);
	return 0;
}

int rll_SetRandomSeed(lua_State *L){
	unsigned int seed = (unsigned int)luaL_checkinteger(L, 1);
	SetRandomSeed(seed);
	return 0;
}

int rll_GetRandomValue(lua_State *L){
	int min = (unsigned int)luaL_checkinteger(L, 1);
	int max = (unsigned int)luaL_checkinteger(L, 2);
	int r = GetRandomValue(min, max);
	lua_pushinteger(L, r);
	return 1;
}

int rll_TakeScreenshot(lua_State *L){
	size_t size;
	const char *fileName = luaL_checklstring(L, 1, &size);
	return 0;
}

int rll_SetConfigFlags(lua_State *L){
	unsigned int flags = (unsigned int)luaL_checkinteger(L, 1);
	SetConfigFlags(flags);
	return 0;
}

int rll_OpenURL(lua_State *L){
	size_t size;
	const char *url = luaL_checklstring(L, 1, &size);
	OpenURL(url);
	return 0;
}

int rll_TraceLog(lua_State *L){
	int logLevel = (int)luaL_checkinteger(L, 1);
	size_t size;
	const char* text = luaL_checklstring(L, 1, &size);
	TraceLog(logLevel, text);
	return 0;
}

int rll_SetTraceLogLevel(lua_State *L){
	int logLevel = (int)luaL_checkinteger(L, 1);
	SetTraceLogLevel(logLevel);
	return 0;
}

int rll_CompressData(lua_State *L){
	size_t size = 0;
	unsigned const char *data = (unsigned const char*)luaL_checklstring(L, 1, &size);
	int compDataSize = 0;
	unsigned const char *str = CompressData(data, size, &compDataSize);
	lua_pushlstring(L, (char*)str, compDataSize);
	return 1;
}

int rll_DecompressData(lua_State *L){
	size_t size = 0;
	const unsigned char *data = (unsigned const char*)luaL_checklstring(L, 1, &size);
	int outputDataSize = 0;
	unsigned const char *str = DecompressData(data, size, &outputDataSize);
	lua_pushlstring(L, (char *)str, outputDataSize);
	return 1;
}

int rll_EncodeDataBase64(lua_State *L){
	size_t size = 0;
	const unsigned char *data = (unsigned const char*)luaL_checklstring(L, 1, &size);
	int compDataSize = 0;
	const char *str = EncodeDataBase64(data, size, &compDataSize);
	lua_pushlstring(L, (char*)str, compDataSize);
	return 1;
}

int rll_DecodeDataBase64(lua_State *L){
	size_t size = 0;
	char *data = (char*)luaL_checklstring(L, 1, &size);
	int outputDataSize = 0;
	char *str = (char*)DecodeDataBase64((unsigned char*)data, &outputDataSize);
	lua_pushlstring(L, str, outputDataSize);
	return 1;
}

int rll_ComputeCRC32(lua_State *L){
	size_t size = 0;
	char *data = (char*)luaL_checklstring(L, 1, &size);
	lua_Integer r = (lua_Integer)ComputeCRC32((unsigned char*)data, size);
	lua_pushinteger(L, r);
	return 1;
}

int rll_ComputeMD5(lua_State *L){
	size_t size = 0;
	char *data = (char*)luaL_checklstring(L, 1, &size);
	lua_Integer r = (lua_Integer)ComputeMD5((unsigned char*)data, size);
	lua_pushinteger(L, r);
	return 1;
}

int rll_ComputeSHA1(lua_State *L){
	size_t size = 0;
	char *data = (char*)luaL_checklstring(L, 1, &size);
	lua_Integer r = (lua_Integer)ComputeSHA1((unsigned char*)data, size);
	lua_pushinteger(L, r);
	return 1;
}

int rll_IsKeyPressed(lua_State *L){
	int key = (int)luaL_checkinteger(L, 1);
	int r = IsKeyPressed(key);
	lua_pushboolean(L, r);
	return 1;
}

int rll_IsKeyPressedRepeat(lua_State *L){
	int key = (int)luaL_checkinteger(L, 1);
	int r = IsKeyPressedRepeat(key);
	lua_pushboolean(L, r);
	return 1;
}

int rll_IsKeyDown(lua_State *L){
	int key = (int)luaL_checkinteger(L, 1);
	int r = IsKeyDown(key);
	lua_pushboolean(L, r);
	return 1;
}

int rll_IsKeyReleased(lua_State *L){
	int key = (int)luaL_checkinteger(L, 1);
	int r = IsKeyReleased(key);
	lua_pushboolean(L, r);
	return 1;
}

int rll_IsKeyUp(lua_State *L){
	int key = (int)luaL_checkinteger(L, 1);
	int r = IsKeyUp(key);
	lua_pushboolean(L, r);
	return 1;
}

int rll_GetKeyPressed(lua_State *L){
	int r = GetKeyPressed();
	lua_pushinteger(L, r);
	return 1;
}

int rll_GetCharPressed(lua_State *L){
	int r = GetCharPressed();
	lua_pushinteger(L, r);
	return 1;
}

int rll_SetExitKey(lua_State *L){
	int key = (int)luaL_checkinteger(L, 1);
	SetExitKey(key);
	return 0;
}

int rll_IsMouseButtonPressed(lua_State *L){
	int button = (int)luaL_checkinteger(L, 1);
	int r = IsMouseButtonPressed(button);
	lua_pushinteger(L, r);
	return 1;
}

int rll_IsMouseButtonDown(lua_State *L){
	int button = (int)luaL_checkinteger(L, 1);
	int r = IsMouseButtonDown(button);
	lua_pushinteger(L, r);
	return 1;
}

int rll_IsMouseButtonReleased(lua_State *L){
	int button = (int)luaL_checkinteger(L, 1);
	int r = IsMouseButtonReleased(button);
	lua_pushinteger(L, r);
	return 1;
}

int rll_IsMouseButtonUp(lua_State *L){
	int button = (int)luaL_checkinteger(L, 1);
	int r = IsMouseButtonUp(button);
	lua_pushinteger(L, r);
	return 1;
}

int rll_GetMouseX(lua_State *L){
	lua_Integer posx = (lua_Integer)GetMouseX();
	lua_pushinteger(L, posx);
	return 1;
}

int rll_GetMouseY(lua_State *L){
	lua_Integer posy = (lua_Integer)GetMouseY();
	lua_pushinteger(L, posy);
	return 1;
}

int rll_GetMousePosition(lua_State *L){
	Vector2 pos = GetMousePosition();
	lua_Integer x = (lua_Integer)pos.x;
	lua_Integer y = (lua_Integer)pos.y;
	lua_pushinteger(L, x);
	lua_pushinteger(L, y);
	return 2;
}

int rll_GetMouseDelta(lua_State *L){
	Vector2 pos = GetMouseDelta();
	lua_Number dx = (lua_Number)pos.x;
	lua_Number dy = (lua_Number)pos.y;
	lua_pushnumber(L, dx);
	lua_pushnumber(L, dy);
	return 2;
}

int rll_SetMousePosition(lua_State *L){
	int x = (int)luaL_checkinteger(L, 1);
	int y = (int)luaL_checkinteger(L, 2);
	SetMousePosition(x, y);
	return 0;
}

int rll_SetMouseOffset(lua_State *L){
	int x = (int)luaL_checkinteger(L, 1);
	int y = (int)luaL_checkinteger(L, 2);
	SetMouseOffset(x, y);
	return 0;
}
int rll_SetMouseScale(lua_State *L){
	float x = (float)luaL_checknumber(L, 1);
	float y = (float)luaL_checknumber(L, 2);
	SetMouseScale(x, y);
	return 0;
}

int rll_GetMouseWheelMove(lua_State *L){
	float v = GetMouseWheelMove();
	lua_pushnumber(L, v);
	return 1;
}

int rll_GetMouseWheelMoveV(lua_State *L){
	Vector2 pos = GetMouseWheelMoveV();
	lua_Number dx = (lua_Number)pos.x;
	lua_Number dy = (lua_Number)pos.y;
	lua_pushinteger(L, dx);
	lua_pushinteger(L, dy);
	return 2;
}

int rll_SetMouseCursor(lua_State *L){
	int cursor = (int)luaL_checkinteger(L, 1);
	SetMouseCursor(cursor);
	return 0;
}