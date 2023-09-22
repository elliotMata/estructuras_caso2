// clase para el proceso de poner el techo

#ifndef _TECHO_
#define _TECHO_

#include "Proceso.h"

class Techo : public Proceso {
    private:
        string nombreProceso;
        int cantidadPersonalEsperado; // trabajaria con personal de techos
        int cantidadPersonal;

        /* para llamar a quien lee el json y obtener la cantidad de personal necesario
         * para este proceso. se almacenarian en cantidadPersonalEsperado
         */
        void getCantidadEsperadaPersonal (){}

    public:
        Techo (string nombreProceso, int cantidadPersonal) : Proceso(nombreProceso, cantidadPersonal){}

        /* para obtener la cantidad de personal que se espera
         * para poder realizar el proceso 
         */
        int getCantidadPersonalEsperado (){
            return this->getCantidadPersonal();
        }

        void ejecutar (){} // poner techo
};

#endif