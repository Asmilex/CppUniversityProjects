#include <iostream>
using namespace std;

int main (){
	int valor;
	cout <<"Introduce un valor entero \n";
	cin >>valor;

	while (valor < 0 || valor > 100){
		cout <<"El valor debe estar en el rango [0,100]. Por favor, reescriba el número\n";
		cin >>valor;
	}
}