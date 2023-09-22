// clase "asbtracta" para los procesos de construccion

#ifndef _PROCESO_
#define _PROCESO_

#include <string>
#include <iostream>

using namespace std;

class Proceso {
    private:
        string nombreProceso;
        int cantidadPersonal;

    public:
        Proceso (string nombreProceso, int cantidadPersonal){
            this->nombreProceso = nombreProceso;
            this->cantidadPersonal = cantidadPersonal;
        }

        string getNombreProceso (){
            return this->nombreProceso;
        }

        int getCantidadPersonal (){
            return this->cantidadPersonal;
        }

        virtual void ejecutar () = 0;
};

#endif