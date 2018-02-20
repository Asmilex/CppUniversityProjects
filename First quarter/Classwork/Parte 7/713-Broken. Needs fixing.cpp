#include <vector>
#include <string>
#include <iostream>
using namespace std;

int Lectura(vector<string> & nombres, vector<string> & apellidos){ //La posición 0 no sirve para nada. Ignórala
    int acu=0;
    while (nombres[acu]!="#"){
        cout <<"Persona "<<acu+1<<". Nombre:  ";
        string Aux;
        getline(cin,Aux);
        nombres.push_back(Aux);

        if (nombres[acu+1]!="#"){
            cout <<"Apellidos: ";
            getline(cin, Aux);
            apellidos.push_back(Aux);
        }    

        acu++; 
    
    }
      cout <<nombres[1]<<apellidos[1];

      return acu;

}

void OrdenadorPrint(vector<string> vectorcillo){ //No tengo huevos a sacar esto. Se supone que debe ir recorriendo los caracteres e ir sacando los menores
    int SelectorOrden=0;
    for (int i=0; i<vectorcillo.size(); i++)
        vectorcillo[i]=toupper(vectorcillo[i]);


    for (unsigned int MovString=0; MovString<vectorcillo.size(); MovString++){
        for (unsigned int MovCaracter=1; MovCaracter<vectorcillo[string].size(); MovCaracter++){    //La posición 0 se va a reservar para indicar el orden
            if (string>0){
                if (vectorcillo[MovString][MovCaracter]>)
            }
        } 
    }
}

int main(){
    vector<string> nombres(1);
    vector<string> apellidos(1);

    Lectura(nombres, apellidos);

    OrdenadorPrint(nombres);
    return 0;
}