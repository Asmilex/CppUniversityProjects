#include <iostream>
using namespace std;

int poder(int a, int b){ //a base, b potencia
    int resultado=a;
    
    for (int i = 0; i<b-1; i++)
        resultado=resultado*a;
    return resultado;

}

int main(){
    int a, b,potencia;

    cout <<"Dame 2 números\n";
    cin >>a>>b;
    
    potencia=poder(a,b);

    cout <<"La potencia vale "<<potencia;
    return 0;    
}