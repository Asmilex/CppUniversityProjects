#include <iostream>
using namespace std;

int main(){
	int i=1,val,final;
	double media=0, cuad=0, varianza;
	for (i; i!=0; i++){
		cout <<"Introduce los números a sumar. Cuando quieras parar, introduce 0: \t";
		cin >>val;
		media = media + val; //Falta multiplicarlo por 1/i
		cuad = cuad + val*val;
		if (val==0){
			final = i - 1;
			i=-1;
		}
	} 	
	varianza = (cuad/final) - (media*media);
	media = (media/final);
	cout <<"La media vale "<<media<<" y la varianza "<<varianza<<"espacio"<<cuad;
}