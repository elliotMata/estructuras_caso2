// clase para revisar los permisos de la casa

#ifndef _PERMISOS_
#define _PERMISOS_

#include "Proceso.h"

class Permiso : public Proceso {
    private:
        string nombreProceso;
        int cantidadPersonalEsperado; // trabaja con abogados
        int cantidadPersonal;

        /* para llamar a quien lee el json y obtener la cantidad de personal necesario
         * para este proceso. se almacenarian en cantidadPersonalEsperado
         */
        void getCantidadEsperadaPersonal (){}

    public:
        Permiso (string nombreProceso, int cantidadPersonal) : Proceso(nombreProceso, cantidadPersonal){}

        /* para obtener la cantidad de personal que se espera
         * para poder realizar el proceso 
         */
        int getCantidadPersonalEsperado (){
            return this->getCantidadPersonal();
        }

        void execute (){} // revisar que se tenga permisos de construccion para el proyecto dado (ID)
};

#endif