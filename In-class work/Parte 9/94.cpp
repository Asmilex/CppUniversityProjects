#include <iostream>
#include <vector>
using namespace std;



class Punto{
private:
    double x;
    double y;

public:
    Punto(){
        x = 0;
        y = 0;
    }
    Punto(double x_, double y_){
        x = x_;
        y = y_;
    }

    double GetX() const{
        return x;
    }
    double GetY() const{
        return y;
    }
    void SetX(double valor){
        x = valor;
    }
    void SetY(double valor){
        y = valor;
    }

    void Print() const{
        cout <<"(x,y) = ("<<this->x<<","<<this->y<<")";
    }

    Punto operator=(Punto paux){
        x = paux.GetX();
        y = paux.GetY();
    }
};

class Segmento{
private:
    Punto p1, p2;
    Punto Seg;

public:  
     Segmento(){
        cout <<"Punto 1: \nX:";
        double x1;
        cin >>x1;
        
        cout <<"Y:";
        double y1;
        cin >>y1;

        p1.SetX(x1);
        p1.SetY(y1);

        cout <<"Punto 2: \nX:";
        double x2;
        cin >>x2;
        
        cout <<"Y:";
        double y2;
        cin >>y2;
        
        p2.SetX(x2);
        p2.SetY(y2);

        Seg.SetX( p2.GetX() - p1.GetX() );
        Seg.SetY( p2.GetY() - p1.GetY() );
    }

    void Print() const{
        cout <<"Puntos del segmento: \nP1: ";
        p1.Print();
        cout <<"\nP2: ";
        p2.Print();
        cout <<"\nSegmento que los une: ";
        Seg.Print();
    }
    
    /**
     * @brief: Devuelve si el punto pasado se encuentra a la derecha o a la izquierda del segmento
     * @return: 0 si se encuentra a la izquierda, 1 si es parte del segmento, 2 si está a la derecha
     */
    bool DetectorPosicion(Punto p){
        double value = (p2.GetX() - p1.GetX())*(p.GetY() - p1.GetY()) - (p2.GetY() - p1.GetY())*(p.GetX() - p1.GetX());

        if (value > 0)
            return 2;
        if (value == 0 )
            return 1;
        else
            return 0;
    }
};

int main(){
    cout <<"Introduce los puntos que unen al segmento:\n";
    Segmento seg1;
    seg1.Print();
    
    cout <<"\nIntroduce otro segmento";
    Segmento seg2;
    
    cout <<"\nAhora un punto: ";
    double i,j;
    cin >>i,j;
    Punto p3(i,j);

    if (seg1.DetectorPosicion(p3) == 2)
        cout <<"El punto se encuentra a la derecha del seg1";
    if (seg1.DetectorPosicion(p3) == 1)
        cout <<"El punto se encuentra en el seg1";
    else
        cout <<"El punto se encuentra a la izquierda del seg1";
    
        


    return 0;
}