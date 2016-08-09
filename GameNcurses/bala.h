using namespace std;

typedef pair <int, int > pii;

class bala{
  public:
    int x,y; 
    int* Z;
    bala(int y,int* Z){
      this->Z=Z;
      x=0;
      this->y=y;
    }
    int coor(int z){ // z tamaño de la matriz
      if((z-x-1)%2==z%2)
        return (z-x-1)*z+y;
      return (z-x-1)*z+(z-y-1);
    }
    void actualizar(int z){
      x+=1;
      mvaddch(z-x,z-y,'*');
      return;
    }
};

class Bala{
  public:
    vector<bala> B;
    void agrBala(int y,int* Z){
      B.push_back(bala(y,Z));
    }
    void actualizar(int z){
      for (int i=0;i<B.size();i++)
        B[i].actualizar(z);
    }
    int Pos(int z){
      return B[0].coor(z);
    }
    int size(){
      return B.size();
    }
    int coor(int i,int z){
      return B[i].coor(z);
    }
};
