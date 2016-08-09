#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef pair <int,int> pii;

class Usuario {
  private:
    string nombre;
    int clave;
  public:
    Usuario(){
      cout << "Escriba su nombre de usuario o administrador: " << endl;
      cin >> nombre;
      int clave;
      cout << "Escriba su clave: ";
      cin >> clave;
      this->clave=clave;
    }
    //void SetNombre(string* nombre){ this->nombre=nombre;}
    //void SetClave(int clave){this->clave=clave;}
};

pii eu_ex(int a,int b){
  if (b==0) return make_pair(1,0);
  else{ pii Res= eu_ex(b, a%b);
    return make_pair(Res.second,Res.first - Res.second * (a/b));
  }
} 

int inv (int n, int m){
  pii Eu_ex = eu_ex(n,m);
  return ((Eu_ex.first%m)+m)%m;
}

char enc(char c, int clave ){
  return char((int(c)*clave)%256);
}

void alg(string in, int clave){
  string out;
  cout << "Guardar como: ";
  cin >> out;
  ifstream leer(in);
  ofstream escr(out);
  char c;
  while(leer.get(c)) escr.put (enc(c,clave));
  escr.close();
  leer.close();
  return ; 
}

void enc(int clave){
  string in;
  cout << "Archibo de texto: ";
  cin >> in;
  alg(in,clave);
}

void revisar(){
  int clave,clave1;cout << "Clave: ";
  cin >> clave;clave1=inv(clave,256);
  enc(clave);enc(clave1);
  return ;
}

int main(){
  vector <Usuario> usuarios;
  Usuario Admin;
  //revisar();
}
