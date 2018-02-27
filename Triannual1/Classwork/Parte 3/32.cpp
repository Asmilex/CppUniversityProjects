#include <iostream> 
using namespace std;

int main(){
	double rad,per,are;
	char opt='0';
	do {
		cout <<"\n\tBienvenido al programa! Selecciona una opción: \n \t1) Cambiar el valor del radio \n\t2) Mostrar el valor del radio \n\t3) Calcular el área \n\t4) Calcular el perímetro\n\t5) Finalizar el programa\n";
		cin >>opt;
		per=2*3.1415*rad;
		are=3.1415*rad*rad;
		switch (opt) {
			case '1':
				cout <<"¿Cuánto vale? ";
				cin >>rad;
				break;
			case '2':
				cout <<"El radio vale "<<rad;
				break;
			case '3':
				cout <<"El área vale "<<are;
				break;
			case '4':
				cout <<"El perímetro vale "<<per;
				break;
			case '5':
				opt = '5';
				break;
		}
		
	} while (opt != '5');

}