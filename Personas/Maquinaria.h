// clase para los encargados de maquinaria (trabajan la parte de excavacion de la casa)

#ifndef _MAQUINARIA_
#define _MAQUINARIA_

#include "Persona.h"

class Maquinaria : public Persona {
    private:
        string tipoPersona;
        int cantidadPersona;

    public:
        Maquinaria (string tipoPersona, int cantidadPersona) : Persona(tipoPersona, cantidadPersona){}

        void realizarAccion (){} // realizar excavacion
};

#endif