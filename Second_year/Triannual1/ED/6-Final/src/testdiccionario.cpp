#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "diccionario.h"

using namespace std;

int main ( int argc, char * argv[] ) {
    if ( argc != 2) {
        cerr  << "Parámetros:" << endl
              << "\t1.- Fichero con las palabras";

        return 1;
    }

// ─────────────────────────────────────────────────── EXTRACCION DICCIONARIO ─────

    ifstream f( argv[1] );
    
    if ( !f ) {
        cerr << "No se ha podido abrir el fichero " << argv[1] << endl;

        return 1;
    }

    Diccionario diccionario;
    cout << "Cargando diccionario...\n";

    f >> diccionario;

    cout << "Diccionario cargado\n";

// ───────────────────────────────────────────────────────── TEST DE LONGITUD ─────
    
    int longitud;

    cout << "\n¿De qué longitud quieres ver las palabras?\n";

    do
        cin >> longitud;
    while ( longitud <= 0 );

    vector <string> extraccion = diccionario.length( longitud );

    for ( auto palabra: extraccion )
        cout << palabra << ", ";

// ─────────────────────────────────────── COMPROBACION ELEMENTOS DICCIONARIO ─────

    string palabra;

    cout << "\n\nDime una palabra: ";
    cin >> palabra;

    if ( diccionario.word_exists(palabra) )
        cout << "Existe\n";
    else
        cout << "No existe\n";
    
    
    
    return 0;
}






