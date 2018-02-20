#include <iostream>
using namespace std;

int main(){
	int suma=0;
	int x=0;

	cout <<"Introduce los valores que te dé la gana y pulsa enter\n";

	do {
		cin >>x; 
		suma = suma + x;
		if (x == -1)
			suma = suma +1;
	} while ( x > -1);
	cout <<"La suma vale "<<suma;

}	
