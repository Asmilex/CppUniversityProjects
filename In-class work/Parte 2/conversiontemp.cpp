// Este es el ejercicio 2.3
#include <iostream>
using namespace std;

int main()
{
	double base,convertido;
	char uin,uout;
	cout <<"Introduce el valor inicial, seguido de la letra de la unidad y la unidad a la que quieres convertirlo: \n";
	cin >>base>>uin>>uout;
	
	if (uin == uout)
		base = convertido;

	if (uin == 'C')
	{
		if (uout == 'K')
			convertido = base + 273.15;
		if (uout == 'F')
			convertido = (9*base)/5 + 32;
		if (uout == 'R')
			convertido = (9*base)/5 + 32 + 459.97; 
	}	
	
	if (uin == 'K')
	{
		if (uout == 'C')
			convertido = base - 273.15;
		if (uout == 'F')
			convertido = base*(9.0/5) - 459.67; 
		if (uout == 'R')
			convertido = base*(9.0/5);
	}

	if (uin == 'F')
	{
		if (uout == 'C')
			convertido = (base-32)/1.8;
		if (uout == 'R')
			convertido = base + 459.75;
		if (uout == 'K')
			convertido = (base + 459.67) * (5.0/9);
	}

	if (uin == 'R')
	{
		if (uout == 'C')
			convertido = (base - 491.67) * (5.0/9);
		if (uout == 'F')
			convertido = base - 459.67;
		if (uout == 'K')
			convertido = base * 5.9;
	}

	cout <<base<<uin<<" = "<<convertido<<uout;
}