/** 
 * @file learn.cpp
 * @author DECSAI
*/

#include <iostream>
#include <cstring>
#include "ContadorBigramas.h"

using namespace std;

/**
 * @brief Imprime mensaje de ayuda
*/
void pinta_mensaje() {
    cout << "Formato:" << endl;
    cout << "learn {-c|-a} [-l nombreIdioma] [-f ficheroSalida] texto1.txt texto2.txt texto3.txt .... " << endl;
    cout << "           aprende el codigo para el lenguaje nombreIdioma a partir de los ficheros texto1.txt texto2.txt texto3.txt ..." << endl;
    cout << endl;
    cout << "Parámetros:" << endl;
    cout << "-c|-a: operación crear fichero de idioma (-c) o añadir a fichero de idioma (-a)" << endl;
    cout << "-I nombreIdioma: idioma (unknown por defecto)" << endl;
    cout << "-f ficheroSalida:  nombre del fichero de salida (out.bgr por defecto)" << endl;
    cout << "texto1.txt texto2.txt texto3.txt ....: nombres de los ficheros de entrada (debe haber al menos 1)" << endl;
}

int main(int argc, char *argv[]) {
	/// Cadena de caracteres válidos de ISO8859-1 para múltiples idiomas
    string valid="abcdefghijklmnopqrstuvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF"; 
    
    if (argc < 3){
        pinta_mensaje();
        return 1;
    }

    char option;
    string idioma           = "unknown";
    string fichero_salida   = "out.bgr";
    
    unsigned int dim_inputs = 0;
    string ficheros_entrada[7];
    
    //Parsing arguments
    for (unsigned int i=0; i<argc; i++){
        if (strcmp(argv[i],"-c") == 0 || strcmp(argv[i],"-a") == 0)
            option = argv[i][1];     
        else if (strcmp(argv[i],"-I") == 0 || strcmp(argv[i],"-l") == 0) //No sé si lo del pdf es una L o una I ¯\_(ツ)_/¯ 
            idioma = argv[i+1];
        else if (strcmp(argv[i],"-f") == 0)
            fichero_salida = argv[i+1];
        else if (strstr(argv[i],".txt") != nullptr){
            ficheros_entrada[dim_inputs] = argv[i];
            dim_inputs++;
        }
    }

    if (option == 'c'){
        ContadorBigramas matriz(valid);
        
        for (unsigned int i=0; i<dim_inputs; i++){
            matriz.calcularFrecuenciasBigramas(ficheros_entrada[i].c_str());
        }

        Idioma nuevo_idioma = matriz.toIdioma();
        nuevo_idioma.setIdioma(idioma);
        nuevo_idioma.ordenar();
        
        nuevo_idioma.salvarAFichero(fichero_salida.c_str());
    }
    else if (option == 'a'){
        //Archivo de texto donde se encuentran almacenados los datos
        bool interruptor = true;
        string recuperacion_datos = "out.bgr";
        
        //Importación
        for (unsigned int i=0; i<argc && interruptor; i++)
            if (strstr(argv[i],".bgr") != nullptr){
                recuperacion_datos = argv[i];
                interruptor = false;
            }

        Idioma nuevo_idioma;
        nuevo_idioma.cargarDeFichero(recuperacion_datos.c_str());

        ContadorBigramas matriz(valid);
        matriz.fromIdioma(nuevo_idioma);

        //Búsqueda de nuevos bigramas y exportación
        for (unsigned int i=0; i<dim_inputs; i++){
            matriz.calcularFrecuenciasBigramas(ficheros_entrada[i].c_str());
        }

        nuevo_idioma = matriz.toIdioma();
        nuevo_idioma.setIdioma(idioma);
        nuevo_idioma.ordenar();
        nuevo_idioma.salvarAFichero(recuperacion_datos.c_str());
    }
    else{
        cerr <<"Error en la lectura de la orden principal. Debes usar -c o -a";
        return 1;
    }

    cout <<"Todo listo. Puedes comprobar el archivo de salida con `more "<<fichero_salida;

   return 0;
}   