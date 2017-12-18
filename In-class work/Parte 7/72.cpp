#include <iostream>
#include <vector>
using namespace std;

void LecturaEnteros(int dim, vector<int> & escalares){
    int leido;
    for (int i=1; i<dim; i++){
        cin >>leido;
        escalares.push_back(leido);
    }    
}

void EscribirMatriz(const vector<vector<int>> & Vandermonde){
    unsigned int dim=Vandermonde.size();
    for (int i=0; i<dim; i++){
        for (int j=0; j<dim; j++)
            cout <<Vandermonde[i][j];
         cout <<endl;
    }
}

int main (){
    unsigned int dim;
    cout <<"Introduce la dimensión de la matriz: ";
    cin >>dim;

    vector<int> escalares(1,1);
    cout <<"Ahora escribe una serie de números, que serán los escalares de la matriz";
    LecturaEnteros(dim, escalares);
    
    return 0;
}