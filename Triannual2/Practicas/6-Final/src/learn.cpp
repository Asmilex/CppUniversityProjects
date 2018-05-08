/** 
 * @file learn.cpp
 * @author DECSAI
*/

#include <iostream>
#include <cstring>

/// ... Resto de include

using namespace std;

/**
 * @brief Imprime mensaje de ayuda
*/
void pinta_mensaje() {
    cout << "Formato:" << endl;
    cout << "learn {-c|-a} [-t|-b] [-l nombreIdioma] [-f ficheroSalida] texto1.txt texto2.txt texto3.txt .... " << endl;
    cout << "           aprende el codigo para el lenguaje nombreIdioma a partir de los ficheros texto1.txt texto2.txt texto3.txt ..." << endl;
    cout << endl;
    cout << "Parámetros:" << endl;
    cout << "-c|-a: operación crear fichero de idioma (-c) o añadir a fichero de idioma (-a)" << endl;
    cout << "-l nombreIdioma: idioma (unknown por defecto)" << endl;
    cout << "-f ficheroSalida:  nombre del fichero de salida (salida.bgx por defecto)" << endl;
    cout << "texto1.txt texto2.txt texto3.txt ....: nombres de los ficheros de entrada (debe haber al menos 1)" << endl;
}

int main(int argc, char *argv[]) {
	/// Cadena de caracteres válidos de ISO8859-1 para múltiples idiomas
    string valid="abcdefghijklmnopqrstuvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF"; 

	/// ... Resto de variables y código de main
   return 0;
}
