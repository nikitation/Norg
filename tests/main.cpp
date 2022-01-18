#include <iostream>
#include <windows.h>

int main() {
    // Вызов консольной комманды
    // system("echo hello");



    // размер терминала linux
    // struct winsize w;
    // ioctl(0, TIOCGWINSZ, &w);
    // std::cout << "lines:\t" << w.ws_row << "\ncolumns:\t" << w.ws_col;



    // размер терминала Windows
    //CONSOLE_SCREEN_BUFFER_INFO csbi;
    //int columns, rows;

    //GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    //columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    //rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    //std::cout << "Columns: " << columns << 
    //    "\nRows: " << rows << std::endl;
}
