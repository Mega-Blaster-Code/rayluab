#include "rayluab_rshapes.h"

Color globalColor = {255,255,255,255};

int f2c(lua_State *L, int idx) {
    lua_Number v = luaL_checknumber(L, idx);
    if (v < 0.0) v = 0.0;
    if (v > 1.0) v = 1.0;
    return (int)lround(v * 255.0);
}

 Color irll_GetColor(lua_State *L, int base){
    return (Color){
        f2c(L, base + 0),
        f2c(L, base + 1),
        f2c(L, base + 2),
        f2c(L, base + 3)
    };
}

 Color irll_GetColorTBL(lua_State *L, int idx){
    luaL_checktype(L, idx, LUA_TTABLE);
    Color c = {0, 0, 0, 255};
    unsigned char *out = (unsigned char *)&c;
    for (int i = 0; i < 4; i++){
        lua_geti(L, idx, i + 1);
        if (i == 3 && lua_isnil(L, -1)) {
            out[i] = 255;
        } else{
            out[i] = (unsigned char)f2c(L, -1);
        }
        lua_pop(L, 1);
    }
    return c;
}

 Rectangle irll_GetRectangleTBL(lua_State *L, int idx){
    luaL_checktype(L, idx, LUA_TTABLE);
    Rectangle r = {0.0f, 0.0f, 0.0f, 0.0f};
    float *out = (float *)&r;
    for (int i = 0; i < 4; i++){
        lua_geti(L, idx, i + 1);
        out[i] = (float)luaL_checknumber(L, -1);
        lua_pop(L, 1);
    }
    return r;
}

 Vector2 irll_GetVector2TBL(lua_State *L, int idx) {
    luaL_checktype(L, idx, LUA_TTABLE);
    Vector2 r = {0.0f, 0.0f};
    float *out = (float *)&r;
    for (int i = 0; i < 2; i++) {
        lua_geti(L, idx, i + 1);
        out[i] = (float)luaL_checknumber(L, -1);
        lua_pop(L, 1);
	}
    return r;
}

int rll_SetColor(lua_State *L){
	globalColor = irll_GetColor(L, 1);
	return 0;
}

int rll_ClearBackground(lua_State *L){
	Color c = irll_GetColor(L, 1);
	ClearBackground(c);
	return 0;
}

int rll_DrawPixel(lua_State *L){
	int x = (int)luaL_checkinteger(L, 1);
	int y = (int)luaL_checkinteger(L, 2);
	DrawPixel(x, y, globalColor);
	return 0;
}

int rll_DrawLine(lua_State *L){
	int sx = (int)luaL_checkinteger(L, 1);
	int sy = (int)luaL_checkinteger(L, 2);
	int ex = (int)luaL_checkinteger(L, 3);
	int ey = (int)luaL_checkinteger(L, 4);
	DrawLine(sx, sy, ex, ey, globalColor);
	return 0;
}

int rll_DrawLineEx(lua_State *L){
	float sx = (float)luaL_checknumber(L, 1);
	float sy = (float)luaL_checknumber(L, 2);
	float ex = (float)luaL_checknumber(L, 3);
	float ey = (float)luaL_checknumber(L, 4);
	int thick = (int)luaL_checkinteger(L, 5);
	DrawLineEx((Vector2){sx, sy}, (Vector2){ex, ey}, thick, globalColor);
	return 0;
}

int rll_DrawLineBezier(lua_State *L){
	float sx = (float)luaL_checknumber(L, 1);
	float sy = (float)luaL_checknumber(L, 2);
	float ex = (float)luaL_checknumber(L, 3);
	float ey = (float)luaL_checknumber(L, 4);
	int thick = (int)luaL_checkinteger(L, 5);
	DrawLineBezier((Vector2){sx, sy}, (Vector2){ex, ey}, thick, globalColor);
	return 0;
}

int rll_DrawCircle(lua_State *L){
	int x = (int)luaL_checkinteger(L, 1);
	int y = (int)luaL_checkinteger(L, 2);
	float radius = (float)luaL_checknumber(L, 3);
	DrawCircle(x, y, radius, globalColor);
	return 0;
}

