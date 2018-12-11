#include "letras.h"
#include <sstream>
using namespace std;

//
// ─── CONSTRUCTORES ──────────────────────────────────────────────────────────────
//

    Letras::Letras (    string       archivo
                    ,   unsigned int num_letras ) {

        load_file( archivo );
        generate_random_letters( num_letras );   
    }

    
    Letras::Letras (    unsigned int score[26]  
                    ,   unsigned int frec[26]   
                    ,   unsigned int num_letras ) {

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
            return false;
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

                while ( !ss.eof() )  {
                    ss >> temp;

                    if ( stringstream(temp) >> valor && is_frec ) {
                        this->frecuencia[ index ] = valor;
                        is_frec = false;
                    }
                    else if ( is_frec == false ) {
                        this->puntuaciones [ index ] = valor;
                        is_frec = true;
                    }

                    temp = "";
                }
            }       

            return true;
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
            arr[i] = frecuencia[i];
    }

    
    void Letras::get_puntuaciones ( int arr[26] ) const { 
        for ( int i = 0; i < 26; ++i )
            arr[i] = puntuaciones[i];
    }

    
    unsigned int Letras::get_frecuencia  ( const char letra ) const {
        if ( letra - 65 >= 0 && letra - 65 <= 25  )
            return frecuencia[ (int)toupper(letra) - 65 ];
        else
            return 0;
    }

    
    unsigned int Letras::get_frecuencia  ( const int index  ) const {
        if ( index >= 0 && index <= 25  )
            return frecuencia[ index ];
        else
            return 0;
    }

    
    unsigned int Letras::get_puntuacion  ( const int index  ) const {
        if ( index >= 0 && index <= 25  )
            return puntuaciones[ index ];
        else
            return false;
    }

    
    unsigned int Letras::get_puntuacion  ( const char letra ) const {
        if ( letra - 65 >= 0 && letra - 65 <= 25  )
            return puntuaciones[ (int)toupper(letra) - 65 ];
        else
            return 0;
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

    // FIXME no mira disponibilidad de letras
    list< string > Letras::search_longest_words ( unsigned int longitud ) const {
        list < string > resultados;
        
        auto letter_belongs_list = [ this ]( char letra ) 
        { 
                return find(   this->lista_letras.begin()
                            ,  this->lista_letras.end() 
                            ,  toupper(letra) ) != lista_letras.end(); 
        };

        // La palabra más larga del español tiene 130 letras
        auto max_length = min(longitud, (unsigned int) 130);

        for ( max_length; max_length >= 1; --max_length ) {
            for ( auto palabra: diccionario ) {
                if ( palabra.size() != max_length )
                    continue;
                
                if ( all_of( palabra.begin(), palabra.end(), letter_belongs_list ) )
                    resultados.push_back( palabra );
            }

            if ( !resultados.empty() )
                return resultados;
        }

        return resultados;
    }    

    
    list< string > Letras::search_rarest_words ( unsigned int puntuacion ) const {
        list < string > resultados;

        auto letter_belongs_list = [ this ]( char letra ) 
        { 
                return find(   this->lista_letras.begin()
                            ,  this->lista_letras.end() 
                            ,  toupper(letra) ) != lista_letras.end(); 
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

    void Letras::generate_random_letters( int numero ) {
        lista_letras.clear();
        
        mt19937 rng;
        rng.seed(std::random_device()());
        uniform_int_distribution<mt19937::result_type> dist(65,90); // distribution in range [1, 6]
        
        int* frecuencia_disponible = new int [26];
        for ( size_t i = 0; i < 26; ++i )
            frecuencia_disponible[ i ] = frecuencia[ i ];

        char letra;

        size_t errors     = 0;
        size_t max_errors = 100000;

        /*
            NOTE Buscaremos letras disponibles hasta que no se pueda encontrar ninguna otra
            Esto, ahora mismo, está implementado como una tasa de errores máxima que asegura
            en media la capacidad de conseguir las disponibles

            Conforme más letras se pide, peor funciona. Es probable que deba cambiar esta función
            Pero como de momento funciona, se queda
        */
        for ( int i = 0; i < numero && errors < max_errors; ++i ) {
            letra = (char)dist( rng );

            if ( frecuencia_disponible[ letra - 65 ] > 0 ) { 
                --frecuencia_disponible[ letra - 65 ];         
                lista_letras.push_back( letra );               
            }
            else {
                errors++;
            }
        }

        delete [] frecuencia_disponible;
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

        return *this;
    }

    ostream& operator << ( ostream& os, const Letras& letras ) {
        os << "Letras generadas:\n";
        
        for ( auto letra: letras.lista_letras )
            os << letra << " ";
        
        os << "\nLetra | Puntuación | Frecuencia:\n";
    
        for ( char letra = 'A'; letra <= 'Z'; ++letra ) {
            os << letra << " " << letras.get_puntuacion( letra )
                        << " " << letras.get_frecuencia( letra ) << endl;
        }

        return os;
    }