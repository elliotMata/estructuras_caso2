// clase para realizar el revestimiento y aislamiento de la casa

#ifndef _RA_
#define _RA_

#include "Proceso.h"

class RevestimientoAislamiento : public Proceso {
    private:
        string nombreProceso;
        int cantidadPersonalEsperado; // trabajaria con constructores
        int cantidadPersonal;

        /* para llamar a quien lee el json y obtener la cantidad de personal necesario
         * para este proceso. se almacenarian en cantidadPersonalEsperado
         */
        void getCantidadEsperadaPersonal (){}

    public:
        RevestimientoAislamiento (string nombreProceso, int cantidadPersonal) : Proceso(nombreProceso, cantidadPersonal){}

        /* para obtener la cantidad de personal que se espera
         * para poder realizar el proceso 
         */
        int getCantidadPersonalEsperado (){
            return this->getCantidadPersonal();
        }

        void ejecutar (){} // realizar la excavacion
};

#endif