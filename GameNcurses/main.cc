#include <iostream>
#include <vector>
#include <ctime>
#include <list>
#include <ncurses.h>
#include <stdlib.h>

#include "funciones.h"
#include "serpiente.h"
#include "bala.h"
#include "tanke.h"
#include "game.h"

using namespace std;

typedef pair <int, int > pii;

int main(){
  int z,tam;
  cin >> z >> tam;
  srand(time(NULL));
  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr,TRUE);
  timeout(800);
  int dir;
  bool ba;
  int Z[z][z];
  for (int i=0;i<z;i++)
    for (int j=0;j<z;j++) 
      Z[i][j]=0;
  Game G1(z,tam,&(Z[0][0]));
  bool jugar=true;
  while (jugar){
    int ch;
    ch=getch();
    switch(ch){
      case KEY_RIGHT:
        ba=false;
        dir=-1;
        break;
      case KEY_LEFT:
        ba=false;
        dir=1;
        break;
      case ' ':
        ba=true;
        dir=0;
        break;
      default:
        ba=false;
        dir=0;
        break;
    }
    erase();
    if (G1.colision_Tanke() || G1.colision_Bala()) jugar=false;
    G1.actualizar(dir,ba);
    refresh();
  }
  timeout(-1);
  erase();
  refresh();
  getch();
  endwin();
  cout << "Game Over" << endl;
  return 0;
}
