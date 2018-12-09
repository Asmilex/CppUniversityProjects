#include "letras.h"
#include <sstream>
using namespace std;

//
// ─── CONSTRUCTORES ──────────────────────────────────────────────────────────────
//

    Letras::Letras (    string       archivo
                    ,   unsigned int num_letras = default_random_letters ) {

        load_file( archivo );
        generate_random_letters( num_letras );   
    }

    
    Letras::Letras (    unsigned int score[26]  = {0}
                    ,   unsigned int frec[26]   = {0}
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

        lista_letras.clear();

        for ( int i = 0; i < numero; ++i )
            lista_letras.push_back( (char)dist6(rng) );
        
    }

    
    bool Letras::load_file ( string archivo ) {
        /*
            Estructura:
            
            #Letra Cantidad Puntos
            A   12   1
            ...
        */

        ifstream f ( archivo );

        if ( !f ) {
            cerr << "No se ha podido abrir el archivo";
        }
        else {
            string linea;

            while ( getline(f, linea, '\n') ) {
                if ( linea[0] == '#' )      //Ignorar primra línea
                    continue;
                
                size_t index = (char) linea[0] - 65;
                // NOTE A == 65. Traslación
                // https://ascii.cl/

                if ( index < 0 || index > 25) {
                    cerr << "Error en el archivo de configuración";
                    break;
                }

                stringstream ss;        
                ss << linea;
                
                string temp;            // Extracción subcadenas

                int valor;               
                bool is_frec = true;   

                /*
                    Como la estructura es letra - frecuencia - puntuación,
                    iremos metiendo por orden
                */      

                while ( !ss.eof() )
                    ss >> temp;

                    if ( stringstream(temp) >> valor && is_frec ) {
                        this->frecuencia[ index ] = valor;
                        is_frec = false;
                    }
                    else if ( is_frec == false )
                        this->puntuaciones [ index ] = valor;
                        is_frec = true;

                    temp = "";
            }       
        }
    }    

//
// ─── INTERFACES ─────────────────────────────────────────────────────────────────
//

    size_t Letras::get_amount_letters () const {
        return lista_letras.size();
    }

    
    list < char > Letras::get_list_letters () const {
        return lista_letras;
    }

    
    void Letras::get_frecuencias ( int arr[26] ) const {
        for ( int i = 0; i < 26; ++i )
            arr[i] = frecuencia[26];
    }

    
    void Letras::get_puntuaciones ( int arr[26] ) const { 
        for ( int i = 0; i < 26; ++i )
            arr[i] = puntuaciones[26];
    }

    
    unsigned int Letras::get_frecuencia  ( const char letra ) const {
        return frecuencia[ (int)toupper(letra) - 65 ];
    }

    
    unsigned int Letras::get_frecuencia  ( const int index  ) const {
        return frecuencia[ index ];
    }

    
    unsigned int Letras::get_puntuacion  ( const int index  ) const {
        return puntuaciones[ index ];
    }

    
    unsigned int Letras::get_puntuacion  ( const char letra ) const {
        return puntuaciones[ (int)toupper(letra) - 65 ];
    }

    
    void Letras::load_diccionario ( const Diccionario& dic ) {
        this->diccionario = dic;
    }

    
    Diccionario Letras::get_diccionario () const {
        return diccionario;
    }

//
// ─── CALCULOS ───────────────────────────────────────────────────────────────────
//

    unsigned int Letras::puntuacion_palabra ( string word ) const {
        int sum = 0; 
            
        for ( auto letter: word )
            sum += get_puntuacion( letter );
            
        return sum;
    };

    
    list< string > Letras::search_longest_words ( unsigned int longitud ) const {
        list < string > resultados;
        
        auto letter_belongs_list = [ this ]( char letra ) 
        { 
                return find(   this->lista_letras.begin()
                            ,  this->lista_letras.end() 
                            ,  letra ) != lista_letras.end(); 
        };

        for ( auto palabra: diccionario ) {
            if ( palabra.size() != longitud )
                continue;
            
            
            if ( all_of( palabra.begin(), palabra.end(), letter_belongs_list ) )
                resultados.push_back( palabra );
        }

        return resultados;
    }    

    
    list< string > Letras::search_rarest_words ( unsigned int puntuacion ) const {
        list < string > resultados;

        auto letter_belongs_list = [ this ]( char letra ) 
        { 
                return find(   this->lista_letras.begin()
                            ,  this->lista_letras.end() 
                            ,  letra ) != lista_letras.end(); 
        };

        // REVIEW solución poco eficiente. 
        // Primero consigues la puntuación de ciertas palabras, luego las buscas de nuevo
        
        // Cacheamos puntuaciones
        int maximo = 0;

        for ( auto palabra: diccionario ) {
            if (    puntuacion_palabra( palabra ) > maximo  
                &&  all_of( palabra.begin(), palabra.end(), letter_belongs_list ) ) {
                    
                maximo = puntuacion_palabra( palabra );
            }
        }   

        // Buscamos las palabras adecuadas
        for ( auto palabra: diccionario ) {
            if (    puntuacion_palabra( palabra ) == maximo  
                &&  all_of( palabra.begin(), palabra.end(), letter_belongs_list ) ) {
                    
                resultados.push_back( palabra );
            }
        }

        return resultados;
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