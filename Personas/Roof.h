// clase para los encargados de poner los techos (trabajan la parte de roofing de la casa)

#ifndef _ROOF_
#define _ROOF_

#include "Persona.h"

class Excavacion : public Persona {
    private:
        string tipoPersona;
        int cantidadPersona;

    public:
        Excavacion (string tipoPersona, int cantidadPersona) : Persona(tipoPersona, cantidadPersona){}

        void realizarAccion (){} // poner los techos
};

#endif