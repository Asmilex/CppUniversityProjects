#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct punto{ 
    double x;
    double y;
};

double DistanciaPunto(const punto & p1, const punto & p2){
    double distancia = sqrt((p1.x - p2.x)*(p1.x - p2.x)+(p1.y - p2.y)*(p1.y - p2.y));
    return distancia;
}

class circulo{
private:
    punto centro;
    double radio;

public:
    circulo (punto centrocir, double radiocir){ //Constructor
        centro=centrocir;
        radio=radiocir;
    } 

    bool EsInterior(punto puntillo) const{ 
        double DisCentroPunto=DistanciaPunto(puntillo, centro);
        if (DisCentroPunto<=radio)
            return true;
        else
            return false;
    }
  
    double GetRadio() const{ //Al añadir const, se le indica al compilador que la función no va a cambiar círculo
        return radio;
    }

    punto GetCentro() const{
        return centro;
    }

    void EscribirCirculo(){
        cout <<"Centro: ("<<centro.x<<","<<centro.y<<")";
        cout <<"Radio: "<<radio;
    }
};

double LeerPositivo(){
    double numero=0;
    cin >>numero;

    while (numero<=0){
        cout <<"\nDebe ser mayor que 0. Vuelve a meterlo: ";
        cin >>numero;
    }
    return numero;
}

punto LeerPunto(){
    punto p1;
    cin >>p1.x>>p1.y;
    
    return p1;
}

void EscribirPunto(const punto & Puntaco){
    cout <<"(x,y) = ("<<Puntaco.x<<","<<Puntaco.y<<")\n";

}

void Clasificador(vector<punto> & interiores, vector<punto> & exteriores, const vector<punto> & VecPuntos, const circulo & c1){
    for (int i=0; i<VecPuntos.size(); i++){
        if (c1.EsInterior(VecPuntos[i]))
            interiores.push_back(VecPuntos[i]);
        else
            exteriores.push_back(VecPuntos[i]);
    }

}

int main(){
    cout <<"\nDime un punto. Será el centro del radio ";
    punto p1=LeerPunto();
    
    cout <<"\nIntroduce un radio: ";
    double radiomain = LeerPositivo();
    
    cout <<"\nAhora pon un listado de puntos: ";
    punto p2;
    
    //Reconocimiento de punto
    bool Activador=true;
    vector<punto> VecPuntos(1);
    for (int i=0; Activador==true; i++){
        p2=LeerPunto();
        
        Activador=false; //No me conseguía evaluar correctamente p2.x != 0 && p2.y!=0, así que se me ha ocurrido esto
        if (p2.x!=0)
            Activador=true;
        if (p2.y!=0)
            Activador=true;

        if (Activador==true){
                VecPuntos.resize(i+1);
                VecPuntos[i]=p2;
        }
    }
    
    circulo c1(p1,radiomain);
    vector<punto> interiores, exteriores;

    Clasificador(interiores, exteriores, VecPuntos, c1);

    cout <<"Esta es la lista de puntos interiores: \n";
    for (int i=0; i<interiores.size(); i++){
        EscribirPunto(interiores[i]);
    }
   
    cout <<"Se encuentran fuera del círculo los siguientes vectores: \n";
    for (int i=0; i<exteriores.size(); i++){
        EscribirPunto(exteriores[i]);
    }
}

