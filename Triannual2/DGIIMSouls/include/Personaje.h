#ifndef DS_PERSONAJE
#define DS_PERSONAJE

#include <string>
#include <fstream>
#include <cstring>
#include <iostream>

class Personaje{
private:
    char * _nombre;
    unsigned int _dim_nombre;

    float  _vida;
    double _basedamage;
    
    int * _level;
    int * _nextlevel;

public:
    Personaje();                                                 //Default constructor
    Personaje(const char * nombre);                              //Define nombre del personaje
    ~Personaje();                                                //Destructor

    bool SaveFile(std::string save) const;                            //Guarda partida. true si ha ocurrido con éxito
    bool LoadFile(std::string save) const;                            //Carga partida. true si ha ocurrido con éxito

    double Atacar() const;                                       //Devuelve un doble para quitarle vida al malo maloso
    void LevelUp();                                              //Te sientes revitalizado y aumentas el tamaño de tu array de vida. Modofica _level y _nextlevel
    void UpdateXP(int experiencia);                              //Actualiza tu nivel tras la batalla

    float GetVida() const;                                       //Muestra la vida que te queda
    char * GetNombre() const;                                    //De verdad te has olvidado de cómo te llamas, pringao?
    double GetBDamage() const;                                   //Devuelve el daño base
    int GetLevel() const;                                        //Por mucho nivel que tengas no va a hacer que mejores

    friend std::ostream & operator<<(std::ostream os, Personaje naufrago); //Muestra en pantalla tu personaje
}

std::ostream& operator<<(std::ostream os, Personaje naufrago);

#endif