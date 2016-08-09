using namespace std;

typedef pair <int, int > pii;

class serpiente {
  public:
    int inicio;
    int tam;
    int* Z;
    serpiente (int inicio,int tam,int* Z){
      this->Z=Z;
      this->inicio=inicio;
      this->tam=tam;
    }
    void actualizar(int z){
      //*(Z+conv(inicio,z))=0;
      //*(Z+conv(inicio+tam,z))=1;
      inicio+=1;
      for (int i=inicio;i<inicio+tam;i++){
        pii cor=conv(i,z);
        mvaddch(z-cor.first,cor.second,'o');
      }
      return;
    }
    void act_tam(int pos){
      int fin=inicio+tam-1;
      inicio=pos+1;
      tam=fin-inicio+1;
      return;
    }
    bool colision(int z,int pos){
      for (int i=inicio;i<inicio+tam;i++)
        if (i==pos)return true;
      return false;
    }
    pii Get(){
      return make_pair(inicio,tam);
    }
};

class Serpiente {
  public:
    vector<serpiente> C;
    //Serpiente (int tam) C.push_back(serpiente(0,tam));
    void agrSerpiente(int inicio,int tam,int* Z){
      C.push_back(serpiente(inicio,tam,Z));
      return;
    }
    void actualizar(int z){
      for (int i=0;i<C.size();i++)
        C[i].actualizar(z);
      return;
    }
    int colision(int z,int  pos){
      for (int i=0;i<C.size();i++)
        if(C[i].colision(z,pos)) return i;
      return -1; 
    }
    int size(){
      return C.size();
    }
    pii Get(int i){
      return C[i].Get();
    }
    int GetCabeza(){
      pii aux=C[0].Get();
      return aux.first+aux.second-1;
    }
    void act_tam(int i,int pos){
      C[i].act_tam(pos);
      return;
    }
};
