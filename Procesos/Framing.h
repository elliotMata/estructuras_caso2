// clase para realizar el framing de la casa

#ifndef _FRAMING_
#define _FRAMING_

#include "Proceso.h"

class Framing : public Proceso {
    private:
        string nombreProceso;
        int cantidadPersonalEsperado; // trabajaria con constructores
        int cantidadPersonal;
        int cantidadMaterialesEsperados; // trabajaria con la madera
        int cantidadMateriales;

        /* para llamar a quien lee el json y obtener la cantidad de materiales necesarios
         * para este proceso. se almacenarian en cantidadMaterialesEsperados
         */
        void getCantidadEsperadaMateriales (){}

        /* para llamar a quien lee el json y obtener la cantidad de personal necesario
         * para este proceso. se almacenarian en cantidadPersonalEsperado
         */
        void getCantidadEsperadaPersonal (){}

    public:
        Framing (string nombreProceso, int cantidadPersonal, int cantidadMateriales) : Proceso(nombreProceso, cantidadPersonal){
            this->cantidadMateriales = cantidadMateriales;
        }

        /* para obtener la cantidad de materiales que se esperan
         * para poder realizar el proceso 
         */
        int getCantidadMaterialesEsperados (){
            return this->cantidadMaterialesEsperados;
        }

        /* para obtener la cantidad de personal que se espera
         * para poder realizar el proceso 
         */
        int getCantidadPersonalEsperado (){
            return this->getCantidadPersonal();
        }

        void execute (){} // realizar el framing the la casa
};

#endif