#pragma once
#include "Entities.h"

class Bullet{
  private:
    Coord m_pos{1, 1};

  public:
    Bullet(int x, int y);

    Coord getPos();

    int move(int x);

    void draw();

    void undraw();
};


class Player{
  private:
    Coord m_pos{1, 1};
    Bullet *m_bullet_shot{nullptr};

  public:
    Player(Grid grid);

    Coord getPos();

    void move(int x);

    void shoot();

    void draw();

    void undraw();

    Bullet* getBullet();

    void deleteBullet();

};
