// clase para los constructores (trabajan la parte de cimientos y framing()

#ifndef _CONSTRUCTOR_
#define _CONSTRUCTOR_

#include "Persona.h"

class Excavacion : public Persona {
    private:
        string tipoPersona;
        int cantidadPersona;

    public:
        Excavacion (string tipoPersona, int cantidadPersona) : Persona(tipoPersona, cantidadPersona){}

        void realizarAccion (){} // realizar accion dependiendo del proceso en el que se les llame
                                 // puede ser "hacer los cimientos" o "hacer el framing"
};

#endif