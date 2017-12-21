#include <iostream>
using namespace std;

int main(){
  int dia,diaspasados;
  cout << "\nDime el día de la semana, siendo el lunes 0 y el domingo 6:";
  cin >>dia;
  cout << "\n¿Cuántos días quieres que pasen?";
  cin >> diaspasados;
  int resultado=(dia+diaspasados)%7;
  cout <<"\nEl día de la semana será " <<resultado;
}
