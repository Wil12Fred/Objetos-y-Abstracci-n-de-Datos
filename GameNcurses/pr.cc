#include <curses.h>

int main(){
  char users_name[ 100 ];

  initscr();
  (void)echo();

  addstr( "What is your name> " );
  refresh();
  getnstr( users_name, sizeof( users_name ) - 1 );

  clear();

  printw( "Greetings and salutations %s!\n", users_name );
  refresh();

  printw( "\n\n\nPress ENTER to quit." );
  refresh();
  getnstr( users_name, sizeof( users_name ) - 1 );

  endwin();
  return 0;
}  
