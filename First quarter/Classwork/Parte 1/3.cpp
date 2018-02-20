#include <iostream>
#include <cmath>
using namespace std;

int main(){
  double media,desv,abscisa;
  const double PI=3.1415;
  cout <<"\nNecesito que me des estos valores:\nMedia:";
  cin >>media;
  cout <<"\nDesviación típica:";
  cin >>desv;
  cout <<"\nAbscisa:";
  cin >>abscisa;
  double gauss=1/(desv*sqrt(2*PI))*exp((-1/2.0)*((abscisa-media)/(desv))*((abscisa-media)/(desv)))  ;
  cout <<"\nEl apetepórico Gauss vale" <<gauss;
}
