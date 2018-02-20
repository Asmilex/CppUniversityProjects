#include <iostream>
#include <cmath>

using namespace std;

/**
 * @brief Pasados dos valores, devuleve la suma de ellos siempre que sean racionales
 * @param a: Valor racional 1 a sumar
 * @param b: Valor racional 2 a sumar
 * @return c: Suma de ambos 
 */
double suma(double a, double b){
   double c=a+b;
   return c;
}

/**
 * @brief Resta dos números pertenecientes a Q. El orden es importante. El segundo es que lleva la operación de resta
 * @param a: Pirmer valor a restar. 
 * @param b: Segundo valor a restar.
 * @return c: Valor resultante
*/
double resta(double a,double b){
    double r=a-b;
    return r;
}

/**
 * @brief Producto de dos números racionales
 * @param a: Valor a multiplicar
 * @param b: Otro valor a multiplicar
 * @return m: Multiplicación de ambos
 */
double mult(double a, double b){
    double m=a*b;
    return m;
}
/**
 * @brief calcula el respresentante canónico de 2 números. SE MODIFICARÁN LOS VALORES ASOCIADOS. Precisión de 5 decimales
 * @param can1: Primer representante canónico. SE MODIFICARÁ
 * @param can2: Primer representante canónico. SE MODIFICARÁ
 */
void canonico(double& can1, double& can2){
    int a=can1+1;
    int b=can2+1;
    for (int i=0; i<1000000; i++){
        if (a!=can1)
            can1=can1+0.00001;
        if (b!=can2)
            can2=can2+0.00001;
    }
    

} 

int main(){
    int callvoid;
    double x,y,z,r,m,can1,can2;
    cout <<"Dame un valor de x ";
    cin >>x;
    cout <<"Ahora de y ";
    cin >>y;

    z=suma(x,y);
    r=resta(x,y);
    m=mult(x,y);
    can1=x;
    can2=y;
    canonico(can1,can2);

    cout <<"La suma vale "<<z<<"\nLa resta de ambos vale "<<r<<"\nEl producto vale "<<m<<"\nLos representantes canónicos son  "<<can1<<" y "<<can2;
    return 0;
}