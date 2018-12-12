#include "letras.h"
#include <string.h>
#include <cstring>

using namespace std;

int juego_puntuaciones ( Letras letras ) { 

}

int juego_longitud ( Letras& letras ) {
    char opcion;
    size_t amount_letters = letras.get_amount_letters();

    //cout << letras;
    
    do {

        list< char > lista_letras = letras.get_list_letters();
        
        cout << "\nLista de lerras generadas:\n";
        for ( auto letra: lista_letras )
            cout << letra << " ";

        string sol_user;
        cout << "\nDame tu solución: ";
        cin >> sol_user;

        if ( !letras.is_word_diccionario(sol_user) )
            cout << "\nLa palabra que me has dado no está en el diccionario\n";
        else
            cout << "\nPuntuación de la palabra: " << sol_user.size() << endl; 

        
        cout << "\nBúsqueda de palabras con una longitud máxima de " << letras.get_amount_letters() << ":\n";
        
        auto palabras = letras.search_longest_words( amount_letters );
        for ( auto word: palabras )
            cout << word << " (" << word.size() << "), " ;

        cout << "\n\n¿Quieres seguir jugando? (S/N) ";
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
    
    Letras letras( diccionario, atoi(argv[3]) );
    

    // ─────────────────────────────────────────────────────────── MODOS DE JUEGO ─────


    if ( strcmp( argv[4], "P" ) == 0 )
        juego_puntuaciones( letras );
    else
        juego_longitud( letras );

    return 0;
}
