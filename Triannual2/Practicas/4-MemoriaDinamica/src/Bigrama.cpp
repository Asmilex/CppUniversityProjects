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

    for (comprobador; comprobador < 2; comprobador++)
        if (cadena[comprobador] == '\0')
            interruptor = false; 


    if (interruptor == false)
        cout <<"Longitud del bigrama inválida para la cadena recibida"<<endl;
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
            if (strcmp(v[j].getBigrama(),v[i].getBigrama()) > 0){
                                
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
            if (v[j].getFrecuencia() > v[i].getFrecuencia()){
                Intercambio.setFrecuencia(v[i].getFrecuencia());
                Intercambio.setBigrama(v[i].getBigrama());

                v[i].setFrecuencia(v[j].getFrecuencia());
                v[i].setBigrama(v[j].getBigrama());

                v[j].setFrecuencia(Intercambio.getFrecuencia());
                v[j].setBigrama(Intercambio.getBigrama());
            }
}

void sumaBigramas(const Bigrama * v1, int nv1, const Bigrama * v2, int nv2, Bigrama *& res, int & nres){
    Bigrama * cadena1 = new Bigrama [nv1];
    Bigrama * cadena2 = new Bigrama [nv2];
    
    //Dado que se pasa de forma constante, creemos un nuevo array para ordenarlos
    
    for (unsigned int i=0; i<nv1; i++){     //por pre, nv1 = nv2
        cadena1[i].setBigrama(v1[i].getBigrama());
        cadena1[i].setFrecuencia(v1[i].getFrecuencia());

        cadena2[i].setBigrama(v2[i].getBigrama());
        cadena2[i].setFrecuencia(v2[i].getFrecuencia());

    }

    ordenaAscBigr(cadena1, nv1);
    ordenaAscBigr(cadena2, nv2);
    
    nres = nv1;                             //por pre
    
    for (unsigned int i=0; i<nres; i++){
        res[i].setFrecuencia(cadena1[i].getFrecuencia() + cadena2[i].getFrecuencia());
        res[i].setBigrama(cadena1[i].getBigrama());

    }
    delete [] cadena1;
    delete [] cadena2;
    
}