#include <iostream>
#include <vector>
using namespace std;

void Ordenador(vector<int> & serienumeros){
    int aux;
    for (int i=0; i<serienumeros.size(); i++)
        for (int j=0; j<serienumeros.size(); j++)
            if (serienumeros[j]>serienumeros[i]){
                aux = serienumeros[i];
                serienumeros[i]=serienumeros[j];
                serienumeros[j]=aux;
            }
        
}

void LectorSerie(vector<int> & serienumeros){
    int introduccion=0;

    while (introduccion>=0){
        cin >>introduccion;

        if (introduccion>=0)
            serienumeros.push_back(introduccion);
    }
}

double CalculoMediana(vector<int> serienumeros){
    if (serienumeros.size()==0)
        return -1;
    if (serienumeros.size()%2!=0)   //Impar
        return serienumeros[(serienumeros.size()-1)/2];
    
    int val1=serienumeros[serienumeros.size()/2]/2;
    int val2=serienumeros[(serienumeros.size()/2)-1]/2;
    if (serienumeros.size()%2==0){  //Par
        return val1+val2;
    }


}

int main(){
    cout <<"Escribe una serie de números enteros. Cuando pongas un negativo, se terminará la lectura: ";
    vector<int> serienumeros;
    LectorSerie(serienumeros);
    Ordenador(serienumeros);

    for (int i=0; i<serienumeros.size(); i++)
        cout <<serienumeros[i]<<" ";


    double mediana=CalculoMediana(serienumeros);
    if (mediana== -1)
        cout <<"No hay datos a procesar";
    else
        cout <<"La mediana vale "<<mediana;

    return 0;
}