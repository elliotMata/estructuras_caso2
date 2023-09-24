// clase para llamar a los trabajadores para que vayan a realizar un proceso

#ifndef _JEFE_
#define _JEFE_

#include <string>
#include <vector>
#include <iostream>

#include "Persona.h"

class Jefe
{
private:
    vector<Persona> abogados, cableadoPlomeria, constructores, decoradores, maquinaria, techos;
    int cantidadMinima, cantidadMaxima;

    /* para llamar a quien lee el json y obtener la cantidad minima y maxima
     * por cada trabajador que se puede obtener por llamada
     */
    // void getInfoTrabajadores(){}

    /* los siguientes metodos se encargan de llamar al trabajador indicado
     * de acuerdo con los datos obtenidos del json
     */
    void callAbogados() {}

    void callCableado() {}

    void callPlomeria() {}

    void callConstructores() {}

    void callDecoradores() {}

    void callMaquinaria() {}

    void callTechos() {}

public:
    Jefe(int pCantMin, int pCantMax) : cantidadMinima(pCantMin), cantidadMaxima(pCantMax)
    {
        // getInfoTrabajadores();
    }

    /* los siguientes metodos llaman al trabajador o a los trabajadores
     * indicados y devuelve el vector con los trabajadores obtenidos
     */
    vector<Persona *> getAbogados() {}

    vector<Persona *> getCableadoPlomeria() {}

    vector<Persona *> getConstructores() {}

    vector<Persona *> getDecoradores() {}

    vector<Persona *> getMaquinaria() {}

    vector<Persona *> getTechos() {}
};

#endif