/** 
 * @file main.cpp
 * @author DECSAI
 * @warning Cödigo incompleto
*/
#include <iostream>
#include <cstring>
#include "Bigrama.h"

using namespace std;

int main() {
    char s[60];
    int frec, nv1, nv2, nv3;
    Bigrama *v1=NULL, *v2=NULL, *v3=NULL;
    
    // Lee número de elementos del primer vector
    // Lee el primer vector
   
    // Lee número de elementos del segundo vector
    // Lee el segundo vector
    cout << endl <<"Contenido de v1" << endl; imprimeBigramas(v1, nv1);
    cout << endl <<"Contenido de v2" << endl; imprimeBigramas(v2, nv2);
   
    // Posibles operaciones intermedias sobre v1 o v2 
    
    sumaBigramas(v1, nv1, v2, nv2, v3, nv3);
    ordenaAscFrec(v3, nv3);
    cout << endl <<"Contenido de v3" << endl; imprimeBigramas(v3, nv3);

    // Limpieza de memoria
    return 0;
}

