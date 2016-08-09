#ifndef PUZZLE_H
#define PUZZLE_H
#include "Librerias.h"

class Puzzle
{
  public:
    Puzzle(char m[4][4]);
    virtual ~Puzzle();

    void print_puzzle();
    void build_mat();
    void rand_mat();
    void locate_space(int&,int&);
    void move_space(char&,int&,int&);
    bool win_lose();
    void menu();

    char matriz[4][4];

  protected:
  private:
};

#endif // PUZZLE_H
