#include <iostream>
using namespace std;

int main(){
	int num=0;
	while (num <= 0){ //Comprueba si el número es positivo
		cout <<"Introduce un número entero positivo\n";
		cin >>num;	
	}
	cout <<"El número es "<<num;
	int dig=0
	while (num > 0){ //Este bucle calcula las cifras del número
		num=num/10;
		dig = dig + 1;
	}
	cout <<" y tiene "<<dig<<" cifras";
}