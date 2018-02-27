#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void LecturaEnteros(int dim, vector<int> & escalares){
    int leido;
    while (escalares.size()<dim){
        cin >>leido;
        escalares.push_back(leido);
    }    
}

void EscribirMatriz(const vector<vector<int>> & Vandermonde){
    unsigned int dim=Vandermonde.size();
    for (int i=0; i<dim; i++){
        for (int j=0; j<dim; j++)
            cout <<Vandermonde[i][j]<<" ";
         cout <<endl;
    }
}

void GenVandermonde (const vector<int> & escalares, vector<vector<int>> & vandermonde ){
    for (int i=0; i<escalares.size(); i++){
        for (int j=0; j<escalares.size(); j++){
            vandermonde[j][i]=pow(escalares[j],i);
        }
    }
}


int main (){
    unsigned int dim;
    cout <<"Introduce la dimensión de la matriz: ";
    cin >>dim;

    vector<int> escalares;
    cout <<"Ahora escribe una serie de números, que serán los escalares de la matriz: ";
    LecturaEnteros(dim, escalares);

    vector<vector<int>> Vandermonde(escalares.size(),vector<int>(escalares.size()));
    GenVandermonde(escalares, Vandermonde);

    cout <<"La matriz de Vandermonde es:\n";
    EscribirMatriz(Vandermonde);
    /*for (int i=0; i<dim; i++)
        cout <<escalares[i]<<" ";
    */
    return 0;
}