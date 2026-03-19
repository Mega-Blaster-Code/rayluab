#ifndef RAYLUAB_UDATA_H
#define RAYLUAB_UDATA_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <lua5.4/lua.h>
#include <lua5.4/lauxlib.h>
#include <time.h>
#include "./../raylib/raylib.h"
#include "safema.h"

#define WINDOWHANDLER_USERDATA 0
#define IMAGE_USERDATA 1
#define WAVE_USERDATA 2
#define SOUND_USERDATA 3

typedef struct {
    int type;
    void *data;
} uni_userdata;

#define UNI_MT "UNI_UD"

void rll_createMT(lua_State *L);

uni_userdata *rll_newuserdata(lua_State *L, int type, void *data, size_t data_size);
uni_userdata *rll_newSelfUserdata(lua_State *L, int type, void *data);
uni_userdata *rll_getuserdata(lua_State *L, int idx, int type);
void *rll_getuserdata_data(lua_State *L, int idx, int type);

#endif //RAYLUAB_UDATA_H