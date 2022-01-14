#include <iostream>
#include <string>
#include <windows.h>

int main(int args, char** argv) {

/////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////

    // список комманд
    std::string commands[] = {"content", "task", "config"};
    int command_number;

    // поиск номера комманды
    if (args != 1) {
        for (int number = 0; number < args; number++) {
            if (std::string(argv[1]) == commands[number]) {
                command_number = number;
                break;
            }
        }
    }

    switch (command_number) {
        case 0:
            std::cout << "content";
            break;
        case 1:
            std::cout << "task";
            break;
        case 2:
            set::cout << "config";
            break;
        default:
//            std::cout << "\norg [option] [command]\n\t" <<
//                "hmm";
            //SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
    }
    delete argv;
    return 0;
}
