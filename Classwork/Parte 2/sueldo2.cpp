#include <iostream>
using namespace std;

int main ()
{
	double sueldob,sueldon;
	char tipo;
	cout <<"Introduce el sueldo base y si es fijo o temporal, todo seguido: ";
	cin >>sueldob;
	cin >>tipo;

	if (tipo == 'F')
	{
		sueldob=sueldob+200;
		if (sueldob >= 1200)
		{
			sueldon=sueldob - sueldob*(0.2);
			cout <<"El tipo de trabajador es fijo. Su sueldo base es "<<sueldob<<" y su sueldo neto es "<<sueldon;
		}
		else
		{
			sueldon=sueldob-sueldob*(0.17);
			cout <<"El tipo de trabajador es fijo. Su sueldo base es "<<sueldob<<" y su sueldo neto es "<<sueldon;
		} 
	}
	
	if (tipo == 'T')
	{
		if (sueldob >= 1200)
		{
			sueldon = sueldob - sueldob*(0.2);
			cout <<"El tipo de trabajador es temporal. Su sueldo base es "<<sueldob<<" y su sueldo neto es "<<sueldon;
		}
		else
		{ 
			sueldon = sueldob - sueldob*(0.17);
			cout <<"El tipo de trabajador es temporal. Su sueldo base es "<<sueldob<<" y su sueldo neto es "<<sueldon;
		}
	}
}