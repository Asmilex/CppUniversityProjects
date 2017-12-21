#include <iostream>
using namespace std;

main(){
  int x,y;
  cout <<"\nIllo, métele un valor a X";
  cin >>x;
  cout <<"\nAhora para Y";
  cin >>y;
  cout <<"\nMira cómo hago magia borrás";
  int intercambio1,intercambio2;
  intercambio1=x; intercambio2=y; x=intercambio2; y=intercambio2;
  cout <<x,y;
}
