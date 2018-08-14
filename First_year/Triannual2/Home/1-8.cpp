#include <iostream>
using namespace std;

void Escribir(double array[], unsigned int dim){
    for (int i=0; i<dim; i++)
        cout <<array[i]<<" ";
}

void Copia(double array[], double array_output[], unsigned int inicio, unsigned int ultimo){
    unsigned int j = 0;

    for (inicio; inicio<=ultimo; inicio++){
        array_output[j] = array[inicio]; 
        j++;
    }
}
void LocalizadorSubcadena(double array[], unsigned int dim, unsigned int & inicio, unsigned int & ultimo ){
    unsigned int contador=1, max_teorico=0;
    for (unsigned int i=1; i<dim; i++){
        if (array[i-1] <= array[i])
            contador++;
        else if (contador>max_teorico){ //Guarda las acotacines provisionalmente si termina la cadena monótona
            ultimo = i-1;
            inicio = i - contador;
            max_teorico = contador;
            contador = 1;
        }   
    }
}

int main(){
    unsigned const int dim = 50;  
    double array[dim] = {1,2,3,4,5,1,1,2,3,4,5,6,7,8};
    double array_output[dim];

    unsigned int inicio=0, ultimo=0; //Acotación del array fuente
    LocalizadorSubcadena(array, dim, inicio, ultimo);

    Copia(array, array_output, inicio, ultimo);

    unsigned int dim_aux = ultimo-inicio+1; //Por comodidad, dejemos en la auxiliar la dimensión útil del array destino
    Escribir(array_output, dim_aux);

    
}