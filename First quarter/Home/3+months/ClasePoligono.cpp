#include <iostream>
#include <cmath>
using namespace std;

class PoligonoRegular{
private:
    unsigned int n;
    double l;
    double x;
    double y;
public:
    PoligonoRegular(){
        n = 4;
        l = 1;
        x = 0;
        y = 0;
    }

    PoligonoRegular(unsigned int n_, double l_, double x_, double y_){
        n = n_;
        l = l_;
        x = x_;
        y = y_;
    }

    PoligonoRegular(const PoligonoRegular& poli){
        n = poli.n;
        l = poli.l;
        x = poli.x;
        y = poli.y;
    }

    double radio() const{
        return l/2*sin(M_PI/n);
    }
    
    void CambioLado(unsigned int k){
        l = this->radio() * sqrt(2*(1-cos(2*M_PI/(k*n))));
    }

    double Perimetro(){
        double valor = 0;
        for (unsigned int i=0; i<n; i++)
            valor += l;
        
        return valor;
    }

    double Area() const{
        return (n/2) * this->radio() * this->radio() * sin(2*M_PI/n);
    }

    bool operator<(const PoligonoRegular & poli) const{
        return (this->Area() < poli.Area());
    }
    bool operator>(const PoligonoRegular & poli) const{
        return (this->Area() > poli.Area());
    }

};

int main(){
    PoligonoRegular poli1(4,1,0,0);
    PoligonoRegular poli2(4,2,0,0);

    if (poli1>poli2)
        cout <<"Oh well";
    else
        cout <<"Feels bad man";

    return 0;
}