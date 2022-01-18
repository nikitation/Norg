#include <lua.hpp>
#include <iostream>
#include <string>
using namespace std;

int lua_cFunct(lua_State *L) {

    int res = lua_tointeger(L, 1);
    res *= 10;
    lua_pushinteger(L, res);

    return 1;
}

int main(int argc, char** argv) {

    lua_State *L = luaL_newstate();

    int res;

    luaL_openlibs(L);

    res = luaL_dofile(L, "hello.lua");

    lua_getglobal(L, "num");
    int num = lua_tointeger(L, -1);
    lua_settop(L, 0);
    lua_getglobal(L, "table");
    lua_pushstring(L, "var_bool");
    lua_pushstring(L, "var_string");
    lua_gettable(L, 1);
    bool vb = lua_toboolean(L, -2);
    string bs = lua_tostring(L, -1);
    lua_settop(L, 0);

    cout << num << endl << vb << endl << bs << endl;

    lua_getglobal(L, "num_is");
    lua_pushinteger(L, 5);
    lua_call(L, 1, 1);
    int f_res = lua_tointeger(L, -1);

    cout << "result lua function: " << f_res << endl;
    lua_settop(L, 0);

    lua_register(L, "HostFunction", lua_cFunct);
    lua_getglobal(L, "RunCFunction");
    lua_pushinteger(L, 5);
    lua_pushinteger(L, 4);
    lua_call(L, 2, 1);
    int cf_res = lua_tointeger(L, -1);

    cout << "result c++ from lua function: " << cf_res << endl;

    lua_close(L);

    return 0;
}
