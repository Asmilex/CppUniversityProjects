#include <iostream>
#include <cstring>

using namespace std;

//Dejo fuera las constantes porque son universales. En vez de pasarlas a la función como parámetro, las pongo globales y ya
const int MAX_CHAR = 100;
const int MAX_WORD = 20;

struct InfoPalabra{
    char * inicio;
    char * fin;
};

int EncuentraCaracteres(char * const caracteres, InfoPalabra palabras[]){//Lleva 2 asteriscos porque es un puntero a punteros. No estoy seguro de si esto se debe hacer así. Ese const debe ir ahí sí o sí. Prueba a moverlo si quieres
    unsigned int ini = 0, finales = 0;
    
    //Inicio de las palabras
    for (int i=0; i<MAX_CHAR && caracteres[i] != '\0'; i++){
        while (caracteres[i] == ' '){                               //Así nos quitamos problemas de espacios múltiples
            i++;
        }
        
        if (ini == 0 && i == 0){                                      //El caso más problemático es el primero. Como no podemos mirar el anterior (i-1), lo soluciono así 
            palabras[ini].inicio = &caracteres[i];
            ini++;
        }

        if (i>0 && caracteres[i-1] == ' ' && ini < MAX_WORD){         //j!=0 => no se solapa con la solución de arriba; j<MAX_WORD => no se saldrá del vector
            palabras[ini].inicio = &caracteres[i]; 
            ini++;
        }

        if (caracteres[i+1] == '\0'){
            palabras[finales].fin = &caracteres[i];
        } else if (caracteres[i+1] == ' '){
            palabras[finales].fin = &caracteres[i];
            finales++;
        }
    }

    if (ini == MAX_WORD - 1)
        cout <<"Vector de palabras lleno";
    else{
        palabras[ini].inicio = nullptr;
        palabras[ini].fin    = nullptr;

    }


    return ini;
}

int main(){
    char caracteres[MAX_CHAR];
    InfoPalabra palabras[MAX_WORD]; //El asterisc denota que es un puntero

    //Recuerda que los propios arrays son punteros. Osea que, para la línea 32, palabras es un puntero a punteros
    
    cout <<"Mete la peaso cadena: ";
    cin.getline(caracteres, MAX_CHAR);


    int longitud_palabras = EncuentraCaracteres(caracteres, palabras);
    
    cout <<"\nInicio de las palabras: \n";
    for (int i=0; i < MAX_WORD && palabras[i].inicio != nullptr; i++) 
        cout <<*(palabras[i].inicio)<<" "; //El asterisco indica que se imprime el valor


    cout <<"\nFinal de las palabras: \n";
    for (int i=0; i < MAX_WORD && palabras[i].inicio != nullptr; i++) 
        cout <<*(palabras[i].fin)<<" ";
        
    //Para sacar la dirección de un puntero, usa puntero
    //Para sacar el valor, usa *puntero 
    }
