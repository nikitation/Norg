#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <list>

using namespace std;

list<string> get_term_res(string command) {
    char buffer[128];
    list<string> result;

    FILE* pipe = popen(command.c_str(), "r");

    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != NULL)
            result.push_back(buffer);
    }

    pclose(pipe);
    return result;
}

int main() {
    list<string> res = get_term_res("dir .. /b /a:d");
    list<string>::iterator iter = res.begin();
    for(int i = 0; i < res.size(); i++, iter++) {
        cout << i << " line is: " << *iter;
    }
}

