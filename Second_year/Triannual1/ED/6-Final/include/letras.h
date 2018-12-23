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

    static const unsigned int default_random_letters = 0;

//
// ─── METODOS PRIVADOS ───────────────────────────────────────────────────────────
//

    /**
     * @brief Dada una frecuencia, calcula la puntuación asociada
     * El resultado se ve reflejado en el objeto puntuaciones
     */
    void calculate_score ();

    /**
     * @brief Calcula las frecuencias asociadas para cada letra
     * El resultado se obtiene dadas las entradas del diccionario
     */
    void calculate_frequency ();

    /**
     * @brief Carga las frecuencias y las puntuaciones reflejadas en el archivo
     * @param config_file Archivo a cargar
     * Formato del archivo: 
            #Letra Cantidad Puntos
            A   12   1
            ...
     * @return true si se ha conseguido. Si ha habido fallos, false
     */
    bool load_file ( const string config_file );

public:

//
// ─── CONSTRUCTORES ──────────────────────────────────────────────────────────────
//

    /**
     * @brief Constructor por parámetros. 
     * @param dic Diccionario a cargar
     * @param num_letras Número de letras a generar
     * @note Las frecuencias y las puntuaciones se consiguen a partir del diccionario
     */
    Bolsa_Letras (    const Diccionario  dic
                  ,   const unsigned int num_letras = default_random_letters );
    
    /**
     * @brief Constructor parametrizado
     * @param dic Diccionario a usar
     * @param score Puntuaciones de las letras
     * @param frec Frecuencia de las letras
     * @param num_letras Número de letras a generar
     */
    Bolsa_Letras (    const Diccionario dic
                  ,   const unsigned int score[26]
                  ,   const unsigned int frec[26] 
                  ,   const unsigned int num_letras = default_random_letters );

    /**
     * @brief Constructor de carga de archivo
     * @param dic Diccionario a cargar
     * @param config_file Archivo a abrir para cargar su contenido
     * @param n Número de letras a generar
     * Este tiene la estructura indicada en la función load_file
     */
    Bolsa_Letras (    const Diccionario dic
                  ,   const string file
                  ,   const int n = default_random_letters );

    /**
     * @brief Constructor de copia
     * @param otro Objeto a copiar
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
     * @brief Devuelve la cantidad de letras almacenadas
     * @return El número de letras generadas aleatoriamente
     */
    size_t get_amount_letters () const;

    /**
     * @brief Devuelve la lista de letras almacenadas
     * @return Listado de letras
     */
    list < char > get_list_letters () const;

    /**
     * @brief Devuelve la lista de frecuencias total
     * @param arr Array donde almacenarlas
     */
    void get_frecuencias ( int arr[26] )      const;
   
    /**
     * @brief Devuelve la lista de puntuaciones total
     * @param arr Array donde almacenarlas
     */
    void get_puntuaciones( int arr[26] )      const; 
    
    /**
     * @brief Devuelve la frecuencia de una letra en específico
     * @return Frecuencia de la letra
     */
    unsigned int get_frecuencia  ( const char letra ) const;

    /**
     * @brief Devuelve la puntuación de una letra en específico
     * @return Frecuencia de la letra
     */
    unsigned int get_puntuacion  ( const char letra ) const;

    /**
     * @brief Devuelve el diccionario cargado
     * @return El diccionario
     */
    Diccionario get_diccionario () const;

    /**
     * @brief Guarda la frecuencia y la puntuación de cada letra
     * @param config_file Archivo donde guardar
     * @return true si ha funcionado, false si ha habido errores
     */
    bool save_file ( const string config_file ) const;

    /**
     * @brief Exporta las frecuencias absolutas y relativas al archivo indicado
     * @param export_file 
     */
    bool export_frecuencias ( const string file ) const;

//
// ─── CALCULOS ───────────────────────────────────────────────────────────────────
//

    /**
     * @brief Genera un cierto número de letras aleatorias a partir de la frecuencia
     * @param numero Cuántas letras generar
     */
    void generate_random_letters ( const int numero );
    
    /**
     * @brief Busca las palabras más largas posibles según al lista de letras
     * @param longitud Longitud máxima que buscar
     * @return :as palabras más largas
     */
    list< string > search_longest_words ( const unsigned int longitud ) const;

    /**
     * @brief Busca las palabras más raras atentiendo a las puntuaciones
     * @return La lista de palabras con mayor puntuación
     */
    list< string > search_rarest_words () const;

    /**
     * @brief Muestra si una palabra está en el diccionario 
     *  y cumple los requisitos de la lista de letras
     * @param palabra Palabra a comprobar
     * @return true si está dentro, false si no
     */
    bool pertenece_bolsa ( const string palabra ) const;

    /**
     * @brief Comprueba que una palabra puede formarse atentiendo a la lista de letras generada
     * @return true si se puede; si no, false
     */
    bool can_be_formed ( const string palabra ) const;

    /**
     * @brief Comprueba que una palabra está en el diccionario cargado
     * @return true si se puede; si no, false
     */
    bool can_be_found ( const string palabra ) const;

    /**
     * @brief Devuelve la puntuación de una palabra
     * @param word Palabra a sacar la puntuación
     * @return La puntuación de la palabra
     */
    unsigned int puntuacion_palabra ( const string word ) const;
    
//
// ─── SOBRECARGA DE OPERADORES ───────────────────────────────────────────────────
//

    Bolsa_Letras& operator = ( const Bolsa_Letras& otro );

    friend ostream& operator << ( ostream& os, const Bolsa_Letras& letras );
};

ostream& operator << ( ostream& os, const Bolsa_Letras& letras );

#include "../src/letras.cpp"
#endif