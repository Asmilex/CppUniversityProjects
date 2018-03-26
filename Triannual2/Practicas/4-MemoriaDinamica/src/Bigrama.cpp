/** 
 * @file Bigrama.cpp
 * @author DECSAI
 * @warning Código incompleto
*/

#include <cstring>
#include <iostream>
#include "Bigrama.h"

using namespace std;


Bigrama::Bigrama() {
    _bigrama[0] = '\0';
    _frecuencia = -1;
}

const char * Bigrama::getBigrama() const{
    return this->_bigrama;
}

int Bigrama::getFrecuencia() const{
    return this->_frecuencia;
};

void Bigrama::setBigrama(const char cadena[]){
    int comprobador  = 0;
    bool interruptor = true;

    for (comprobador; interruptor == true && comprobador < 2; comprobador++)
        if (this->_bigrama[comprobador] == '\0' || cadena[comprobador] == '\0')
            interruptor = false;

    if (!interruptor)
        cout <<"Longitud del bigrama inválida para la cadena recibida";
    else{
        for (unsigned int i=0; i < 2; i++)
            this->_bigrama[i] = cadena [i];
        this->_bigrama[2] = '\0';
    }
};

void Bigrama::setFrecuencia(int frec){
    this->_frecuencia = frec;
}


void imprimeBigramas(const Bigrama *v, int n)  {
    cout << "Lista de " << n << " bigramas:" <<endl;
    for (int i=0; i<n; i++)
        cout << v[i].getBigrama() << "-" << v[i].getFrecuencia()<< ", "; // << endl;
}

void ordenaAscBigr(Bigrama * v, int n){
    Bigrama Intercambio;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (v[j].getBigrama() < v[i].getBigrama()){
                Intercambio.setFrecuencia(v[i].getFrecuencia());
                Intercambio.setBigrama(v[i].getBigrama());

                v[i].setFrecuencia(v[j].getFrecuencia());
                v[i].setBigrama(v[j].getBigrama());

                v[j].setFrecuencia(Intercambio.getFrecuencia());
                v[j].setBigrama(Intercambio.getBigrama());
            }

}

void ordenaAscFrec(Bigrama * v, int n){
    Bigrama Intercambio;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (v[j].getFrecuencia() < v[i].getFrecuencia()){
                Intercambio.setFrecuencia(v[i].getFrecuencia());
                Intercambio.setBigrama(v[i].getBigrama());

                v[i].setFrecuencia(v[j].getFrecuencia());
                v[i].setBigrama(v[j].getBigrama());

                v[j].setFrecuencia(Intercambio.getFrecuencia());
                v[j].setBigrama(Intercambio.getBigrama());
            }
}

void sumaBigramas(const Bigrama * v1, int nv1, const Bigrama * v2, int nv2, Bigrama *& res, int & nres){
    nres = nv1 + nv2;
    for (int i=0; i<nres; i++){
        if (i<nv1)
            res[i] = v1[i];
        else
            res[i] = v2[i-nv1];

    }
}