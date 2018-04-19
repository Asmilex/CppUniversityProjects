/**
 * @file main.cpp
 * @author DECSAI
 * @warning Código incompleto. Completar donde se indica
*/
#include <iostream>
#include <cstring>
#include "Bigrama.h"
#include "Idioma.h"
using namespace std;

int main(int narg, char * args[]) {
    /// Completar variables

    if (narg  < 3)  {
        cerr << "Error en la llamada.\n   idioma <bigrama> <fich1.bgr> <fich2.bgr> ..."<<endl;
        return 1;
    }
    //La idea es cargar todos los ficheros, y después tratar con ellos

    /// Completar el main
    return 0;
}