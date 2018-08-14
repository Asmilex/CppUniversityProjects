#include <iostream>
using namespace std;

int mcd(int a, int b){
    int r=a%b;

    while (r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int mcm(int a, int b){
    int resultado, valmcd;
    valmcd=mcd(a,b);

    resultado=(a*b)/valmcd;

    return resultado;
}

int main(){
    int a, b, valmcd, valmcm;

    cout <<"Dame 2 números\n";
    cin >>a>>b;
    
    valmcd=mcd(a,b);
    valmcm=mcm(a,b);

    cout <<"El máximo común divisor es "<<valmcd<<" y el mínimo común múltiplo "<<valmcm;

    return 0;
}