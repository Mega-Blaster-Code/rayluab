#include "udata.h"

void rll_createMT(lua_State *L){
    luaL_newmetatable(L, UNI_MT);
    lua_pop(L, 1);
}

uni_userdata *rll_newuserdata(lua_State *L, int type, void *data, size_t data_size){
    uni_userdata *ud = (uni_userdata *)lua_newuserdata(L, sizeof(uni_userdata) + data_size);

    ud->type = type;
    ud->data = (void*)(ud + 1);

	memcpy(ud->data, data, data_size);

    luaL_getmetatable(L, UNI_MT);
    lua_setmetatable(L, -2);

    return ud;
}

uni_userdata *rll_newSelfUserdata(lua_State *L, int type, void *data){
    uni_userdata *ud = (uni_userdata *)lua_newuserdata(L, sizeof(uni_userdata));

    ud->type = type;
    ud->data = data;

    luaL_getmetatable(L, UNI_MT);
    lua_setmetatable(L, -2);

    return ud;
}

uni_userdata *rll_getuserdata(lua_State *L, int idx, int type){
    uni_userdata *ud = (uni_userdata *)luaL_checkudata(L, idx, UNI_MT);

    if(ud->type != type){
        luaL_error(L, "bad userdata expected [%d] got [%d]", type, ud->type);
    }

    return ud;
}

void *rll_getuserdata_data(lua_State *L, int idx, int type){
    uni_userdata *ud = (uni_userdata *)luaL_checkudata(L, idx, UNI_MT);

    if(ud->type != type){
        luaL_error(L, "bad userdata expected [%d] got [%d]", type, ud->type);
    }

    return ud->data;
}