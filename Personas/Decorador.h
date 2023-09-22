// clase para los encargados de decorar la casa (trabajan la parte de acabados finales de la casa)

#ifndef _DECORADOR_
#define _DECORADOR_

#include "Persona.h"

class Decorador : public Persona {
    private:
        string tipoPersona;
        int cantidadPersona;

    public:
        Decorador (string tipoPersona, int cantidadPersona) : Persona(tipoPersona, cantidadPersona){}

        void realizarAccion (){} // decorar la casa
};

#endif