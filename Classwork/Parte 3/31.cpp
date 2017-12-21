#include <iostream>
#include <cmath>
using namespace std;

int main(){
	double error,tera,terb;
	cout <<"Se van a calcular las raíces del polinomio 2x³+8x²-5=0. Introduce primero el valor del error:\n ";
	cin >>error;
	cout <<"¿Entre qué valores quieres comprobar si hay soluciones?";
	cin >>tera>>terb;
		
	if (tera > terb){ //Cambia el orden del intervalo por si se da al revés
		double temp;
		temp = tera;
		tera = terb;
		terb = temp;
	}

	while (terb - tera > error){
		double media=((tera + terb)/2);
		if (tera*c < 0){

		}

		if (terb*c < 0){

		}
	} 


}