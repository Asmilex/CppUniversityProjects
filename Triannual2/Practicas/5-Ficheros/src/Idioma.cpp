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
    reservarMemoria(nbg);
}


void Idioma::reservarMemoria(int n){
    if (this->_conjunto != nullptr)
        this->liberarMemoria();

    this->_nBigramas = n;
    this->_conjunto = new Bigrama [this->_nBigramas];

}

void Idioma::ampliarMemoria(int n){
    //Copia de la memoria a uno temporal
    if (n > 0 && this->_conjunto != nullptr){
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
    //TODO bg es string, getBigrama es char *. Convierte bg a la otra basura
    
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

bool Idioma::cargarDeFichero(const char * fichero){ //El argumento es el fichero a leer
    ifstream entrada;
    entrada.open(fichero);
    if (entrada){
        string codificacion, idioma, entradas;
        int dimension;
        
        entrada >> codificacion;
        if (codificacion == "MP-BIGRAMAS_IDIOMA-T-1.0")
            cout <<"Codificación correcta";
        else{
            cerr <<"Fallo en la codificación";
            return false;
        }
        
        entrada >> idioma;
        if (entrada)
            cout <<"Idioma captado: "<<idioma;
        else{
            cerr <<"Fallo en la lectura del idioma";
            return false;
        }
        
        entrada >> dimension;
        
        unsigned int contador_lineas = 0;
        string basura;
        ifstream entrada_temp;
        entrada_temp.open(fichero);
        while (!entrada_temp.eof()){
            entrada_temp >> basura;
            contador_lineas++;
        }
        if (dimension == contador_lineas + 3){


        }
        else
            cerr <<"Número de bigramas a leer incorrecto";
    }
    else{
        cerr <<"No existe el archivo";
        return false;
    }

    
    //Comprobar que todos los elementos leídos son correctos
    /* entrada >> codificacion. Este realmente no hace fala hacerlo. Pero lo hago porque puedo
    entrada >> idioma
    entrada >> dimension
    entrada >> bigramas 
    
    Controlar a los cyka blyat
    Mirar que existe el fichero antes de ponerte a hacer nah. Ej: picolini*/

}

bool Idioma::addDeFichero(const char * fichero){
    //Suma las frecuencias de ficheros
}

/*
    Voy a copiar ahora lo que estamos haciendo en clase. Lo dejo como comentario
    Se pueden usar rutas relativas y absolutas dentro de la función .open()
    Se pueden usar strings para especificar los archivos:
        string archivo = "Cosa";
        ifstream entrada;
        entrada.open(archivo);
    Se puede capturar errores de istream con:
        if (entrada)
            cout <<Funciona
        if (!entrada)
            cout <<No fufa
    Puedes detectar si te has quedado sin caracteres que leer dentro de un archivo con repetidos if (entrada)

    Traducciones de tipos: atof

    Comprobar que estemos tratando los mismos idiomas
*/

