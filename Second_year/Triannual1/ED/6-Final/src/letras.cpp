#include "letras.h"
#include <sstream>
using namespace std;

//
// ─── CONSTRUCTORES ──────────────────────────────────────────────────────────────
//

    Bolsa_Letras::Bolsa_Letras (    Diccionario  dic
                                ,   unsigned int num_letras ) {

        this->diccionario = dic;
        
        calculate_frequency();
        calculate_score();
        
        generate_random_letters( num_letras );   
    }


    
    Bolsa_Letras::Bolsa_Letras (    Diccionario dic
                                ,   unsigned int score[26]  
                                ,   unsigned int frec[26]   
                                ,   unsigned int num_letras ) {

        this->diccionario = dic;

        for ( size_t i = 0; i < 26; ++i ) {
            puntuaciones[i] = score[i];
            frecuencia[i]   = frec[i];
        }

        generate_random_letters( num_letras );

    }


    
    Bolsa_Letras::Bolsa_Letras ( const Bolsa_Letras& otro ) {
        *this = otro;
    }

//
// ─── METODOS PRIVADOS ───────────────────────────────────────────────────────────
//

    void Bolsa_Letras::calculate_score () {
        long int total_letras = 0;

        int maximo = 0, minimo = 100000;

        for ( size_t i = 0; i < 26; ++i ) {
            total_letras += frecuencia[i];
            
            if ( frecuencia[i] > maximo)
                maximo = frecuencia[i];
            
            if ( frecuencia[i] < minimo )
                minimo = frecuencia[i];
        }
        
        if ( total_letras != 0)
            for ( size_t i = 0; i < 26; ++i ) {
                if ( frecuencia[i] != 0 ) {
                    puntuaciones[i] = ( 1.2*maximo - frecuencia[i] ) / (50*minimo); 

                    // puntuaciones[i] = (1 - frecuencia[i] / total_letras) * 10
                    // FIXME underflow
                }
                else
                    puntuaciones[i] = 0;
             }
    }



    void Bolsa_Letras::calculate_frequency () {
        for ( size_t i = 0; i < 26; ++i )
            frecuencia[i] = 0;

        for ( auto palabra: diccionario )
            for ( auto letra: palabra )
                frecuencia[ toupper(letra) - 65 ]++;
    }  



    bool Bolsa_Letras::load_file ( string archivo ) {
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



    bool Bolsa_Letras::save_file ( string config_file ) {
        ofstream salida ( config_file );

        if ( !salida ) {
            cerr << "No se ha podido crear el archivo de destino";
            return false;
        }

        salida << "#Letra FAbs Puntuación\n";
        
        for ( size_t i = 0; i < 26; ++i ) {
            salida << (char)(i+65) << "  " << frecuencia[i] 
                                   << "  " << puntuaciones[i] << endl;
        }

        return true;
    }

//
// ─── INTERFACES ─────────────────────────────────────────────────────────────────
//

    size_t Bolsa_Letras::get_amount_letters () const {
        return lista_letras.size();
    }

    

    list < char > Bolsa_Letras::get_list_letters () const {
        return lista_letras;
    }


    
    void Bolsa_Letras::get_frecuencias ( int arr[26] ) const {
        for ( int i = 0; i < 26; ++i )
            arr[i] = frecuencia[i];
    }


    
    void Bolsa_Letras::get_puntuaciones ( int arr[26] ) const { 
        for ( int i = 0; i < 26; ++i )
            arr[i] = puntuaciones[i];
    }

    

    unsigned int Bolsa_Letras::get_frecuencia  ( const char letra ) const {
        if ( toupper(letra) - 65 >= 0 && toupper(letra) - 65 <= 25  )
            return frecuencia[ (int)toupper(letra) - 65 ];
        else
            return 0;
    }
    

    
    unsigned int Bolsa_Letras::get_puntuacion  ( const char letra ) const {
        if ( toupper(letra) - 65 >= 0 && toupper(letra) - 65 <= 25  )
            return puntuaciones[ (int)toupper(letra) - 65 ];
        else
            return 0;
    }
    


    Diccionario Bolsa_Letras::get_diccionario () const {
        return diccionario;
    }

//
// ─── CALCULOS ───────────────────────────────────────────────────────────────────
//

    unsigned int Bolsa_Letras::puntuacion_palabra ( string word ) const {
        int sum = 0; 
            
        for ( auto letter: word )
            sum += get_puntuacion( toupper(letter) );
            
        return sum;
    };



    list< string > Bolsa_Letras::search_longest_words ( unsigned int longitud ) const {
        list < string > resultados;
        
        // NOTE La palabra más larga del español tiene 130 letras
        for ( auto max_length = min( longitud, (unsigned int)130 ); 
                   max_length >= 1; --max_length ) {

            for ( auto palabra: diccionario ) {
                if ( palabra.size() != max_length )
                    continue;
                
                if ( can_be_formed(palabra) )
                    resultados.push_back( palabra );
            }

            if ( !resultados.empty() )
                return resultados;
        }

        return resultados;
    }    


    
    list< string > Bolsa_Letras::search_rarest_words () const {
        list < string > resultados;
        int maximo = 0;

        for ( auto palabra: diccionario ) {
            if (    puntuacion_palabra( palabra ) >= maximo  
                &&  can_be_formed( palabra ) ) {
            
                if ( puntuacion_palabra(palabra) > maximo ) {
                    resultados.clear();
                    maximo = puntuacion_palabra(palabra);
                }
                
                resultados.push_back(palabra);
            }
        }

        return resultados;
    }



    bool Bolsa_Letras::pertenece_bolsa ( string palabra ) const {
        return can_be_formed(palabra) && can_be_found(palabra);
    }

    bool Bolsa_Letras::can_be_formed ( string palabra ) const {
        /*
            Para cada letra de la lista de letras, 
            el número de ocurrencias en la palabra debe ser menor o igual que
            las veces que está presente en la lista
        */

        auto letter_belongs_list = [ this ]( char letra ) 
        { 
                return find(   this->lista_letras.begin()
                            ,  this->lista_letras.end() 
                            ,  toupper(letra) ) != lista_letras.end(); 
        };
        
        // Comprobar que la palabra cumple los requisitos de la lista
        if ( !all_of( palabra.begin(), palabra.end(), letter_belongs_list) )
            return false;
        
        int count_palabra, count_lista;
        
        for ( char letra: lista_letras ) {
            count_palabra = count ( palabra.begin(), palabra.end(), tolower(letra) );
            count_lista = count ( lista_letras.begin(), lista_letras.end(), letra );
            
            if ( count_palabra > count_lista ) {
                return false;
            }
        }

        return true;
    }


    bool Bolsa_Letras::can_be_found ( string palabra ) const {
        return diccionario.word_exists( palabra );
    }


    /*
    Supongamos que 
    A 7
    B 5
    C 4
    D 0
    E 3
    F 2
    Z 1

    Se puede interpetrar como 
    A A A A A A A B B B B B C C C C F F Z

    Entonces, se puede generar un número aleatorio con una seed entre [1, 19].
    Sea n un número generado aleatoriamente, n = 9
    Entonces, n => B
    */
    void Bolsa_Letras::generate_random_letters( int numero ) {
        lista_letras.clear();
        
        int cota = 0;
        for ( size_t i = 0; i < 26; ++i )
            cota += frecuencia[ i ];

        mt19937 rng;
        rng.seed(std::random_device()());
        uniform_int_distribution<mt19937::result_type> dist(1, cota); // distribution in range [1, cota]

        int generado;
        int counting;
        bool keep_searching;  

        for ( size_t num = 0; num < numero; ++num ) {
            generado = dist( rng );

            // Reinicializar variables para la ubicación del nuevo elemento
            keep_searching = true;
            counting = 0;

            for ( size_t i = 0; i < 26 && keep_searching; ++i) {
                counting += frecuencia[i];
                
                if ( generado <= counting) {     // Primera ocurrencia
                    lista_letras.push_back( (char)(i + 65) );
                    keep_searching = false;
                }
            }
        }
    }
//
// ─── SOBRECARGA DE OPERADORES ───────────────────────────────────────────────────
//

    Bolsa_Letras& Bolsa_Letras::operator = ( const Bolsa_Letras& otro ) {
        this->diccionario  = otro.diccionario;
        this->lista_letras = otro.lista_letras;

        for ( size_t i = 0; i < 26; ++i ) {
            puntuaciones[i] = otro.puntuaciones[i];
            frecuencia[i]   = otro.frecuencia[i];
        }

        return *this;
    }



    ostream& operator << ( ostream& os, const Bolsa_Letras& letras ) {
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