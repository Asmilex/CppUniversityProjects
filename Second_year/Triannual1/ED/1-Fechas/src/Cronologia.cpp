#include <iostream>
#include "Cronologia.h"
#include "Fecha_Historica.h"

using namespace std;

//Resize
  void Cronologia::resize(int r){
     if(r>reservados){
     Fecha_Historica *aux = new Fecha_Historica[r];   
     for (int i=0; i<num_eventos; i++)
        aux[i]=eventos[i]; 
     delete[] eventos;
     eventos = aux;
     reservados=r;
     }
  }
  
//Ordena
  void Cronologia::ordenar(){
     for (int i=num_eventos-1; i>0; --i) 
      for (int j=0; j<i; ++j)
         if (eventos[j].getAnio() > eventos[j+1].getAnio()) {
            Fecha_Historica aux;
            aux = eventos[j];
            eventos[j] = eventos[j+1];
            eventos[j+1]= aux;
         }
}

//Constructor vacío
  Cronologia::Cronologia(): reservados(0), num_eventos(0), eventos(0){}
     

//Constructor con parámetro cadena de Fecha_Historica y número de objetos
  Cronologia::Cronologia(Fecha_Historica *eh, int n): reservados(n),num_eventos(n){
     Fecha_Historica *event = new Fecha_Historica[n];   
     for (int i=0; i<n; i++)
        event[i]=eh[i];
  }

//Constructor de copias
   Cronologia::Cronologia(const Cronologia& c){
      eventos = new Fecha_Historica[c.reservados];
      num_eventos = c.num_eventos;
      reservados = c.num_eventos;
     
      for(int i=0; i<num_eventos; ++i)
         eventos[i] = c.eventos[i];
   }

//Añade objeto de Fecha_Historica
  void Cronologia::aniadirEvento(Fecha_Historica& eh){
     if (num_eventos == reservados){
        if (num_eventos==0)
           resize(1);
        else
           resize(2*reservados);
     }
     eventos[num_eventos]=eh;
     num_eventos++;
     ordenar();
  }


//Busca un evento en la Cronología y devuelve su posición en el vector
  int Cronologia::buscarAnio(int f){
     int i=0;
     bool valido=false;
     while(i<num_eventos && !valido){
        if(eventos[i].getAnio()==f)
           valido = true;
        else
           ++i;
     }
     if(!valido)
        i=-1;
     return i;
  }


//Busca un evento en la Cronología y devuelve su posición en el vector
  Cronologia Cronologia::buscarEventos(string s){
     Cronologia nuevo;
     for (int i=0; i < num_eventos; ++i){
        Fecha_Historica aux;
        if(eventos[i].buscarEventos(s,aux)){
           nuevo.aniadirEvento(aux);
        }
     }
     nuevo.ordenar();
     return nuevo;
   }

//Operador <<
  ostream& operator<< (ostream& os, const Cronologia& c){
     for(int i=0; i<c.num_eventos; i++)
        os << c.eventos[i];
     return os;     
  }

//Operador >>
  istream& operator>> (istream& is, Cronologia& c){
     Fecha_Historica b;
     while(is >> b){
        c.aniadirEvento(b);
     }
     return is;
  } 
