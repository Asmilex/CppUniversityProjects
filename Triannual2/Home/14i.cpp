#include <iostream>
#include <fstream>
using namespace std;

struct vectorChar{
    char * array;
    int util;
    int capacidad;
};

void inicializar(vectorChar & v){
    v.array     = new char [10];
    v.util      = 0;
    v.capacidad = 10
}

void liberar(vectorChar & v){
    delete [] v.array; 
    v.array     = 0;
    v.util      = 0;
    v.capacidad = 0;
}

void mostrar(ostream & flujo, const vectorChar & v){
    for (int i = 0; i < v.util; i++){
        flujo <<v.array[i];
    }
    flujo << endl;
}    

void aniadir(vectorChar & v, char caracter){
    if (v.util == v.capacidad)
        redimensionar(v, v.capacidad);
    v.array[v.util] = caracter;
    v.util++;
}

void leer(istream & flujo, vectorChar & v){
    char caracter;

    while (flujo.get(caracter));
        aniadir(v, caracter);
}

int main(int argc, char * argv[]){
    vectorChar mivector;
    

    inicializar(mivector);
    if (argc == 1){
        leer (cin, mivector);
    
    } else{
        ifstream flujo (argv[1]);
        if (!flujo){
            cerr << "Error: fichero "<<argv[1]<<" no válido."<<endl;
            return 1;
        }
        leer (flujo, mivector);
    }
    
    mostrar(cout, mivector);
    liberar(mivector);
    
}
