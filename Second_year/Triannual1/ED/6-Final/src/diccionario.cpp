#include "diccionario.h"

using namespace std;

Diccionario::Diccionario ( const Diccionario& diccionario ) {
    *this = diccionario;
}

size_t Diccionario::size() const {
    return datos.size();
}

bool Diccionario::word_exists ( const string & palabra ) const {
    return datos.find( palabra ) != datos.end() 
        ? true
        : false;
}

vector < string > Diccionario::length ( const size_t longitud ) const {
    vector < string > resultado;

    for ( auto palabra: datos )
        if ( palabra.size() == longitud )
            resultado.push_back( palabra );
    
    return resultado;
}

void Diccionario::add ( const string& nueva_palabra) {
    datos.insert( nueva_palabra );
}

Diccionario& Diccionario::operator= ( const Diccionario& diccionario ) {
    datos = diccionario.datos;
    return *this;
}

ostream& operator>> ( ostream& os, const Diccionario & diccionario ) {
    for ( auto palabra: diccionario )
        os << "\t-> " << palabra;

    return os;
}

istream& operator>> ( istream& is, Diccionario & diccionario ) {
    string palabra;

    is >> palabra;
    diccionario.add( palabra );

    return is;
}

ifstream& operator >> (ifstream& in, Diccionario& diccionario ) {
    string entrada;

    while ( getline(in, entrada) )
        diccionario.add( entrada );

    return in;
}
