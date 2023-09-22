// clase para poner las tuberias y el cableado de la casa

#ifndef _PC_
#define _PC_

#include "Proceso.h"

class PlomeriaCableado : public Proceso {
    private:
        string nombreProceso;
        int cantidadPersonalEsperado; // trabajaria con personal de plomeria y cableado
        int cantidadPersonal;

        /* para llamar a quien lee el json y obtener la cantidad de personal necesario
         * para este proceso. se almacenarian en cantidadPersonalEsperado
         */
        void getCantidadEsperadaPersonal (){}

    public:
        PlomeriaCableado (string nombreProceso, int cantidadPersonal) : Proceso(nombreProceso, cantidadPersonal){}

        /* para obtener la cantidad de personal que se espera
         * para poder realizar el proceso 
         */
        int getCantidadPersonalEsperado (){
            return this->getCantidadPersonal();
        }

        void ejecutar (){} // poner tuberias y cableado
};

#endif