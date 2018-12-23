#include "letras.h"
#include <string.h>
#include <cstring>

using namespace std;

int juego_puntuaciones ( Bolsa_Letras letras ) { 
    char opcion; 
    size_t amount_letters = letras.get_list_letters().size();

    do {
        letras.generate_random_letters( amount_letters );
        list< char > lista_letras = letras.get_list_letters();
        
        cout << "\nLista de lerras generadas:\n";
        for ( auto letra: lista_letras )
            cout << letra << " ";

        string sol_user;
        cout << "\nDame tu solución: ";
        cin >> sol_user;

        if ( letras.pertenece_bolsa(sol_user) )
            cout << "La puntuación de tu palabra es " << letras.puntuacion_palabra(sol_user) << endl;
        else
            cout << "La palabra no pertenece al diccionario\n";
    
        cout << "\nHold my beer: " << endl;
        auto palabras = letras.search_rarest_words();

        for ( auto word: palabras )
            cout << word << " (" << letras.puntuacion_palabra(word) << "), " ;

        cout << "\n\n¿Quieres seguir jugando? (S/N) ";
        cin >> opcion;

        
    } while ( toupper(opcion) == 'S' );

    return 0;
}

int juego_longitud ( Bolsa_Letras& letras ) {
    char opcion;
    size_t amount_letters = letras.get_amount_letters();

    //cout << letras;
    
    do {
        letras.generate_random_letters( amount_letters );
        list< char > lista_letras = letras.get_list_letters();
        
        cout << "\nLista de lerras generadas:\n";
        for ( auto letra: lista_letras )
            cout << letra << " ";

        string sol_user;
        cout << "\nDame tu solución: ";
        cin >> sol_user;

        if ( !letras.pertenece_bolsa(sol_user) )
            cout << "\nLa palabra que me has dado no está en el diccionario\n";
        else
            cout << "\nPuntuación de la palabra: " << sol_user.size() << endl; 

        
        cout << "\nBúsqueda de palabras con una longitud máxima de " << letras.get_amount_letters() << ":\n";
        
        auto palabras = letras.search_longest_words( amount_letters );
        for ( auto word: palabras )
            cout << word << " (" << word.size() << "), " ;

        cout << "\n\n¿Quieres seguir jugando? (S/N) ";
        cin >> opcion;


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
    
    // Bolsa_Letras
    string archivo_letras = argv[1];
    
    Bolsa_Letras letras( diccionario, atoi(argv[3]) );
    

    // ─────────────────────────────────────────────────────────── MODOS DE JUEGO ─────

    cout << letras;

    if ( strcmp( argv[4], "P" ) == 0 )
        juego_puntuaciones( letras );
    else
        juego_longitud( letras );

    char opcion; 
    cout << "\n¿Quieres guardar los resultados en el fichero " << argv[1] << "? (S/N) ";
    cin >> opcion;

    if ( toupper(opcion) ==  'S' ) {
        if (letras.save_file( argv[1] ) )
            cout << "\nArchivo guardado correctamente\n";
        else
            cout << "\nNo se ha podido guardar el archivo\n";
    }

    cout << "Quieres escribir las frecuencias en el fichero " << argv[1] << "? (S/N) ";

    cin >> opcion; 
    if ( toupper(opcion) ==  'S' ) {
        if (letras.export_frecuencias( argv[1] ) )
            cout << "\nArchivo guardado correctamente\n";
        else
            cout << "\nNo se ha podido guardar el archivo\n";
    }
    
    return 0;
}