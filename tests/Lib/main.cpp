//#include <test.hpp>
#include <windows.h>
#include <iostream>

int main() {
    typedef int (__stdcall *MyFunct_f)(int);
    HMODULE hModule = ::LoadLibrary("test.dll");
    MyFunct_f MyFunct = (MyFunct_f)::GetProcAddress(hModule, "f");
    std::cout << "number is: " << MyFunct(10) << std::endl;

    ::FreeLibrary(hModule); // unload DLL
    return 0;
}
