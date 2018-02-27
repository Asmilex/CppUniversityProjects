#include <iostream>
using namespace std;

int poder(int a, int b){ //a base, b potencia
    int resultado=a;
    
    for (int i = 0; i<b-1; i++)
        resultado=resultado*a;
    return resultado;

}

double Evaluar(double a, double b, double c, double d, double x){
    return a*poder(x,3) + b*poder(x,2) + c*x + d;
}

int main(){
    double a,b,c,d,x,resultado;
    
    cout <<"Dame los valores a b c d\n";
    cin >>a>>b>>c>>d; 
    cout <<"¿En qué punto se va a evaluar la función?\n";
    cin >>x;

    resultado=Evaluar(a,b,c,d,x);
    cout <<"El resultado es "<<resultado;
    
    return 0;
}