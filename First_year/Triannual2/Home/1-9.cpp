//Puedes ir avanzando ambos arrays a la vez, y avanzar solo cuando el valor de uno sea menor que otro. Así, los vas comparando y añadiendo a otro auxiliar
#include <iostream>
using namespace std;

int MezclarUnico(double array1[], double array2[], double array_output[], unsigned int dim_util1, unsigned int dim_util2){
    unsigned int iterador1=0, iterador2=0, iterador_output=0;
    unsigned int dim_max = dim_util1 + dim_util2;
    unsigned int dim_util_output=0;

    for (iterador_output; iterador_output < dim_max; iterador_output++){
        if (array1[iterador1] < array2[iterador2]){
            array_output[iterador_output] = array1[iterador1];
            dim_util_output++;

            if(iterador1 < dim_util1)
                iterador1++;

        }
        else if (array2[iterador2] < array1[iterador1]){
            array_output[iterador_output] = array2[iterador2];
            dim_util_output++;

            if (iterador2 < dim_util2)
                iterador2++;
        }
        else if (array1[iterador1] == array2[iterador2]){
            if (iterador_output == 0){
                array_output[iterador_output] = array1[iterador1];
                dim_util_output++;
            }
            if (array_output[iterador_output-1] != array1[iterador1]){
                array_output[iterador_output] = array1[iterador1];
                dim_util_output++;
            }
            if (iterador2 < dim_util2)
                iterador2++;
            if(iterador1 < dim_util1)
                iterador1++;
            
        }

    }
}
int main(){
    const int dim=50;
    double array1[dim] = {1,2,4,30,65,66,67,80};
    double array2[dim] = {1,3,4,5,43,45,79};
    double array_output[2*dim];

    unsigned int dim_util1=8, dim_util2=7;
    unsigned int dim_final=MezclarUnico(array1, array2, array_output, dim_util1, dim_util2);

    cout <<dim_final;

}