// clase para los abogados (trabajan la parte de permisos de la casa)

#ifndef _ABOGADO_
#define _ABOGADO_

#include "Persona.h"

class Abogado : public Persona {
    private:
        string tipoPersona;
        int cantidadPersona;

    public:
        Abogado (string tipoPersona, int cantidadPersona) : Persona(tipoPersona, cantidadPersona){}

        void realizarAccion (){} // revisar permisos
};

#endif