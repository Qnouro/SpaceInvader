#pragma once
#include "Entities.h"

class Player{
  private:
    Coord m_pos{1, 1};

  public:
    Player(Grid grid);

    Coord getPos();

    void move(int x);

    void shoot();

    void draw();

    void undraw();

};
