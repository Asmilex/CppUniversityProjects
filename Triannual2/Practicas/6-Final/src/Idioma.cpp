#include "Idioma.h"
#include "Bigrama.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//Constructores
Idioma::Idioma(){
    this->_idioma    = "NULL";
    this->_conjunto  = nullptr;
    this->_nBigramas = -1;
}

Idioma::Idioma(int nbg){
    this->_idioma    = "NULL";
    reservarMemoria(nbg);
}

Idioma::Idioma(const Idioma & orig){
    copiar(orig);    
}

Bigrama Idioma::getPosicion(int p) const{
    if (p>=0 && p < this->_nBigramas)
        return this->_conjunto[p];
    else
        cerr << "Error: índice p erróneo";
}

void Idioma::setPosicion(int p, const Bigrama & bg){
    if (p < this->_nBigramas && p>=0){
        this->_conjunto[p].setFrecuencia(bg.getFrecuencia());
        this->_conjunto[p].setBigrama(bg.getBigrama());
    }
    else
        cerr << "Error: índice p erróneo";
}

int Idioma::findBigrama(const string & bg) const{   
    for (unsigned int i=0; i < this->_nBigramas; i++){
        if (strcmp( this->_conjunto[i].getBigrama(), bg.c_str()) == 0){
            return i;
        }
    }

    return -1;
}

double Idioma::distancia(const Idioma & otro) const{
    


}

void Idioma::ordenar(){


}

bool Idioma::salvarAFichero(const char * fichero) const{

    
}

bool Idioma::cargarDeFichero(const char * fichero){ //El argumento es el fichero a leer
    ifstream entrada;
    entrada.open(fichero);
    
    if (entrada){
        string codificacion, idioma;
        int dimension;
        
        entrada >> codificacion;
        if (codificacion == "MP-BIGRAMAS_IDIOMA-T-1.0")
            cout <<"Codificación correcta"<<endl;
        else{
            cerr <<"Fallo en la codificación"<<endl;
            entrada.close();
            return false;
        }
        
        entrada >> idioma;
        if (this->_idioma == idioma || this->_idioma == "NULL"){
            cout <<"Idioma captado: "<<idioma<<endl;
            this->setIdioma(idioma);
        }
        else{
            cerr <<"Fallo en la lectura del idioma. El idioma actual "<<this->_idioma<<" no es compatible con "<<idioma<<endl;
            entrada.close();
            return false;
        }
        
        entrada >> dimension;
        cout <<"Recibida dimensión de tamaño "<<dimension<<endl;
        
        int contador_lineas = 0;
        int frecuencia_temp;
        string bigrama_temp;
        this->reservarMemoria(dimension);

        for (contador_lineas; contador_lineas < dimension; contador_lineas++){
            if (!entrada.eof()){
                entrada >> bigrama_temp;
                entrada >> frecuencia_temp;
   
                this->_conjunto[contador_lineas].setBigrama(bigrama_temp.c_str());
                this->_conjunto[contador_lineas].setFrecuencia(frecuencia_temp);

            }
            else{
                cerr <<"Error: dimensión dada es menor de la cantidad de bigramas que hay"<<endl;
                entrada.close();
                return false;
            }
        }

        if (dimension > contador_lineas + 2){
            cerr <<"Error: la dimensión dada es mayor que el número de bigramas presente"<<endl;
            entrada.close();
            return false;
        }
    }
    else{
        cerr <<"No existe el archivo "<<fichero<<endl;
        return false;
    }

    entrada.close();
    return true;
}

void Idioma::reservarMemoria(int n){
    if (this->_conjunto != nullptr)
        this->liberarMemoria();
    
    if (n > 0){
        this->_nBigramas = n;
        this->_conjunto  = new Bigrama [this->_nBigramas];
    }
}

void Idioma::liberarMemoria(){
    this->_nBigramas = -1;
    delete [] this->_conjunto;
}

void Idioma::copiar(const Idioma & otro){
    this->_idioma = otro.getIdioma();

    reservarMemoria(otro.getSize());

    for (unsigned int i=0; i<this->_nBigramas; i++){
        this->_conjunto[i].setBigrama(otro.getPosicion(i).getBigrama());
        this->_conjunto[i].setFrecuencia(otro.getPosicion(i).getFrecuencia());
    }
}
