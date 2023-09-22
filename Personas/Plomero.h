// clase para los plomeros (trabajan la parte de plomeria de la casa)

#ifndef _PLOMERO_
#define _PLOMERO_

#include "Persona.h"

class Plomero : public Persona {
    private:
        string tipoPersona;
        int cantidadPersona;

    public:
        Plomero (string tipoPersona, int cantidadPersona) : Persona(tipoPersona, cantidadPersona){}

        void realizarAccion (){} // poner las tuberias
};

#endif