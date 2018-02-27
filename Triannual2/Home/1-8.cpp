#include <iostream>
using namespace std;

void mayorSecuenciaMonotona(const int array[], int util, int salida[], int & utilSalida){
    unsigned int longitud = 0, posMax = 0;
    utilSalida = 1;

    for (int i=1; i < util; i++){
        if (array[i]>array[i-1])
            longitud++;           
        else{
            if (longitud > utilSalida){
                utilSalida = longitud;
                posMax = i - longitud; 
            }
            longitud = 1;
        }
    }
}

int main(){
    cout <<"prueba";
}