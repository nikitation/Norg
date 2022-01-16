#include <lua.hpp>
#include <iostream>
using namespace std;

void print_error(lua_State* state) {
    const char* message = lua_tostring(state, -1);
    cout << message << endl;
    lua_pop(state, 1);
}

void execute(const char* filename) {
    lua_State *state = luaL_newstate();
    luaL_openlibs(state);
    int result;
    result = luaL_loadfile(state, filename);
    result = lua_pcall(state, 0, LUA_MULTRET, 0);
    lua_close(state);
}

int main(int argc, char** argv) {
    if(argc <= 1) {
        cout << "Usage: runlua files(s)\n" <<
            "Loads and executes Lua programs." << endl;
        return 1;
    }
    for(int n = 1; n < argc; ++n) {
        execute(argv[n]);
    }
    system("PAUSE");
    return 0;
}
