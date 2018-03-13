/**
   @file paquete.cpp
   @author decsai.ugr.es
   @warning Código incompleto
**/
#include "paquete.h"
using namespace std;

Paquete::Paquete(int id, double peso, double largo, int ancho, int alto){
    _id = id;
    _peso = peso;
    _largo = largo;
    _ancho = ancho;
    _alto = alto;
}

//Set
void Paquete::setId(int id){
    _id = id;
}
void Paquete::setPeso(double peso){
    _peso = peso;
}
void Paquete::setLargo(int largo){
    _largo = largo;
}
void Paquete::setAncho(int ancho){
    _ancho = ancho;
}
void Paquete::setAlto(int alto){
    _alto = alto;
}
void Paquete::setPaquete(int id, int peso, int largo, int ancho, int alto){
    _id = id;
    _peso = peso;
    _largo = largo;
    _ancho = ancho;
    _alto = alto;

}

//Get
int Paquete::getId(){
    return _id;
}
int Paquete::getLargo(){
    return _largo;
}
int Paquete::getAncho(){
    return _ancho;
}
int Paquete::getAlto(){
    return _alto;
}
double Paquete::getPeso(){
    return _peso
}

double 