int rll_DrawCircleSector(lua_State *L){
	float x = (float)luaL_checknumber(L, 1);
	float y = (float)luaL_checknumber(L, 2);
	float radius = (float)luaL_checknumber(L, 3);
	float startAngle = (float)luaL_checknumber(L, 4);
	float endAngle = (float)luaL_checknumber(L, 5);
	int segments = (int)luaL_checkinteger(L, 6);
	DrawCircleSector((Vector2){x, y}, radius, startAngle, endAngle, segments, globalColor);
	return 0;
}

int rll_DrawCircleSectorLines(lua_State *L){
	float x = (float)luaL_checknumber(L, 1);
	float y = (float)luaL_checknumber(L, 2);
	float radius = (float)luaL_checknumber(L, 3);
	float startAngle = (float)luaL_checknumber(L, 4);
	float endAngle = (float)luaL_checknumber(L, 5);
	int segments = (int)luaL_checkinteger(L, 6);
	DrawCircleSectorLines((Vector2){x, y}, radius, startAngle, endAngle, segments, globalColor);
	return 0;
}

int rll_DrawCircleGradient(lua_State *L){
	float x = (float)luaL_checknumber(L, 1);
	float y = (float)luaL_checknumber(L, 2);
	float radius = (float)luaL_checknumber(L, 3);
	Color _c1 = irll_GetColorTBL(L, 4);
	Color _c2 = irll_GetColorTBL(L, 5);

	DrawCircleGradient(x, y, radius, _c2, _c1);
	return 0;
}

int rll_DrawCircleLines(lua_State *L){
	int x = (int)luaL_checkinteger(L, 1);
	int y = (int)luaL_checkinteger(L, 2);
	float radius = (float)luaL_checknumber(L, 3);
	DrawCircleLines(x, y, radius, globalColor);
	return 0;
}

int rll_DrawEllipse(lua_State *L){
	int x = (int)luaL_checkinteger(L, 1);
	int y = (int)luaL_checkinteger(L, 2);
	float radiusH = (float)luaL_checknumber(L, 3);
	float radiusV = (float)luaL_checknumber(L, 3);
	DrawEllipse(x, y, radiusH, radiusV, globalColor);
	return 0;
}

int rll_DrawEllipseLines(lua_State *L){
	int x = (int)luaL_checkinteger(L, 1);
	int y = (int)luaL_checkinteger(L, 2);
	float radiusH = (float)luaL_checknumber(L, 3);
	float radiusV = (float)luaL_checknumber(L, 3);
	DrawEllipseLines(x, y, radiusH, radiusV, globalColor);
	return 0;
}

int rll_DrawRing(lua_State *L){
	float x = (float)luaL_checknumber(L, 1);
	float y = (float)luaL_checknumber(L, 2);
	float innerRadius = (float)luaL_checknumber(L, 3);
	float outerRadius = (float)luaL_checknumber(L, 4);

	float startAngle = (float)luaL_checknumber(L, 5);
	float endAngle = (float)luaL_checknumber(L, 6);

	int segments = (int)luaL_checkinteger(L, 7);
	DrawRing((Vector2){x, y}, innerRadius, outerRadius, startAngle, endAngle, segments, globalColor);
	return 0;
}

int rll_DrawRingLines(lua_State *L){
	float x = (float)luaL_checknumber(L, 1);
	float y = (float)luaL_checknumber(L, 2);
	float innerRadius = (float)luaL_checknumber(L, 3);
	float outerRadius = (float)luaL_checknumber(L, 4);

	float startAngle = (float)luaL_checknumber(L, 5);
	float endAngle = (float)luaL_checknumber(L, 6);

	int segments = (int)luaL_checkinteger(L, 7);
	DrawRingLines((Vector2){x, y}, innerRadius, outerRadius, startAngle, endAngle, segments, globalColor);
	return 0;
}

