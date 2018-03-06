#include <iostream>
#include <assert.h>
#include "intervalo.h"
using namespace std;

bool Intervalo::validar(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior){
    bool comprobador = 1;
    if (cotaInferior > cotaSuperior)
        comprobador = 0;
    if (cotaInferior == cotaSuperior && cerradoInferior != cerradoSuperior)
        comprobador = 0;
    return comprobador;
};

Intervalo::Intervalo(){
    this->cotaInf = 0;
    this->cotaSup = 0;
    this->cerradoInf = 0;
    this->cerradoSup = 0;
};

Intervalo::Intervalo(double cinf,double csup){
	assert (validar(cinf,csup, true, true));
	cotaInf = cinf;
	cotaSup = csup;
	cerradoInf = true;
	cerradoSup = true;
};

Intervalo::Intervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior){
    assert (validar(cotaInferior, cotaSuperior, cerradoInferior, cerradoSuperior));
    cotaInf = cotaInferior;
    cotaSup = cotaSuperior;
    cerradoInf = cerradoInferior;
    cerradoSup = cerradoSuperior;
};

double Intervalo::getCotaInf() const{
    return this->cotaInf;
};

double Intervalo::getCotaSup() const{
    return this->cotaSup;
};

bool Intervalo::esCerradoSup() const{
    return this->cerradoSup;
}

bool Intervalo::esCerradoInf() const{
    return this->cerradoInf;
};

bool Intervalo::esVacio() const{
    if (cotaInf == cotaSup && cerradoInf == cerradoSup & cerradoInf == false)
        return true;
    else
        return false;
};

bool Intervalo::estaDentro(double n) const{
    if (cotaInf < n && n < cotaSup)
        return true;
    if (n == cotaInf && cerradoInf == true)
        return true;
    if (n == cotaSup && cerradoSup == true)
        return true;
    else
        return false;
};

void escribir(const Intervalo & i){
    if (i.esCerradoInf())
        cout <<"\n[";
    else
        cout <<"\n(";
    cout <<i.getCotaInf()<<","<<i.getCotaSup();
    if (i.esCerradoSup())
        cout <<"]";
    else
        cout <<")";
};


void leer(Intervalo & i){
    char inclusion_inf, inclusion_sup, coma;
    double minorante, mayorante;
    bool inclusion_inf_bool, inclusion_sup_bool;

    cin >>inclusion_inf>>minorante>>coma>>mayorante>>inclusion_sup;
    
    if (inclusion_inf == '[')
        inclusion_inf_bool = 1;
    else
        inclusion_inf_bool = 0;
    
    if (inclusion_sup == ']' )
        inclusion_sup_bool = 1;
    else
        inclusion_sup_bool = 0;

    Intervalo aux(minorante, mayorante, inclusion_inf_bool, inclusion_sup_bool); 
    i = aux;
}