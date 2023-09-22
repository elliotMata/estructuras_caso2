// clase para los encargados de poner el cableado (trabajan la parte de cableado de la casa)

#ifndef _CABLEADO_
#define _CABLEADO_

#include "Persona.h"

class Cableado : public Persona {
    private:
        string tipoPersona;
        int cantidadPersona;

    public:
        Cableado (string tipoPersona, int cantidadPersona) : Persona(tipoPersona, cantidadPersona){}

        void realizarAccion (){} // poner toda la parte de electricidad
};

#endif