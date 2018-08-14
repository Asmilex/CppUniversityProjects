#include <iostream>
#include <cstring>

using namespace std;

//Dejo fuera las constantes porque son universales. En vez de pasarlas a la función como parámetro, las pongo globales y ya
const int MAX_CHAR = 100;
const int MAX_WORD = 20;

int EncuentraCaracteres(char * const caracteres, char ** palabras){//Lleva 2 asteriscos porque es un puntero a punteros. No estoy seguro de si esto se debe hacer así. Ese const debe ir ahí sí o sí. Prueba a moverlo si quieres
    unsigned int j = 0;
    
    for (int i=0; i<MAX_CHAR; i++){
        while (caracteres[i] == ' '){                               //Así nos quitamos problemas de espacios múltiples
            i++;
        }
        
        if (i == 0){                                      //El caso más problemático es el primero. Como no podemos mirar el anterior (i-1), lo soluciono así 
            palabras[j] = &caracteres[i];
            j++;
        }
        if (i>0 && caracteres[i-1] == ' ' && j < MAX_WORD){         //j!=0 => no se solapa con la solución de arriba; j<MAX_WORD => no se saldrá del vector
            palabras[j] = &caracteres[i];               
            j++;
        }
    }
    if (j == MAX_WORD - 1)
        cout <<"Vector de palabras lleno";
    else
        palabras[j] = nullptr;

    return j;
}

int main(){
    char caracteres[MAX_CHAR];
    char * palabras[MAX_WORD]; //El asterisc denota que es un puntero

    //Recuerda que los propios arrays son punteros. Osea que, para la línea 32, palabras es un puntero a punteros
    
    cout <<"Mete la peaso cadena: ";
    cin.getline(caracteres, MAX_CHAR);

    int longitud_palabras = EncuentraCaracteres(caracteres, palabras);
    
    for (int i=0; i < MAX_WORD && palabras[i] != nullptr; i++) //[1]
        cout <<*palabras[i]<<" "; //El asterisco indica que se imprime el valor

    //Para sacar la dirección de un puntero, usa puntero
    //Para sacar el valor, usa *puntero 
    }
