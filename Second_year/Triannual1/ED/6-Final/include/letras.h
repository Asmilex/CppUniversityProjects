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

class Bolsa_Letras { 
private:

    Diccionario diccionario;
    
    list < char > lista_letras      = {0};
    unsigned int  puntuaciones [26] = {0};  // NOTE ordenadas de A - Z. Sin Ñ
    unsigned int  frecuencia   [26] = {0};

    static const unsigned int default_random_letters = 8;

//
// ─── METODOS PRIVADOS ───────────────────────────────────────────────────────────
//

    /**
     * @brief: dada una frecuencia, calcula la puntuación asociada
     * El resultado se ve reflejado en el objeto puntuaciones
     */
    void calculate_score ();

    /**
     * @brief: calcula las frecuencias asociadas para cada letra
     * El resultado se obtiene dadas las entradas del diccionario
     */
    void calculate_frequency ();

    /**
     * @brief: carga las frecuencias y las puntuaciones reflejadas en el archivo
     * @param config_file: archivo a cargar
     * Formato del archivo: 
            #Letra Cantidad Puntos
            A   12   1
            ...
     * @return: true si se ha conseguido. Si ha habido fallos, false
     */
    bool load_file ( string config_file );

public:

//
// ─── CONSTRUCTORES ──────────────────────────────────────────────────────────────
//

    /**
     * @brief: constructor por parámetros. 
     * @param dic: 
     * @param num_letras: número de letras a generar
     * @note Las frecuencias y las puntuaciones se consiguen a partir del diccionario
     */
    Bolsa_Letras (    Diccionario  dic
                  ,   unsigned int num_letras = default_random_letters );
    
    /**
     * @brief constructor parametrizado
     * @param dic: diccionario a usar
     * @param score: puntuaciones de las letras
     * @param frec: frecuencia de las letras
     * @param num_letras: número de letras a generar
     */
    Bolsa_Letras (    Diccionario dic
                  ,   unsigned int score[26]
                  ,   unsigned int frec[26] 
                  ,   unsigned int num_letras = default_random_letters );

    /**
     * @brief constructor de copia
     * @param otro: objeto a copiar
     */
    Bolsa_Letras ( const Bolsa_Letras& otro );

    /**
     * @brief destructor
     */
    ~Bolsa_Letras () = default;

//
// ─── INTERFACES ─────────────────────────────────────────────────────────────────
//

    /**
     * @brief: devuelve la cantidad de letras almacenadas
     * @return: el número de letras generadas aleatoriamente
     */
    size_t get_amount_letters () const;

    /**
     * @brief: devuelve la lista de letras almacenadas
     * @return: listado de letras
     */
    list < char > get_list_letters () const;

    /**
     * @brief: devuelve la lista de frecuencias total
     * @param arr: array donde almacenarlas
     */
    void get_frecuencias ( int arr[26] )      const;
   
    /**
     * @brief: devuelve la lista de puntuaciones total
     * @param arr: array donde almacenarlas
     */
    void get_puntuaciones( int arr[26] )      const; 
    
    /**
     * @brief devuelve la frecuencia de una letra en específico
     * @return: frecuencia de la letra
     */
    unsigned int get_frecuencia  ( const char letra ) const;

    /**
     * @brief devuelve la puntuación de una letra en específico
     * @return: frecuencia de la letra
     */
    unsigned int get_puntuacion  ( const char letra ) const;

    /**
     * @brief Devuelve el diccionario cargado
     * @return El diccionario
     */
    Diccionario get_diccionario () const;

    /**
     * @brief Guarda la frecuencia y la puntuación de cada letra
     * @param config_file: archivo donde guardar
     * @return true si ha funcionado, false si ha habido errores
     */
    bool save_file ( string config_file );

//
// ─── CALCULOS ───────────────────────────────────────────────────────────────────
//

    /**
     * @brief Genera un cierto número de letras aleatorias a partir de la frecuencia
     * @param numero: cuántas letras generar
     */
    void generate_random_letters ( int numero );
    
    /**
     * @brief busca las palabras más largas posibles según al lista de letras
     * @param longitud: longitud máxima que buscar
     * @return las palabras más largas
     */
    list< string > search_longest_words ( unsigned int longitud ) const;

    /**
     * @brief busca las palabras más raras atentiendo a las puntuaciones
     * @return la lista de palabras con mayor puntuación
     */
    list< string > search_rarest_words () const;

    /**
     * @brief Muestra si una palabra está en el diccionario 
     *  y cumple los requisitos de la lista de letras
     * @param palabra: palabra a comprobar
     * @return true si está dentro, false si no
     */
    bool pertenece_bolsa ( string palabra ) const;

    bool can_be_formed ( string palabra ) const;
    bool can_be_found ( string palabra ) const;

    /**
     * @brief Devuelve la puntuación de una palabra
     * @param word palabra a sacar la puntuación
     * @return la puntuación de la palabra
     */
    unsigned int puntuacion_palabra ( string word ) const;
    
//
// ─── SOBRECARGA DE OPERADORES ───────────────────────────────────────────────────
//

    Bolsa_Letras& operator = ( const Bolsa_Letras& otro );

    friend ostream& operator << ( ostream& os, const Bolsa_Letras& letras );
};

ostream& operator << ( ostream& os, const Bolsa_Letras& letras );

#include "../src/letras.cpp"
#endif