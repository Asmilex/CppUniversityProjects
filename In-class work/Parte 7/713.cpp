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
            cout <<"\nApellidos: ";
            getline(cin, Aux);
            apellidos.push_back(Aux);
        }    

        acu++; 
    
    }
      cout <<nombres[1]<<apellidos[1];

      return acu;

}

int main(){
    vector<string> nombres(1);
    vector<string> apellidos(1);

    Lectura(nombres, apellidos);
    return 0;
}