#include <iostream>
#include "ContadorBigramas.h"
#include "Idioma.h"
#include "Bigrama.h"

using namespace std;

ContadorBigramas::ContadorBigramas(const string & caracteresValidos){
    this->_caracteresValidos = caracteresValidos;

    reservarMemoria(caracteresValidos.size());
}

ContadorBigramas::ContadorBigramas(const ContadorBigramas & orig){
    copiar(orig);
}

ContadorBigramas::~ContadorBigramas(){
    liberarMemoria();
}

int ContadorBigramas::getSize() const{return this->_caracteresValidos.size();} 

string ContadorBigramas::getCaracteresValidos() const{return this->_caracteresValidos;};

int ContadorBigramas::getBigramasActivos() const{


}

int ContadorBigramas::getPosicion(int fila, int columna) const{
    int dim = this->_caracteresValidos.size(); 
    
    if (fila < dim && columna < dim)
        return this->_bigramas[fila][columna];
    else{
        return -1;
        cerr <<"Índice inválido";
    }
}

bool addBigrama(const char cadena[], int frecuencia=0){


}

ContadorBigramas& ContadorBigramas::operator=(const ContadorBigramas & orig){
    copiar(orig);
    return *this;
}

ContadorBigramas& ContadorBigramas::operator+=(const ContadorBigramas & rhs){
    if (this->_caracteresValidos != rhs.getCaracteresValidos())
        cerr <<"Caracteres válidos distintos: seguramente haya errores";

    if (this->_bigramas != nullptr){
        int dim = this->getSize();

        for (unsigned int i=0; i<dim; i++)
            for (unsigned int j=0; j<dim; j++)
                this->_bigramas[i][j] += rhs.getPosicion(i,j);
    }
    else
        copiar(rhs);
    

    return *this;
}

bool ContadorBigramas::calcularFrecuenciasBigramas(const char * nfichero){


}

Idioma ContadorBigramas::toIdioma() const {



}

void ContadorBigramas::fromIdioma(const Idioma & i){


}

void ContadorBigramas::reservarMemoria(int n){
    this->_bigramas = new int * [n];
    for (int i=0; i<n; i++)
        this->_bigramas[i] = new int [n];

}

void ContadorBigramas::liberarMemoria(){
    int dim = this->_caracteresValidos.size();
    this->_caracteresValidos = "NULL";
    
    for (int i=0; i<dim; i++)
        delete [] this->_bigramas[i];
    
    delete [] this->_bigramas;
}

void ContadorBigramas::copiar(const ContadorBigramas & otro){
    this->_caracteresValidos = otro.getCaracteresValidos();

    if (this->_bigramas != nullptr)
        liberarMemoria();

    int dim = otro.getSize();
    reservarMemoria(dim);

    for (unsigned int i=0; i<dim; i++)
        for (unsigned int j=0; j<dim; j++)
            this->_bigramas[i][j] = otro.getPosicion(i,j);
}

