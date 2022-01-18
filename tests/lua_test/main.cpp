//#include "include/lua.hpp"
//#include "include/lualib.h"
#include <lua.hpp>
#include <lualib.h>
#include <iostream>
#include <string.h>
#include <stdio.h>

int getIntField(lua_State* L, const char* key)
{
    lua_pushstring(L, key);
    lua_gettable(L, -2);
 
    int result = (int)lua_tonumber(L, -1);
    lua_pop(L, 1);
    return result;
}
 
std::string getStringField(lua_State* L, const char* key)
{
    lua_pushstring(L, key);
    lua_gettable(L, -2);
 
    std::string result = lua_tostring(L, -1);
    lua_pop(L, 1);
    return result;
}

int main(int argc, char** argv) {
    lua_State* L = luaL_newstate(); 
     
    luaL_loadfile(L, "hello.lua");
    lua_call(L, 0, 0);
    lua_getglobal(L, "window");
         
    int width = getIntField(L, "width");
    int height = getIntField(L, "height");
    std::string title = getStringField(L, "title");
             
    std::cout << "Width = " << width << std::endl;
    std::cout << "Height = " << height << std::endl;
    std::cout << "Title = " << title << std::endl;
     
    lua_close(L);

    return 0;
}
