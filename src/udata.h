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

typedef struct {
    int type;
    void *data;
} uni_userdata;

#define UNI_MT "UNI_UD"

static void create_mt(lua_State *L){
    if(luaL_newmetatable(L, UNI_MT)){

    }
    lua_pop(L, 1);
}

static uni_userdata *rll_newuserdata(lua_State *L, int type, void *data){
    uni_userdata *ud = (uni_userdata *)lua_newuserdata(L, sizeof(uni_userdata));

    ud->type = type;
    ud->data = data;

    luaL_getmetatable(L, UNI_MT);
    lua_setmetatable(L, -2);

    return ud;
}

static uni_userdata *rll_getuserdata(lua_State *L, int idx, int type){
    uni_userdata *ud = (uni_userdata *)luaL_checkudata(L, idx, UNI_MT);

    if(ud->type != type){
        luaL_error(L, "bad userdata expected [%d] got [%d]", type, ud->type);
    }

    return ud;
}