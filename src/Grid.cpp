#include <iostream>
#include <string.h>
#include "Grid.h"
#include "Game.h"
#include "Console.h"
#include <ncurses.h>



Grid::Grid(uint_fast8_t grid_cols, uint_fast8_t grid_lines){
    m_grid_cols = grid_cols;
    m_grid_lines = grid_lines;
}

uint_fast8_t Grid::getCols(){
    return m_grid_cols;
}

void Grid::setCols(uint_fast8_t grid_cols){
    m_grid_cols = grid_cols;
}

uint_fast8_t Grid::getLines(){
    return m_grid_lines;
}

void Grid::setLines(uint_fast8_t grid_lines){
    m_grid_lines = grid_lines;
}

void Grid::draw(){
    for (int x{0}; x < m_grid_lines; ++x){
        for (int y{0}; y < m_grid_cols; ++y){
            if (x == 0 || x == m_grid_lines - 1){
                setcursorPos(x, y);
                // std::cout << "#";
                consoleWrite("#");
            } else{
                if (y == 0 || y == m_grid_cols - 1){
                    setcursorPos(x, y);
                    consoleWrite("#");
                }
            }
        }
    }
}



// int main(){
//     // setupConsole();
//
//     std::system("clear");
//
//     Grid grid{150, 50};
//
//     grid.draw();
//
//
//
//     int x{};
//     std::cin >> x;
//
//     return 0;
// }
