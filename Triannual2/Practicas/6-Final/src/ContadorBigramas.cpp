#include <iostream>
#include <cstring>
#include <fstream>
#include "ContadorBigramas.h"
#include "Idioma.h"
#include "Bigrama.h"

using namespace std;

ContadorBigramas::ContadorBigramas(const string & caracteresValidos){
    this->_caracteresValidos = caracteresValidos;  
    reservarMemoria(this->_caracteresValidos.size());
}

ContadorBigramas::ContadorBigramas(const ContadorBigramas & orig){
    copiar(orig);
}

ContadorBigramas::~ContadorBigramas(){
    liberarMemoria();
}

int ContadorBigramas::getSize() const{return this->_caracteresValidos.size();} 

int ContadorBigramas::getBigramasActivos() const{
    int dim = this->_caracteresValidos.size();
    int activos = 0;

    for (unsigned int i=0; i<dim; i++)
        for (unsigned int j=0; j<dim; j++)
            if (this->_bigramas[i][j] > 0)
                activos++;
    
    return activos;
}

bool ContadorBigramas::addBigrama(const char cadena[], int frecuencia){
    if (strlen(cadena) <= 1){
        cerr <<"Longitud de cadena inválida. Is this an attack?\n";
        return false;
    }

    int fila    = this->_caracteresValidos.find(cadena[0]);
    int columna = this->_caracteresValidos.find(cadena[1]);

    if (fila == -1 || columna == -1){
        //cerr <<"No se puede añadir el bigrama \""<<cadena[0]<<cadena[1]<<"\". No se encuentra disponible";
        return false;
    }

    if (frecuencia == 0)
        this->_bigramas[fila][columna]++;
    if (frecuencia > 0)
        this->_bigramas[fila][columna]+= frecuencia;
        
    return true;
}

ContadorBigramas& ContadorBigramas::operator=(const ContadorBigramas & orig){
    copiar(orig);
    return *this;
}

ContadorBigramas& ContadorBigramas::operator+=(const ContadorBigramas & rhs){
    if (this->_caracteresValidos != rhs._caracteresValidos)
        cerr <<"Caracteres válidos distintos: seguramente haya errores";

    if (this->_bigramas != nullptr){
        int dim = this->getSize();

        for (unsigned int i=0; i<dim; i++)
            for (unsigned int j=0; j<dim; j++)
                this->_bigramas[i][j] += rhs._bigramas[i][j];
    }
    else
        copiar(rhs);
    
    return *this;
}

bool ContadorBigramas::calcularFrecuenciasBigramas(const char * nfichero){
    ifstream entrada;
    entrada.open(nfichero);

    if (!entrada){
        cerr <<"Error en la apertura del fichero";
        return false;
    }

    string palabra;
    char bigrama[3];
    bigrama[2] = '\0';

    while (!entrada.eof()){
        entrada >>palabra;

        if (palabra.size() > 1)
            for (unsigned int i=0; i<palabra.size()-1; i++){
                bigrama[0] = tolower(palabra[i]);
                bigrama[1] = tolower(palabra[i+1]);

                this->addBigrama(bigrama);
            }
    }
    
    return true;
}

Idioma ContadorBigramas::toIdioma() const {
    Idioma new_idioma(this->getBigramasActivos());

    int posicion = 0;
    int dim      = this->_caracteresValidos.size();
    
    char cadena[3];
    cadena[2] = '\0';
    
    Bigrama bigrama;

    for (unsigned int i=0; i<dim; i++)
        for (unsigned int j=0; j<dim; j++)
            if (this->_bigramas[i][j] > 0){
                cadena[0] = this->_caracteresValidos[i];
                cadena[1] = this->_caracteresValidos[j];

                bigrama.setBigrama(cadena);
                bigrama.setFrecuencia(this->_bigramas[i][j]);
                
                new_idioma.setPosicion(posicion,bigrama);
                posicion++;
            }

    return new_idioma;
}
    
void ContadorBigramas::fromIdioma(const Idioma & i){
    for (unsigned int j=0; j<i.getSize(); j++){
        this->addBigrama(i.getPosicion(j).getBigrama(),i.getPosicion(j).getFrecuencia());
    }
}

void ContadorBigramas::reservarMemoria(int n){
    if (n>0){
        this->_bigramas = new int * [n];
        
        for (int i=0; i<n; i++)
            this->_bigramas[i] = new int [n];

        for (unsigned int i=0; i<n; i++)
            for (unsigned int j=0; j<n; j++)
                this->_bigramas[i][j] = 0;
    }
    else
        cerr <<"Reservar memoria | tamaño pasado menor que 0";
}

void ContadorBigramas::liberarMemoria(){
    int dim = this->_caracteresValidos.size();
    this->_caracteresValidos = "NULL";
    
    for (int i=0; i<dim; i++)
        delete [] this->_bigramas[i];
    
    delete [] this->_bigramas;
}

void ContadorBigramas::copiar(const ContadorBigramas & otro){
    this->_caracteresValidos = otro._caracteresValidos;

    if (this->_bigramas != nullptr)
        liberarMemoria();

    int dim = otro.getSize();
    reservarMemoria(dim);

    for (unsigned int i=0; i<dim; i++)
        for (unsigned int j=0; j<dim; j++)
            this->_bigramas[i][j] = otro._bigramas[i][j];
}

