#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

void EscribirMatriz (const vector<vector<double>> & matriz){
    for (int i=0; i<matriz.size(); i++){
        for (int j=0; j<matriz.size(); j++)
            cout <<matriz[i][j]<<" ";
        cout <<endl;
    }
}

double MayorDeMatriz(const vector<vector<double>> & matriz){
    double guardar=matriz[0][0];
    for (int i=0; i<matriz.size(); i++)
        for (int j=0; j<matriz.size(); j++)
            if (guardar<matriz[i][j])
                guardar=matriz[i][j];
        
    return guardar;
}

int main(){
    cout <<"Dada cualquier matriz, se va a buscar el mayor elemento. Dime la dimensión de la matriz: ";
    unsigned int dim;
    cin >>dim;
    
    vector<vector<double>> matriz(dim,vector<double>(dim));
    for (int i=0; i<matriz.size(); i++)
        for (int j=0; j<matriz.size(); j++) 
            matriz[i][j] = rand() % 1000;

    EscribirMatriz(matriz);

    cout <<"El mayor de la matriz es "<<MayorDeMatriz(matriz);
}


