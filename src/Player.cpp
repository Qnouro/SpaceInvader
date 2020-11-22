#include <iostream>
#include "Entities.h"
#include "Grid.h"
#include "Player.h"
#include "Console.h"
#include <ncurses.h>



Player::Player(Grid grid){
    m_pos.m_x = grid.getCols() / 2;  // int
    m_pos.m_y = grid.getLines() - 2;
}

Coord Player::getPos(){
  return m_pos;
}

void Player::move(int x){

      this->undraw();

      m_pos.m_x += x;
      if (m_pos.m_x == 1){
        m_pos.m_x = 2;
      } else if (m_pos.m_x == 140){
        m_pos.m_x = 139;
      }
}

void Player::draw(){
    //  #
    // ###
    this->undraw();

    setcursorPos(m_pos.m_y - 1, m_pos.m_x);
    consoleWrite("#");

    setcursorPos(m_pos.m_y, m_pos.m_x - 1);
    consoleWrite("###");
}

void Player::undraw(){
    setcursorPos(m_pos.m_y - 1, m_pos.m_x);
    consoleWrite(" ");

    setcursorPos(m_pos.m_y, m_pos.m_x - 1);
    consoleWrite("   ");
}