int rll_DrawRectangle(lua_State *L){
	int x = (int)luaL_checkinteger(L, 1);
	int y = (int)luaL_checkinteger(L, 2);
	int w = (int)luaL_checkinteger(L, 3);
	int h = (int)luaL_checkinteger(L, 4);
	DrawRectangle(x, y, w, h, globalColor);
	return 0;
}

int rll_DrawRectanglePro(lua_State *L){
	float x = (float)luaL_checknumber(L, 1);
	float y = (float)luaL_checknumber(L, 2);
	float w = (float)luaL_checknumber(L, 3);
	float h = (float)luaL_checknumber(L, 4);
	float originX = (float)luaL_checknumber(L, 5);
	float originY = (float)luaL_checknumber(L, 6);
	float angle = (float)luaL_checknumber(L, 7) * (180.0f / PI);
	DrawRectanglePro((Rectangle){x, y, w, h}, (Vector2){originX, originY}, angle, globalColor);
	return 0;
}

int rll_DrawRectangleGradientV(lua_State *L){
	int x = (int)luaL_checkinteger(L, 1);
	int y = (int)luaL_checkinteger(L, 2);
	int w = (int)luaL_checkinteger(L, 3);
	int h = (int)luaL_checkinteger(L, 4);

	Color _c1 = irll_GetColorTBL(L, 5);
	Color _c2 = irll_GetColorTBL(L, 6);

	DrawRectangleGradientV(x, y, w, h, _c1, _c2);
	return 0;
}

int rll_DrawRectangleGradientH(lua_State *L){
	int x = (int)luaL_checkinteger(L, 1);
	int y = (int)luaL_checkinteger(L, 2);
	int w = (int)luaL_checkinteger(L, 3);
	int h = (int)luaL_checkinteger(L, 4);

	Color _c1 = irll_GetColorTBL(L, 5);
	Color _c2 = irll_GetColorTBL(L, 6);

	DrawRectangleGradientH(x, y, w, h, _c1, _c2);
	return 0;
}

int rll_DrawRectangleGradientEx(lua_State *L){
	float x = (float)luaL_checknumber(L, 1);
	float y = (float)luaL_checknumber(L, 2);
	float w = (float)luaL_checknumber(L, 3);
	float h = (float)luaL_checknumber(L, 4);

	Color _c1 = irll_GetColorTBL(L, 5);
	Color _c2 = irll_GetColorTBL(L, 6);
	Color _c3 = irll_GetColorTBL(L, 7);
	Color _c4 = irll_GetColorTBL(L, 8);

	DrawRectangleGradientEx((Rectangle){x, y, w, h}, _c1, _c2, _c3, _c4);
	return 0;
}

int rll_DrawRectangleLines(lua_State *L){
	int x = (int)luaL_checkinteger(L, 1);
	int y = (int)luaL_checkinteger(L, 2);
	int w = (int)luaL_checkinteger(L, 3);
	int h = (int)luaL_checkinteger(L, 4);
	DrawRectangleLines(x, y, w, h, globalColor);
	return 0;
}

int rll_DrawRectangleLinesEx(lua_State *L){
	float x = (float)luaL_checknumber(L, 1);
	float y = (float)luaL_checknumber(L, 2);
	float w = (float)luaL_checknumber(L, 3);
	float h = (float)luaL_checknumber(L, 4);
	int thick = (int)luaL_checkinteger(L, 5);
	DrawRectangleLinesEx((Rectangle){x, y, w, h}, thick, globalColor);
	return 0;
}

int rll_DrawRectangleRounded(lua_State *L){
	float x = (float)luaL_checknumber(L, 1);
	float y = (float)luaL_checknumber(L, 2);
	float w = (float)luaL_checknumber(L, 3);
	float h = (float)luaL_checknumber(L, 4);
	float roundness = (float)luaL_checknumber(L, 5);
	int segments = (int)luaL_checkinteger(L, 6);
	DrawRectangleRounded((Rectangle){x, y, w, h}, roundness, segments, globalColor);
	return 0;
}

