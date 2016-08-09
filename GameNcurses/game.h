using namespace std;

typedef pair <int, int > pii;

class Game{
  public:
    int z;//tam de la matriz
    int* Z;
    Serpiente C;
    Bala B;
    tanke T;
    Game(int z,int tam,int* Z){
      this->Z=Z;
      this->z=z;
      C.agrSerpiente(0,tam,Z);
      //for (int i=0;i<tam;i++)
      //  *(Z+conv(i,z))=1;
      T.Crear(z,Z);
      *(Z+z/2)=1;
    }
    bool colision_Bala(){
      if (B.size()>0){
        for (int i=0;i<B.size();i++){
          int pos=B.coor(i,z);
          int coli=C.colision(z,pos);
          if (coli!=-1){
            if(pos==C.GetCabeza())
              return true;
            else{
              pii aux=C.Get(coli);
              C.agrSerpiente(aux.first,pos-aux.first,Z); 
              C.act_tam(coli,pos);
            }
          }
        }
      }
      return false;
    }
    bool colision_Tanke(){
      int coli=C.colision(z,T.coor(z));
      if (coli!=-1)
       return true;
      return false;
    }
    void actualizar(int dir,bool ba){
      /*for (int i=z-1;i>-1;i--){
        for (int j=0;j<z;j++)
          cout << *(Z+i*z+j) << " ";
        cout << endl;
      }*/
      if (ba) B.agrBala(T.Get(),Z);
      T.actualizar(z,dir);
      C.actualizar(z);
      B.actualizar(z);
      return;
    }
};
