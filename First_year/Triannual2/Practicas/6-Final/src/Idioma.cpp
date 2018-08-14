#include "Idioma.h"
#include "Bigrama.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std; 

Idioma::Idioma(){
    this->_idioma    = "unknown";
    this->_conjunto  = nullptr;
    this->_nBigramas = -1;
}

Idioma::Idioma(int nbg){
    this->_idioma    = "unknown";
    reservarMemoria(nbg);
}

Idioma::Idioma(const Idioma & orig){
    copiar(orig);
}

Idioma::~Idioma(){
    liberarMemoria();
}

Idioma& Idioma::operator=(const Idioma & orig){
    this->copiar(orig);
    return *this;
}

Bigrama Idioma::getPosicion(int p) const {
    if (p>=0 && p < this->_nBigramas)
        return this->_conjunto[p];
    else{
        //Nota: para evitar errores de no devolución, envío simplemente la primera
        throw out_of_range("El índice usado es inválido");
    }
}

void Idioma::setPosicion(int p, const Bigrama & bg){
    if (p < this->_nBigramas && p>=0){
        this->_conjunto[p].setFrecuencia(bg.getFrecuencia());
        this->_conjunto[p].setBigrama(bg.getBigrama());
    }
    else
        cerr << "Error: índice erróneo";
}

int Idioma::findBigrama(const string & bg) const{   
    for (unsigned int i=0; i < this->_nBigramas; i++){
        if (strcmp( this->_conjunto[i].getBigrama(), bg.c_str()) == 0){
            return i;
        }
    }

    return -1;
}

void Idioma::ordenar(){
    Bigrama Intercambio;

    for (int i=0; i<this->_nBigramas; i++)
        for (int j=0; j<this->_nBigramas; j++)
            if (this->_conjunto[j].getFrecuencia() < this->_conjunto[i].getFrecuencia()){
                                
                Intercambio.setFrecuencia(this->_conjunto[i].getFrecuencia());
                Intercambio.setBigrama(this->_conjunto[i].getBigrama());

                this->_conjunto[i].setFrecuencia(this->_conjunto[j].getFrecuencia());
                this->_conjunto[i].setBigrama(this->_conjunto[j].getBigrama());

                this->_conjunto[j].setFrecuencia(Intercambio.getFrecuencia());
                this->_conjunto[j].setBigrama(Intercambio.getBigrama());
            }
}

bool Idioma::salvarAFichero(const char * fichero) const{
    ofstream salida;
    salida.open(fichero);

    if (salida){
        salida << "MP-BIGRAMAS_IDIOMA-T-1.0"<<endl;
        salida << this->_idioma<<endl;
        salida << this->_nBigramas;

        for (int i=0; i < this->_nBigramas; i++)
            salida <<endl<<this->_conjunto[i].getBigrama() <<" "<<this->_conjunto[i].getFrecuencia();

        return true;
    }
    else{
        cerr << "Error: no se ha podido crear el fichero";
        return false;
    }    
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
        if (this->_idioma == idioma || this->_idioma == "unknown"){
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
    if (n > 0){
        this->_nBigramas = n;
        this->_conjunto  = new Bigrama [this->_nBigramas];
    }
}

void Idioma::liberarMemoria(){
    this->_nBigramas = -1;

    if (this->_conjunto != nullptr)
        delete [] this->_conjunto;

    this->_conjunto = nullptr;
}

void Idioma::copiar(const Idioma & otro){    
    this->_idioma = otro.getIdioma();

    reservarMemoria(otro.getSize());

    for (unsigned int i=0; i<this->_nBigramas; i++){
        this->_conjunto[i].setBigrama(otro.getPosicion(i).getBigrama());
        this->_conjunto[i].setFrecuencia(otro.getPosicion(i).getFrecuencia());
    }
}

ostream& operator<<(ostream & os, const Idioma & i){
    os <<"Idioma: "<<i.getIdioma()<<endl;
    
    os <<"Lista de " << i.getSize() << " bigramas:" <<endl;
    for (int j=0; j < i.getSize(); j++)
        os << i.getPosicion(j).getBigrama() << "-" << i.getPosicion(j).getFrecuencia()<< ", "; // << endl;

    return os;
}

istream & operator>>(istream & is, Idioma & i){
    int dimension;
    string codificacion, idioma;
    
    is >> codificacion;    
    is >> idioma;

    if (i._idioma != idioma)
        cerr <<"Se reescribirá el idioma, ya que el introducido difiere con el presente";
    
    i.setIdioma(idioma);    
        
    is >> dimension;

    int contador_lineas = 0;
    int frecuencia_temp;
    string bigrama_temp;

    i.reservarMemoria(dimension);

    for (contador_lineas; contador_lineas < dimension; contador_lineas++){
        is >> bigrama_temp;
        is >> frecuencia_temp;

        i._conjunto[contador_lineas].setBigrama(bigrama_temp.c_str());
        i._conjunto[contador_lineas].setFrecuencia(frecuencia_temp);

    }
    
    if (contador_lineas != dimension){
        cerr << "Número de bigramas proporcionados distinta de la obtenida. Se esperan errores";
    }
    
    return is;
}
