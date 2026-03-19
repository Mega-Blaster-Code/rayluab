#ifndef __RAYLUAB_RSHAPES_H
#define __RAYLUAB_RSHAPES_H

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
#include <math.h>

int f2c(lua_State *L, int idx);

Color irll_GetColor(lua_State *L, int base);

Color irll_GetColorTBL(lua_State *L, int idx);

Rectangle irll_GetRectangleTBL(lua_State *L, int idx);

Vector2 irll_GetVector2TBL(lua_State *L, int idx);

int rll_SetColor(lua_State *L);

int rll_ClearBackground(lua_State *L);

int rll_DrawPixel(lua_State *L);

int rll_DrawLine(lua_State *L);

int rll_DrawLineEx(lua_State *L);

int rll_DrawLineBezier(lua_State *L);

int rll_DrawCircle(lua_State *L);

int rll_DrawCircleSector(lua_State *L);

int rll_DrawCircleSectorLines(lua_State *L);

int rll_DrawCircleGradient(lua_State *L);

int rll_DrawCircleLines(lua_State *L);

int rll_DrawEllipse(lua_State *L);

int rll_DrawEllipseLines(lua_State *L);

int rll_DrawRing(lua_State *L);

int rll_DrawRingLines(lua_State *L);

int rll_DrawRectangle(lua_State *L);

int rll_DrawRectanglePro(lua_State *L);

int rll_DrawRectangleGradientV(lua_State *L);

int rll_DrawRectangleGradientH(lua_State *L);

int rll_DrawRectangleGradientEx(lua_State *L);

int rll_DrawRectangleLines(lua_State *L);

int rll_DrawRectangleLinesEx(lua_State *L);

int rll_DrawRectangleRounded(lua_State *L);

int rll_DrawRectangleRoundedLines(lua_State *L);

int rll_DrawRectangleRoundedLinesEx(lua_State *L);

int rll_DrawTriangle(lua_State *L);

int rll_DrawTriangleLines(lua_State *L);

int rll_DrawPoly(lua_State *L);

int rll_DrawPolyLines(lua_State *L);

int rll_DrawPolyLinesEx(lua_State *L);

int rll_CheckCollisionRecs(lua_State *L);

int rll_CheckCollisionCircles(lua_State *L);

int rll_CheckCollisionCircleRec(lua_State *L);

int rll_CheckCollisionCircleLine(lua_State *L);

int rll_CheckCollisionPointRec(lua_State *L);

int rll_CheckCollisionPointCircle(lua_State *L);

int rll_CheckCollisionPointTriangle(lua_State *L);

int rll_CheckCollisionPointLine(lua_State *L);

int rll_CheckCollisionLines(lua_State *L);

int rll_GetCollisionRec(lua_State *L);

#endif //__RAYLUAB_RSHAPES_H