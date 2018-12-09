#include "letras.h"

using namespace std;

int main ( int argc, char const *argv[] ) {
    if ( argc != 5 ) {
        cerr << "Parámetros: ./testletras idioma letras num_letras {L/P}";
        return 1;
    }

    ifstream dic_file( argv[1] );
    
    if ( !dic_file ) {
        cerr << "No se ha podido abrir el fichero " << argv[1] << endl;

        return 1;
    }

    Diccionario diccionario;    
    dic_file >> diccionario;
    
    string archivo_letras = argv[2];
    
    Letras letras( archivo_letras, atoi( argv[3] ) );
    letras.load_diccionario( diccionario );

    cout << letras;
    return 0;
}
