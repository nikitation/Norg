#include <iostream>
#include <string>
#include <windows.h>

int main(int args, char** argv) {

    bool command = false;
    int command_position;

    for(int i = 0; i < args; i++) {
        if(std::string(argv[i][0]) != "-") {
            command = true;
            command_position = i;
            break;
        } else {
            // обработка параметров
            i++;
        }
    }

    return 0;
}
