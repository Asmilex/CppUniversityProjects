#include "letras.h"
using namespace std;

//
// ─── CONSTRUCTORES ──────────────────────────────────────────────────────────────
//

    Letras::Letras (    string archivo = "../files/letras.txt"
                    ,   unsigned int num_letras = default_random_letters ) {

        load_file( archivo );
        generate_random_letters( num_letras );   
    }

    
    Letras::Letras (    unsigned int score[26]
                    ,   unsigned int frec[26]
                    ,   unsigned int num_letras = default_random_letters ) {

        for ( size_t i = 0; i < 26; ++i ) {
            puntuaciones[i] = score[i];
            frecuencia[i]   = frec[i];
        }

        generate_random_letters( num_letras );

    }

    
    Letras::Letras ( const Letras& otro ) {
        *this = otro;
    }

//
// ─── METODOS PRIVADOS ───────────────────────────────────────────────────────────
//

    void Letras::generate_random_letters( int numero ) {
        mt19937 rng;
        rng.seed(std::random_device()());
        uniform_int_distribution<mt19937::result_type> dist6(65,90); // distribution in range [1, 6]

        for ( int i = 0; i < numero; ++i )
            lista_letras.push_back( (char)dist6(rng) );
        
    }

//
// ─── SOBRECARGA DE OPERADORES ───────────────────────────────────────────────────
//

    Letras& Letras::operator = ( const Letras& otro ) {
        this->diccionario  = otro.diccionario;
        this->lista_letras = otro.lista_letras;

        for ( size_t i = 0; i < 26; ++i ) {
            puntuaciones[i] = otro.puntuaciones[i];
            frecuencia[i]   = otro.frecuencia[i];
        }
    }