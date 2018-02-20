#include <iostream>
#include <string>
using namespace std;

/**
    @brief Introduce un año y devuelve si es bisiesto o no
    @param ano: valor del año. Se da por hecho que el valor introducido es entero positivo 
    @return indicador: 1 si es bisiesto. Si no, devuelve 0
*/
bool EsBisiesto(int ano){
    bool indicador;
    
    if (ano%4 == 0 && ano%100 != 0)
        indicador=1;
    else{
        if(ano%400 == 0)
            indicador=1;
        else 
            indicador=0;
    }
    return indicador;
}


/**
    @brief: Recibe una fecha con formato válido (día, mes y año) y devuelve el día juliano astronómico
    @param dia: valor que corresponde al día
    @param mes: valor que corresponde al mes
    @param ano: valor que corresponde al año
    @return juliano: dia juliano correspondiente 
*/
int Juliano(int dia, int mes, int ano){
    int juliano=(1461 * (ano + 4800 + (mes - 14) / 12))/4+(367*(mes-2-12*((mes-14)/12)))/12-(3*((ano+4900+(mes-14)/12)/100))/4+dia-32075;
    return juliano;
}


/**
    @brief: Recibe una fecha (dia, mes, año) y devuelve el día de la semana respectivo
    @param dia: valor que corresponde al día
    @param mes: valor que corresponde al mes
    @param ano: valor que corresponde al año
    @return diacoded: Devuelve una letra dependiendo del día de la semana (L, M, X, J, V, S, D)
*/
char DiaCodificado(int dia, int mes, int ano){
    string codificador="LMXJVSD";
    int djul=Juliano(dia, mes, ano);
    char diacoded=codificador[(djul%7)];
    
    return diacoded;
}

/**
    @brief: Introduce una fecha, y dice si es válida o no
    @param dia: valor que corresponde al día
    @param mes: valor que corresponde al mes
    @param ano: valor que corresponde al año
    @return indicador: Devuelve 1 si la fecha es válida, 0 si no lo es
*/
bool DiaValido(int dia, int mes, int ano){
    bool indicador;
    bool bisiesto=EsBisiesto(ano);
    
    if (ano < 1)
        indicador=0;
    else{         
        if (mes < 0 ||mes > 12)
            indicador=0;
        else{
            if (dia < 0 || dia > 31)
                indicador=0;
            else{ 
                indicador=0; // En caso de que todos fallen, este valor se conervará
                if ((mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && dia<=31)
                    indicador=1;
                if ((mes==4 || mes==6 || mes==9 || mes==11) && dia<=30)
                    indicador=1;
                if (mes==2){
                    if (bisiesto==1){
                        if (dia<=29)
                            indicador=1;
                    }
                    else
                        if (dia<=28)
                            indicador=1;
                        
                }
            }   
        }

    }

    return indicador;
}


int main(){
    cout <<"Introduce una fecha válida (día, mes, año)";
    
    bool fechavalida=0; //Valor para asegurar que el bucle siguiente se inicie
    int dia, mes, ano;
    while (fechavalida==0){
        cout <<"\n";
        cin >>dia>>mes>>ano;

        fechavalida=DiaValido(dia, mes, ano);
        
        if (fechavalida==0)
            cout <<"Has introducido erróneamente los datos. Reintrodúcelos";

    }
    
    cout <<"La fecha es: ";

    char letra=DiaCodificado(dia, mes, ano);
    string DiaSemana;
    if (letra=='L')
        DiaSemana="Lunes";
    if (letra=='M')
        DiaSemana="Martes";
    if (letra=='X')
        DiaSemana="Miercoles";
    if (letra=='J')
        DiaSemana="Jueves";
    if (letra=='V')
        DiaSemana="Viernes";
    if (letra=='S')
        DiaSemana="Sabado";
    if (letra=='D')
        DiaSemana="Domingo";

    string NomMes;
    if (mes==1)
        NomMes="enero";
    if (mes==2)
        NomMes="febrero";
    if (mes==3)
        NomMes="marzo";
    if (mes==4)
        NomMes="abril";
    if (mes==5)
        NomMes="mayo";
    if (mes==6)
        NomMes="junio";
    if (mes==7)
        NomMes="julio";
    if (mes==8)
        NomMes="agosto";
    if (mes==9)
        NomMes="septiembre";
    if (mes==10)
        NomMes="octubre";
    if (mes==11)
        NomMes="noviembre";
    if (mes==12)
        NomMes="diciembre";
    
    cout <<DiaSemana<<" "<<dia<<" de "<<NomMes<<" de "<<ano;
    
    bool Bisiestiano=EsBisiesto(ano);
    if (Bisiestiano==1)
        cout <<" (Bisiesto)";

    return 0;
}