#include <iostream>
using namespace std;

int main(){
	int x=1, pos=0, neg=0;
	while (x != 0) {
		cout <<"Introduce la cadena de valores que desees: ";
		cin >>x;
		if (x > 0)
			pos = pos + 1;
		if (x < 0)
			neg = neg + 1;
		}
	cout <<"Hay "<<pos<<" números positivos y "<<neg<<" números negativos";
}
