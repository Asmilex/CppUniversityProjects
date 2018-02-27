#include <iostream>
#include <vector>
using namespace std;

class TablaTemperaturas{
private:
    const int filas = 10; 
    const int columnas = 24;
    vector<vector<double>> matriz;
public:
    TablaTemperaturas(){
        matriz[filas][columnas];
    };

    double Valor(unsigned int indice, unsigned int hora){
        bool comprobaciones = 1;
        
        if (indice < 0 || indice > 9 || hora < 0 || hora > 23)
            comprobaciones = 0;
        if (comprobaciones)
            return matriz[indice][hora];
    }


};



int main(){
    return 0;
}
