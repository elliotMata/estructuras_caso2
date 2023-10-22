// clase "abstracta" para los trabajadores de la construccion

#ifndef _PERSONA_
#define _PERSONA_

#include <string>
#include <iostream>

using namespace std;

class Persona
{
private:
    string tipoPersona;
    int cantidadPersona; // asumiendo que se va a trabajar por grupos de personas

public:
    Persona(string tipoPersona, int cantidadPersona)
    {
        this->tipoPersona = tipoPersona;
        this->cantidadPersona = cantidadPersona;
    }

    string getTipoPersona()
    {
        return this->tipoPersona;
    }

    int getCantidadPersona()
    {
        return this->cantidadPersona;
    }

    void setCantidadPersona(int pCant)
    {
        this->cantidadPersona = pCant;
    }
};

#endif