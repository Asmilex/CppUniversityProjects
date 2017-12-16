#include <iostream>
using namespace std;

int main(){
	double dol,ite;
	cout <<"¿Cuántos € vale 1$?\t";
	cin >>dol;
	cout <<"Límite de cambio?\t";
	cin >>ite;

	for (int i=1; i < ite + 1; i++){
		cout <<i<<"	$ vale(n) "<<i*dol<<"€\n";
	}
}