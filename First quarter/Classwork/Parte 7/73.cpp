#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<bool> Criba(int numero){
    vector<bool> v(numero, true);

    for (int i=0; i<v.size(); i++){
        if (i>1 && v[i]==true){
            for (int j=i+i; j<v.size(); j=j+i)
                v[j]=false;

        }
    }
    return v;
}

vector<int> Factorizador(int numero){
    vector<bool> BooleanosPrimos=Criba(numero);
    vector<int> factores;
    
    for (int i=2; i<=numero/2; i++){
        if (BooleanosPrimos[i]==true && numero%i==0){
                factores.push_back(i);
                int factoresmultiples=numero/i;
                
                while (factoresmultiples%i==0){
                    factoresmultiples=factoresmultiples/i;
                    factores.push_back(i);
                }       
        }
    }
    
    return factores;

}

int main(){
    cout <<"Se va a realizar la descomposición factorial de los números que introduzcas. Cuando escriba un número negativo o 0, el programa terminará";
    int numero;
    
    while (numero>0){
        cout <<"\n¿Qué número quieres factorizar? ";
        cin >>numero;

        if (numero>0){
            vector<int> factores=Factorizador(numero);
            
            cout <<"\nSus factores son:  ";
            for (int i=0; i<factores.size(); i++)
                cout <<factores[i]<<" ";

        }
        
    }

    cout <<"\nFin de la ejecución";
    return 0 ;
}
/*for (int i=0; i<v.size(); i++)
    if (v[i]==true && i>0)
        cout <<i<<" ";*/