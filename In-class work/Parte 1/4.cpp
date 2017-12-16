#include <iostream>
using namespace std;

int main(){
  double inicial, siquiente;
  cout <<"\nDame tu cosa\n";
  cin >>inicial;

  int grad=inicial;
  double min=(inicial-grad)*60;
  int siguiente=min;
  int sec=(min-siguiente)*60;

  cout <<"Aquí está tu conversión de las narices\n" <<grad; cout <<"\n" << siguiente; cout <<"\n" <<sec; //Lo que hace esto es mostrar todos los valores en diferentes líneas. Es una chapuza porque me da todo el palo mirar cómo se ponen las tabulaciones
}
