using namespace std;

typedef pair <int, int > pii;

pii conv(int p,int z){
  int x=z-p/z-1,y;
  if(x%2==z%2) 
    y=(z-p%z)-1;
  else y=p%z; 
  //return x*z+y;
  return make_pair(x,y);
}
