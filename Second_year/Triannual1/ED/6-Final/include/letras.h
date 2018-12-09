#ifndef _LETRAS_H_
#define _LETRAS_H_

#include <iostream>
#include <list>
#include <string>
#include <random>
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

    void load_file ( string archivo );
    void generate_random_letters ( int numero );




public:

//
// ─── CONSTRUCTORES ──────────────────────────────────────────────────────────────
//

    /**
     * @brief constructor por defecto + parametrizado
     * @param archivo: donde cargar las puntuaciones y las frecuencias
     * @param num_letras: letras aleatorias que generar
     */
    Letras (    string archivo = "../files/letras.txt"
            ,   unsigned int num_letras = default_random_letters );

    /**
     * @brief: constructor 
     */
    Letras (    unsigned int score[26]
            ,   unsigned int frec[26]
            ,   unsigned int num_letras = default_random_letters );
    /**
     * @brief constructor de copia
     */
    Letras ( const Letras& otro );

    /**
     * @brief destructor
     */
    ~Letras ();

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

    unsigned int get_frecuencia ( const char letra );
    unsigned int get_puntuacion ( const char letra );



    void load_diccionario ( const Diccionario& dic );

//
// ─── SOBRECARGA DE OPERADORES ───────────────────────────────────────────────────
//

    Letras& operator = ( const Letras& otro );

    friend ostream& operator << ( ostream& os, const Letras& letras );
};

ostream& operator << ( ostream& os, const Letras& letras );

#endif