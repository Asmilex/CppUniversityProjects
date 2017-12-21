#include <vector>
#include <iostream>
using namespace std;

void LecturaEnteros(int datostotales, vector<double> & datos){
    int aux;
    for (int i=0; i<datostotales; i++){
        cin >>aux;
        datos.push_back(aux);
    }
}

void Ordenador(vector<double> & datos){ 
    int aux;
    for (int i=0; i<datos.size(); i++)
        for (int j=0; j<datos.size(); j++)
            if (datos[j]>datos[i]){
                aux=datos[i];
                datos[i]=datos[j];
                datos[j]=aux;
            }    
}

double CalculoMediana(vector<double> datos){
    double mediana;

    if (datos.size()%2==0){
        mediana=(datos[(datos.size()-2)/2]+datos[(datos.size())/2])/2;
    }
    else{
        mediana=datos[(datos.size()-1)/2]; 
    }
    return mediana;
}

int main(){
    cout <<"Introduce cuántos datos se van a leer: ";
    unsigned int datostotales;
    cin >>datostotales;

    vector<double> datos;
    cout <<"¿Cuál es la serie de datos?\n";
    LecturaEnteros(datostotales, datos);

    Ordenador(datos);

    double mediana=CalculoMediana(datos);

    cout <<"\nEl valor de la mediana es "<<mediana;

    return 0;
}