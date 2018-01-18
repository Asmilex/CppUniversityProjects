#include <iostream>
#include <vector>
using namespace std;

class SecuenciasSilimilares{
private:
    string cadena1, cadena2;
    int tamano1 = cadena1.size();
    int tamano2 = cadena2.size();
public: 
    SecuenciasSilimilares(){
        QueryDefecto();
        cin >>cadena1;
        cin >>cadena2;
    };

    SecuenciasSilimilares(string primera_cadena; string segunda_cadena){
        cadena1 = primera_cadena;
        cadena2 = segunda_cadena;
    }

    void QueryDefecto(){
        cout <<"introduce la primera cadena. Escribe #cuando quieres que termine";
    }

}

int main(){

}