// clase para realizar la excavacion de la casa

#ifndef _EXCAVACION_
#define _EXCAVACION_

#include "Proceso.h"

class Excavacion : public Proceso {
    private:
        string nombreProceso;
        int cantidadPersonalEsperado; // trabajaria con maquinaria
        int cantidadPersonal;

        /* para llamar a quien lee el json y obtener la cantidad de personal necesario
         * para este proceso. se almacenarian en cantidadPersonalEsperado
         */
        void getCantidadEsperadaPersonal (){}

    public:
        Excavacion (string nombreProceso, int cantidadPersonal) : Proceso(nombreProceso, cantidadPersonal){}

        /* para obtener la cantidad de personal que se espera
         * para poder realizar el proceso 
         */
        int getCantidadPersonalEsperado (){
            return this->getCantidadPersonal();
        }

        void ejecutar (){} // realizar la excavacion
};

#endif