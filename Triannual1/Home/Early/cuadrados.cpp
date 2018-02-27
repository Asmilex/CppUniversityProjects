#include <iostream>
using namespace std;

int main(){
    int lado;
    cout <<"Introduzca la dimensión del lado, en unidades ";
    cin >>lado;

    for (int i=1; i<=lado*lado; i++){
        cout <<"*";
        if (i%lado == 0 )
            cout <<"\n";
    }
    return 0;
}