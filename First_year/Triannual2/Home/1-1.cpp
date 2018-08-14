#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;


void ImprimirArray(int array[], int dim){
    for (unsigned int i=0; i<dim; i++)
        cout <<array[i]<<" ";
    cout <<endl;
}

int Uniforme(int min, int max){
    double u01 = rand() / (RAND_MAX + 1.0);
    return floor(min + u01 * (max - min + 1));
}

void GenerarArray(int array[], int dim, int min, int max){
    for (int i=0; i<dim; i++)
        array[i] = Uniforme(min, max);
}

int main(){
    srand((int) time(0));
    
    int mi_array[500];
    int dim=0;
    int min=0, max=0;

    cout <<"¿Cuál será el tamaño del array?: ";
    cin >>dim;
    cout <<"Dime ahora las acotaciones para los valores: ";
    cin >>min>>max;


    GenerarArray(mi_array, dim, min, max);
    ImprimirArray(mi_array, dim);

}