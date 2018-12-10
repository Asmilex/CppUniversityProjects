#ifndef _LETRAS_H_
#define _LETRAS_H_

#include <iostream>
#include <list>
#include <string>
#include <random>           // Generar letras
#include <fstream>          // ifstream
#include <algorithm>        // all_of
#include "diccionario.h"
using namespace std;

//
// ──────────────────────────────────────────────────────────────── I ──────────
//   :::::: C L A S E   L E T R A S : :  :   :    :     :        :          :
// ──────────────────────────────────────────────────────────────────────────
//

class Letras { 
private:

    Diccionario diccionario;
    list < char > lista_letras      = {0};
    unsigned int  puntuaciones [26] = {0};  // NOTE ordenadas de A - Z. Sin Ñ
    unsigned int  frecuencia   [26] = {0};

    static const unsigned int default_random_letters = 8;
//
// ─── METODOS PRIVADOS ───────────────────────────────────────────────────────────
//

    bool load_file ( string archivo );
    void generate_random_letters ( int numero );


public:

//
// ─── CONSTRUCTORES ──────────────────────────────────────────────────────────────
//

    /**
     * @brief constructor por defecto sobrecargado
     * @param score: puntuaciones de las letras
     * @param frec: frecuencia de las letras
     * @num_letras: número de letras a generar
     */
    Letras (    unsigned int score[26]  = {0}
            ,   unsigned int frec[26]   = {0}
            ,   unsigned int num_letras = default_random_letters );
    
    /**
     * @brief: constructor por parámetros. Carga un archivo
     * @param archivo: archivo a cargar
     * @param num_letras: número de letras a generar
     */
    Letras (    string       archivo
            ,   unsigned int num_letras = default_random_letters );

    /**
     * @brief constructor de copia
     */
    Letras ( const Letras& otro );

    /**
     * @brief destructor
     */
    ~Letras () = default;

//
// ─── INTERFACES ─────────────────────────────────────────────────────────────────
//

    /**
     * @brief: devuelve la cantidad de letras almacenadas
     */
    size_t get_amount_letters () const;

    /**
     * @brief: devuelve la lista de letras almacenadas
     */
    list < char > get_list_letters () const;

    void         get_frecuencias ( int arr[26] )      const;
    void         get_puntuaciones( int arr[26] )      const; 
    unsigned int get_frecuencia  ( const char letra ) const;
    unsigned int get_frecuencia  ( const int index  ) const;
    unsigned int get_puntuacion  ( const int index  ) const;
    unsigned int get_puntuacion  ( const char letra ) const;


    void load_diccionario ( const Diccionario& dic );

    Diccionario get_diccionario () const;

//
// ─── CALCULOS ───────────────────────────────────────────────────────────────────
//

    list< string > search_longest_words ( unsigned int longitud ) const;

    list< string > search_rarest_words ( unsigned int puntuacion ) const;

    unsigned int puntuacion_palabra ( string word ) const;
    
//
// ─── SOBRECARGA DE OPERADORES ───────────────────────────────────────────────────
//

    Letras& operator = ( const Letras& otro );

    friend ostream& operator << ( ostream& os, const Letras& letras );
};

ostream& operator << ( ostream& os, const Letras& letras );

#include "../src/letras.cpp"
#endif