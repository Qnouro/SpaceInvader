#include <iostream>
#include <cstdlib>
#include "Game.h"
#include "Grid.h"
#include "Player.h"
#include "Entities.h"
#include "Console.h"
#include <ncurses.h>



void initSetup(){
  // std::system("clear");
  initscr();
  cbreak();
  noecho();
  nodelay(stdscr, TRUE);
  clearok(stdscr, TRUE);
  idlok(stdscr, TRUE);
  curs_set(0);
  // immedok(stdscr, TRUE);  // Overkill

}


void draw(Grid grid, Player *player){
  grid.draw();
  player->draw();
  // wrefresh(stdscr);
}


void logic(Player *player){
  player_logic(player);
  // enemies_logic();

}


int main(){

    initSetup();
    // initscr();

    // Creating the game grid
    // Grid grid{145, 39};
    Grid grid{COLS, LINES};
    Player player{grid};
    //Enemy enemy{grid};

    bool gameover{false};


    while(!gameover){
      // werase(stdscr);
      wrefresh(stdscr);
      draw(grid, &player);
      logic(&player);
    }


    endwin();

    return 0;
}

int kbhit(void)
{
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}

void player_logic(Player *player){
  if (player){
      if (kbhit()){
          auto c{getch()};
          switch(c){
              case 68:  // Left arrow
                player->move(-1);
                break;
              case 67:  // Right arrow
                player->move(1);
                break;
              case 65: // Spacebar
                player->shoot();
                break;
              default:

                break;
          }
      } else {
        napms(10);
      }

      if (player->getBullet()){
        if (!player->getBullet()->move(-1)){
            player->deleteBullet();
        };
      }
  }

}
