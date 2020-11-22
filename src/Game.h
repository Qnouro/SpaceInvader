#pragma once

#include "Grid.h"
#include "Player.h"

void initSetup();

void draw(Grid grid, Player *player);

void logic();

int kbhit(void);

void player_logic(Player *player);
