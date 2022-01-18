#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *f;
    f = popen("get_text.exe", "w");
    std::cout << f << std::endl;
    return 0;
}
