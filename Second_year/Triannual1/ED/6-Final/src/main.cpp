#include <iostream>
#include "guiatlf.h"
#include "diccionario.h"

using namespace std;

int main ( int argc, char const *argv[] ) {
    Diccionario< int, int > coleccion;
    data       < int, int > datos;

// ──────────────────────────────────────────────── PREPARACION DE PARAMETROS ─────

    datos.clave = 1;
    datos.info_asociada.push_back(4);
    datos.info_asociada.push_back(44);
    datos.info_asociada.push_back(34);

    string cosa_nueva = "Nueva info";
    coleccion.insertar(datos);

    data < string, string > estrines;
    estrines.clave = "Número natural";
    estrines.info_asociada.push_back("Conjunto de numerillos no acotados enteros");
    estrines.info_asociada.push_back("El 0 es natural");

    Diccionario < string, string > Conjuntos;
    Conjuntos.insertar(estrines);

// ─────────────────────────────────────────────────────────────── ORDENACION ─────

    cout << coleccion << endl << "Ordenado de menor a mayor" << endl;
    coleccion.sort_info_asociada();
    cout << coleccion;

    cout << coleccion << endl << "Ordenado de mayor a menor" << endl;
    auto lambda = [] ( const int& a, const int& b ) 
        {  return a > b;  };
    coleccion.sort_info_asociada( lambda );
    cout << coleccion;

// ───────────────────────────────────────────────────────────────── BUSQUEDA ─────

    cout << "\nMétodo getInfo_Asociada:" << endl;
    for ( auto elemento : Conjuntos.getInfo_Asociada("Número natural") )
        cout << "\t" <<  elemento << endl;
    
    list< data< string, string > >::iterator posicion;
    Conjuntos.find("Número natural", posicion);
    
    return 0;
}
