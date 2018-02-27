#include <iostream> 
using namespace std;

int main(){
	char sem,vas,fru;
	int cot;

	cout <<"¿Tiene semillas (s/n)? ";
	cin >>sem;

	if (sem == 's'){
		cout <<"Tiene frutos? ";
		cin >>fru;
		if (fru == 's'){
			cout <<"Número de cotiledóneas? ";
			cin >>cot;
			if (cot == 1)
				cout <<"Monocotiledóneas";
			else 
				cout <<"Dicotiledóneas";
		}
		else 
			cout <<"Gimnospernas";
	}
	else{
		cout <<"¿Tiene vasos conductores?";
		cin >>vas;
		if (vas == 's')
			cout <<"Pteridofitas";
		else 
			cout <<"Briofitas";
	}
}