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

    if (m_bullet_shot){
      m_bullet_shot->draw();
    }
}

void Player::undraw(){
    setcursorPos(m_pos.m_y - 1, m_pos.m_x);
    consoleWrite(" ");

    setcursorPos(m_pos.m_y, m_pos.m_x - 1);
    consoleWrite("   ");
}

void Player::shoot(){

    if (!m_bullet_shot){
      // setcursorPos(14, 14);
      // consoleWrite("SHOOTING");
        m_bullet_shot = new Bullet(m_pos.m_x, m_pos.m_y - 1);
    } else {
      // setcursorPos(14, 14);
      // consoleWrite("Existing");
    }
}

Bullet* Player::getBullet(){
  return m_bullet_shot;
}

void Player::deleteBullet(){
    m_bullet_shot->undraw();
    delete m_bullet_shot;
    m_bullet_shot = nullptr;
}


Bullet::Bullet(int x=1, int y=1){
    m_pos.m_x = x;
    m_pos.m_y = y;
}


Coord Bullet::getPos(){
    return m_pos;
}


int Bullet::move(int y){
      static int moving_step{5};
      if (moving_step == 5){
          moving_step = 0;

          this->undraw();

          m_pos.m_y += y;
          // verify collision
          // if collision:
            // Destroy the bullet and remove hp
          if (m_pos.m_y == 1){
            return false;
          }

          return true;
      } else {
          ++moving_step;
      }


}

void Bullet::draw(){
    //  #
    // ###
    this->undraw();

    setcursorPos(m_pos.m_y - 1, m_pos.m_x);
    consoleWrite(".");
}

void Bullet::undraw(){
    setcursorPos(m_pos.m_y, m_pos.m_x);
    consoleWrite(" ");
}
