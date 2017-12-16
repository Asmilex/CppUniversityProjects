#include <iostream>
using namespace std;

int main()
{
	double a,b,c,d,e;
	double sol;
	cout <<"Introduce los 5 números que quieres comparar. Introduce el número y pulsa enter: ";
	cin >>a>>b>>c>>d>>e;
	if (a>b && a>c && a>d && a>e)
		sol=a;
	else
		if (b>c && b>d && b>e)
			sol=b;
		else 
			if (c>d && c>e)
				sol=c;
			else 
				if (d>e)
					sol=d;
				else 
					sol=e;
	cout <<"\nEl número más grande es " <<sol;
}