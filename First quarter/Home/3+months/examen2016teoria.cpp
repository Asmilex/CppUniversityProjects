//http://deiit.ugr.es/BDExamenes/ex%C3%A1menes/Inform%C3%A1tica/1/Fundamentos%20de%20Programaci%C3%B3n/1516/Sept-2016%20fp%20teoria.jpg


#include <vector>
#include <iostream>
using namespace std;



class SecuenciaEnteros{
private: 
public: 
    //Ejercicio 1
    /**
     * @brief: dado un número, se busca una serie de valores mayores o iguales que él. No modificará el elemento
     * @param p: valor de corte. Se buscan los números mayores que este 
     * @param n: número de valores que se van a buscar. Por ejemplo, si n=3, se cogen 3 valores
     */
    SecuenciaEnteros BusquedaHaciaArriba (int p; int n) const{
        if (n>*this.capacidad())
            n=*this.capacidad();
        
        SecuenciaEnteros temp;
        for (int i=0; i<n; i++)
            if (*this.Elemento(i)>=p)
                temp.aniadir( *this.Elemento(i) );

        for (int i=0; i<temp.capacidad(); i++)
            for (int j=0; j<temp.capacidad(); j++)
                if (temp.Elemento(j)>temp.Elemento(i)){
                    int aux;
                    aux              = temp.Elemento(j); 
                    temp.Elemento(j) = temp.Elemento(i);
                    temp.Elemento(i) = aux;
                }
    
        return temp;
    }
}

int main(){
    cout <<"Introduce 2 valores. El primero es el valor, el segundo es el número de elementos: ";
    int p,n;
    cin >>p>>n;

    //Supondremos que ya hay valores dentro de la secuencia
    SecuenciaEnteros secuencia1
    SecuenciaEnteros secuencia2 = secuencia1.BusquedaHaciaArriba(p,n);

} 
