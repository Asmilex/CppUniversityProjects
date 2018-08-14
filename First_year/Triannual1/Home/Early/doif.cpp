#include <iostream>
using namespace std;

int main() {
    double c,f,d,N,exchange; //entrada
    double H,Dmin,Dmax,P; //salida
    
    cout <<"\tIntroduce tus datos: \n\n\tCírculo de confusión (0.001,0.019): ";
    cin >>c;     //Círculo de confusión
    cout <<"\tLongitud Focal (0.5,64): ";
    cin >>f;     //Longitud focal
    cout <<"\tDistancia de enfoque (5,2000): ";
    cin >>d;     //Distancia de enfoque
    cout <<"\tDiafragma (1,infinito): ";
    cin >>N;     //Número f
    
    if (c < 0.001 || c > 0.019 || f < 0.5 || f > 64 || d < 5 || d > 2000 || N < 1)
    {
        cout <<"\n\tHas introducido algún dato mal,\n\tdebes ceñirte a los intervalos que te dicen";
    }
    else
    {
    if (N<d)
    {
        exchange=N;
        N=d;
        d=exchange;
    }
    
    H = ((f*f/(N*c))+f);
    Dmin = (d*(H-f))/(H+d-2*f);
    Dmax = (d*f*f)/(H - d); //La fórmula está mal dada en el enunciado
    P = Dmax - Dmin;
    
    cout <<"\n\tLa hiperfocal vale: "<<H;
    cout <<"\n\tLa distacia mínima de la zona enfocada vale: "<<Dmin;
    if (Dmax < 0)
        cout <<"\n\tLa distancia máxima de la zona enfocada vale infinito";
    else
        cout <<"\n\tLa distancia máxima de la zona enfocada vale: "<<Dmax;
    if (P < 0)
        cout <<"\n\tLa profundidad de campo vale infinito";
    else
        cout <<"\n\tLa profundidad de campo vale: "<<P;
    
    }
    return 0;
}




