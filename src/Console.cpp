#include <iostream>
#include <ncurses.h>

void setcursorPos(int x, int y){
    // std::cout << std::string("\033[") +
    //              std::to_string(x) +
    //              std::string(";") +
    //              std::to_string(y) +
    //              std::string("H");
    move(x, y);
}

void consoleWrite(const char* line){
    //std::cout << line;
    printw(line);
}
