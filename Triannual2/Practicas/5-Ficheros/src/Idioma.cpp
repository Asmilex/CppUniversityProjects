/** 
 * @file Idioma.cpp
 * @author DECSAI
 * @warning Código incompleto. Implementar la clase completa
*/

#include "Idioma.h"
#include "Bigrama.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//Constructores 
Idioma::Idioma(){
    this->_idioma    = "NULL";
    this->_conjunto  = nullptr;
    this->_nBigramas = -1;
}

Idioma::Idioma(int nbg){
    this->_idioma    = "NULL";
    this->_conjunto  = nullptr;
    this->_nBigramas = nbg;
}


void Idioma::reservarMemoria(int n){
    if (this->_conjunto != nullptr)
        delete [] this->_conjunto;
    
    this->_nBigramas = n;
    this->_conjunto = new Bigrama [this->_nBigramas];

}

void Idioma::ampliarMemoria(int n){
    //Copia de la memoria a uno emporal
    Bigrama * Intercambio = new Bigrama [this->_nBigramas];

    for (unsigned int i=0; i < this->_nBigramas; i++){
        Intercambio[i].setFrecuencia(this->_conjunto[i].getFrecuencia());
        Intercambio[i].setBigrama(this->_conjunto[i].getBigrama());
    }

    //Realocación
    delete [] this->_conjunto;
    this->_nBigramas = this->_nBigramas + n;
    this->_conjunto = new Bigrama [this->_nBigramas];
    
    for (unsigned int i=0; i < this->_nBigramas; i++){
        this->_conjunto[i].setFrecuencia(Intercambio[i].getFrecuencia());
        this->_conjunto[i].setBigrama(Intercambio[i].getBigrama());
    }

    delete [] Intercambio;
}

void Idioma::liberarMemoria(){
    this->_nBigramas = -1;
    delete [] this->_conjunto;

}

Bigrama Idioma::getPosicion(int p) const{
    if (p < this->_nBigramas)
        return this->_conjunto[p];
    else
        cerr << "Error: índice p erróneo";
}

void Idioma::setPosicion(int p, const Bigrama & bg){
    if (p < this->_nBigramas){
        this->_conjunto[p].setFrecuencia(bg.getFrecuencia());
        this->_conjunto[p].setBigrama(bg.getBigrama());
    }
    else
        cerr << "Error: índice p erróneo";
}

int Idioma::findBigrama(const string bg) const {
    for (unsigned int i=0; i < this->_nBigramas; i++){
        if (this->_conjunto[i].getBigrama() == bg)
            return i;
    }
    
    return -1;
}

void Idioma::addBigrama(const Bigrama & bg){
    int posicion = Idioma::findBigrama(bg.getBigrama()); 
    if (posicion > -1)
        this->_conjunto[posicion].setFrecuencia(bg.getFrecuencia() + this->_conjunto[posicion].getFrecuencia());
    else{
        Idioma::ampliarMemoria(1);
        this->_conjunto[this->_nBigramas-1].setFrecuencia(bg.getFrecuencia());
        this->_conjunto[this->_nBigramas-1].setBigrama(bg.getBigrama());
    }
}

bool Idioma::cargarDeFichero(const char * fichero){

}

bool Idioma::addDeFichero(const char * fichero){
    
}