int rll_DrawRectangleRoundedLines(lua_State *L){
	float x = (float)luaL_checknumber(L, 1);
	float y = (float)luaL_checknumber(L, 2);
	float w = (float)luaL_checknumber(L, 3);
	float h = (float)luaL_checknumber(L, 4);
	float roundness = (float)luaL_checknumber(L, 5);
	int segments = (int)luaL_checkinteger(L, 6);
	DrawRectangleRoundedLines((Rectangle){x, y, w, h}, roundness, segments, globalColor);
	return 0;
}

int rll_DrawRectangleRoundedLinesEx(lua_State *L){
	float x = (float)luaL_checknumber(L, 1);
	float y = (float)luaL_checknumber(L, 2);
	float w = (float)luaL_checknumber(L, 3);
	float h = (float)luaL_checknumber(L, 4);
	float roundness = (float)luaL_checknumber(L, 5);
	int segments = (int)luaL_checkinteger(L, 6);
	int thick = (int)luaL_checkinteger(L, 7);
	DrawRectangleRoundedLinesEx((Rectangle){x, y, w, h}, roundness, segments, thick, globalColor);
	return 0;
}

int rll_DrawTriangle(lua_State *L){
	float x1 = (float)luaL_checknumber(L, 1);
	float y1 = (float)luaL_checknumber(L, 2);
	float x2 = (float)luaL_checknumber(L, 3);
	float y2 = (float)luaL_checknumber(L, 4);
	float x3 = (float)luaL_checknumber(L, 5);
	float y3 = (float)luaL_checknumber(L, 6);
	DrawTriangle((Vector2){x1, y1}, (Vector2){x2, y2}, (Vector2){x3, y3}, globalColor);
	return 0;
}

int rll_DrawTriangleLines(lua_State *L){
	float x1 = (float)luaL_checknumber(L, 1);
	float y1 = (float)luaL_checknumber(L, 2);
	float x2 = (float)luaL_checknumber(L, 3);
	float y2 = (float)luaL_checknumber(L, 4);
	float x3 = (float)luaL_checknumber(L, 5);
	float y3 = (float)luaL_checknumber(L, 6);
	DrawTriangleLines((Vector2){x1, y1}, (Vector2){x2, y2}, (Vector2){x3, y3}, globalColor);
	return 0;
}

int rll_DrawPoly(lua_State *L){
	float x = (float)luaL_checknumber(L, 1);
	float y = (float)luaL_checknumber(L, 2);

	int sides = (int)luaL_checkinteger(L, 3);

	float radius = (float)luaL_checknumber(L, 4);

	float angle = (float)luaL_checknumber(L, 5) * (180.0f / PI);
	
	DrawPoly((Vector2){x, y}, sides, radius, angle, globalColor);
	return 0;
}

int rll_DrawPolyLines(lua_State *L){
	float x = (float)luaL_checknumber(L, 1);
	float y = (float)luaL_checknumber(L, 2);

	int sides = (int)luaL_checkinteger(L, 3);

	float radius = (float)luaL_checknumber(L, 4);

	float angle = (float)luaL_checknumber(L, 5) * (180.0f / PI);
	
	DrawPolyLines((Vector2){x, y}, sides, radius, angle, globalColor);
	return 0;
}

int rll_DrawPolyLinesEx(lua_State *L){
	float x = (float)luaL_checknumber(L, 1);
	float y = (float)luaL_checknumber(L, 2);

	int sides = (int)luaL_checkinteger(L, 3);

	float radius = (float)luaL_checknumber(L, 4);

	float angle = (float)luaL_checknumber(L, 5) * (180.0f / PI);

	float thick = (float)luaL_checknumber(L, 5) * (180.0f / PI);
	
	DrawPolyLinesEx((Vector2){x, y}, sides, radius, angle, thick, globalColor);
	return 0;
}

int rll_CheckCollisionRecs(lua_State *L){
	Rectangle rec_1 = irll_GetRectangleTBL(L, 1);
	Rectangle rec_2 = irll_GetRectangleTBL(L, 2);
	int b = CheckCollisionRecs(rec_1, rec_2);
	lua_pushboolean(L, b);
	return 1;
}

