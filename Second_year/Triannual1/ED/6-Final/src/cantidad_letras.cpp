#include <iostream>
#include <string>
#include "letras.h"

using namespace std;

int main ( int argc, char const *argv[] ) {
    
    // ────────────────────────────────────────────────────────── PARSE ARGUMENTS ─────    
    
    if ( argc != 4 ) {
        cerr << "Parámetros: ./testletras letras diccionario num_letras {L/P}";
        return 1;
    }
    
    ifstream file_diccionario (argv[1]);

    if ( !file_diccionario ) {
        cerr << "No se ha podido abrir el archivo del diccionario";
        return 1;
    }

    Diccionario diccionario;
    file_diccionario >> diccionario;

    Bolsa_Letras bolsa( diccionario, argv[2] );

    if ( bolsa.export_frecuencias(argv[3]) )
        cout << "Se ha guardado con éxito el archivo. Mira en " << argv[3] << endl;
    else
        cout << "Ha habido errores en la escritura del archivo" << argv[3];

    return 0;
}
