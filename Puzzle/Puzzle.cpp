#include "Puzzle.h"

Puzzle::Puzzle(char m[4][4])
{
  for ( int i = 0 ; i < 4 ;i++ ){
    for ( int j = 0 ; j < 4 ;j++ ){
        matriz[i][j] = m[i][j];
    }
  }

}

void Puzzle:: print_puzzle(){

  for ( int i = 0 ; i < 4 ;i++ ){
    for ( int j = 0 ; j < 4 ;j++ ){
        cout << matriz[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

}

void Puzzle:: build_mat(){

  const char mat[4][4] = { {'1', '2', '3', '4'},
                         {'5', '6', '7', '8'},
                         {'9', 'A', 'B', 'C'},
                         {'D', 'E', 'F', ' '} };

  for ( int i = 0 ; i < 4 ;i++ ){
    for ( int j = 0 ; j < 4 ;j++ ){
       matriz[i][j] = mat[i][j];
    }
  }

}

void Puzzle:: rand_mat(){

 srand((unsigned int)time(NULL));
 int f , c;
 char aux;

 for (int i = 0 ; i < 4 ; ++i ){
   for (int j = 0 ; j < 4 ; ++j){
    f= rand()%4;
    c=rand()%4;
    aux = matriz[i][j];
    matriz[i][j] = matriz[f][c];
    matriz[f][c] = aux;
  }
 }

}

void Puzzle :: locate_space(int& fil , int& col ){

  for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (matriz[i][j] == ' ') {
				fil = i;
				col = j;
			}
		}
	}

}

void Puzzle :: move_space(char& op, int& f , int& c ){

  locate_space(f,c);
  int n_f , n_c ;


  switch(op){

  case 'w':
    n_f = f+1;
    n_c = c;
    break;

  case 's':
    n_f = f-1;
    n_c = c;
    break;

  case 'd':
    n_f = f;
    n_c = c-1;
    break;

  case 'a':
    n_f = f;
    cout << "fil " << n_f << endl;
    n_c = c+1;
    cout << "col " << n_c << endl;
    break;


  default:
    cout << "\n Opcion invalida !! \n Opciones disponibles -> w , s , a , d (arriba,abajo,izq,der). \n";
    cout << endl;
    n_f = f;
    n_c = c;
    break;

  }

  if (n_f >= 0 && n_f < 4 && n_c >= 0 && n_c < 4 ){
    matriz[f][c] = matriz[n_f][n_c] ;
    matriz[n_f][n_c] = ' ';
  }

}

bool Puzzle:: win_lose(){

  const char mat[4][4] = { {'1', '2', '3', '4'},
                         {'5', '6', '7', '8'},
                         {'9', 'A', 'B', 'C'},
                         {'D', 'E', 'F', ' '} };

  int cont = 0;


  for ( int i = 0 ; i < 4 ;i++ ){
    for ( int j = 0 ; j < 4 ;j++ ){
       if ( matriz[i][j] == mat[i][j] )
        ++cont;
     }
  }

  if ( cont == 15 )
    return true;
  return false;


}

void Puzzle:: menu(){

  char op;
  int f , c;

  build_mat();
  print_puzzle();
  rand_mat();
  print_puzzle();

  while ( win_lose() != 1 ){

  cin >> op;
  move_space(op,f,c);
  print_puzzle();

  }

  if ( win_lose() == 1 ){
    cout << "ganaste!" << endl;

  }


}


Puzzle::~Puzzle()
{
  //dtor
}
