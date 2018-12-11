#include "letras.h"
#include <string.h>
#include <cstring>

using namespace std;

int juego_puntuaciones ( Letras letras ) { 

}

int juego_longitud ( Letras& letras ) {
    char opcion;
    size_t amount_letters = letras.get_amount_letters();

    do {
        
        list< char > lista_letras = letras.get_list_letters();
        
        cout << "Lista de lerras generadas:\n";
        for ( auto letra: lista_letras )
            cout << letra << " ";

        cout << "Búsqueda de palabras con una longitud máxima de " << letras.get_amount_letters() << ":\n";
        
        auto palabras = letras.search_longest_words( amount_letters );
        for ( auto word: palabras )
            cout << word << " ";

        cout << "\n¿Quieres seguir jugando? (S/N) ";
        cin >> opcion;

        letras.generate_random_letters( amount_letters );

    } while ( toupper(opcion) == 'S');

    return 0;
}

int main ( int argc, char const *argv[] ) {

    // ────────────────────────────────────────────────────────── PARSE ARGUMENTS ─────    
    
    if ( argc != 5 ) {
        cerr << "Parámetros: ./testletras letras diccionario num_letras {L/P}";
        return 1;
    }
    
    if (   strcmp( argv[4], "L" ) != 0 
        && strcmp( argv[4], "P" ) != 0 ) {

        cerr << "El último parámetro no es ni L ni P";
        return 1;
    }

    // Diccionario
    ifstream dic_file( argv[2] );
    
    if ( !dic_file ) {
        cerr << "No se ha podido abrir el fichero " << argv[2] << endl;

        return 1;
    }

    Diccionario diccionario;    
    dic_file >> diccionario;
    
    // Letras
    string archivo_letras = argv[1];
    
    Letras letras( archivo_letras, atoi( argv[3] ) );
    letras.load_diccionario( diccionario );

    // ─────────────────────────────────────────────────────────── MODOS DE JUEGO ─────

    int exit_value;

    strcmp( argv[4], "P" ) == 0 
        ? exit_value = juego_puntuaciones( letras ) 
        : exit_value = juego_longitud( letras );

    return exit_value;
}