int rll_CheckCollisionCircles(lua_State *L){
	Vector2 vec_1 = irll_GetVector2TBL(L, 1);
	float radius1 = (float)luaL_checknumber(L, 2);
	Vector2 vec_2 = irll_GetVector2TBL(L, 3);
	float radius2 = (float)luaL_checknumber(L, 4);
	int b = CheckCollisionCircles(vec_1, radius1, vec_2, radius2);
	lua_pushboolean(L, b);
	return 1;
}

int rll_CheckCollisionCircleRec(lua_State *L){
	Vector2 vec = irll_GetVector2TBL(L, 1);
	float radius = (float)luaL_checknumber(L, 2);
	Rectangle rec = irll_GetRectangleTBL(L, 3);
	int b = CheckCollisionCircleRec(vec, radius, rec);
	lua_pushboolean(L, b);
	return 1;
}

int rll_CheckCollisionCircleLine(lua_State *L){
	Vector2 vec_1 = irll_GetVector2TBL(L, 1);
	float radius = (float)luaL_checknumber(L, 2);
	Vector2 vec_2 = irll_GetVector2TBL(L, 3);
	Vector2 vec_3 = irll_GetVector2TBL(L, 4);
	int b = CheckCollisionCircleLine(vec_1, radius, vec_2, vec_3);
	lua_pushboolean(L, b);
	return 1;
}

int rll_CheckCollisionPointRec(lua_State *L){
	Vector2 vec = irll_GetVector2TBL(L, 1);
	Rectangle rec = irll_GetRectangleTBL(L, 2);
	int b = CheckCollisionPointRec(vec, rec);
	lua_pushboolean(L, b);
	return 1;
}

int rll_CheckCollisionPointCircle(lua_State *L){
	Vector2 vec = irll_GetVector2TBL(L, 1);
	Vector2 center = irll_GetVector2TBL(L, 2);
	float radius = (float)luaL_checknumber(L, 3);

	int b = CheckCollisionPointCircle(vec, center, radius);
	lua_pushboolean(L, b);
	return 1;
}

int rll_CheckCollisionPointTriangle(lua_State *L){
	Vector2 vec = irll_GetVector2TBL(L, 1);
	Vector2 p1 = irll_GetVector2TBL(L, 2);
	Vector2 p2 = irll_GetVector2TBL(L, 3);
	Vector2 p3 = irll_GetVector2TBL(L, 4);

	int b = CheckCollisionPointTriangle(vec, p1, p2, p3);
	lua_pushboolean(L, b);
	return 1;
}

int rll_CheckCollisionPointLine(lua_State *L){
	Vector2 point = irll_GetVector2TBL(L, 1);
	Vector2 p1 = irll_GetVector2TBL(L, 2);
	Vector2 p2 = irll_GetVector2TBL(L, 3);
	int t = (int)luaL_checkinteger(L, 4);

	int b = CheckCollisionPointLine(point, p1, p2, t);
	lua_pushboolean(L, b);
	return 1;
}

int rll_CheckCollisionLines(lua_State *L){
	Vector2 collisionPoint;
	Vector2 start1 = irll_GetVector2TBL(L, 1);
	Vector2 end1 = irll_GetVector2TBL(L, 2);
	Vector2 start2 = irll_GetVector2TBL(L, 3);
	Vector2 end2 = irll_GetVector2TBL(L, 4);

	int b = CheckCollisionLines(start1, end1, start2, end2, &collisionPoint);
	if(b){
		lua_pushnumber(L, collisionPoint.x);
		lua_pushnumber(L, collisionPoint.y);
		return 2;
	}
	
	return 0;
}

int rll_GetCollisionRec(lua_State *L){
	Rectangle rec_1 = irll_GetRectangleTBL(L, 1);
	Rectangle rec_2 = irll_GetRectangleTBL(L, 2);

	Rectangle rec_coll = GetCollisionRec(rec_1, rec_2);
	
	lua_pushnumber(L, rec_coll.x);
	lua_pushnumber(L, rec_coll.y);
	lua_pushnumber(L, rec_coll.width);
	lua_pushnumber(L, rec_coll.height);
	
	return 4;
}
