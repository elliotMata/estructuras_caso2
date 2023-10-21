// clase para llamar a los trabajadores para que vayan a realizar un proceso

#ifndef _JEFE_
#define _JEFE_

#include <string>
#include <vector>
#include <iostream>

#include "json.hpp"
#include "Persona.h"
#include "Config.h"

class Jefe
{
private:
    int minDuracion, maxDuracion;
    int minPersonal, maxPersonal;
    Config *config;

public:
    Jefe(Config *config)
    {
        minDuracion = config->getJefeDuracionMinima();
        maxDuracion = config->getJefeDuracionMaxima();
        this->config = config;
    };

    Persona *llamarTrabajadores(string pTipo)
    {
        int cantidadLlamada = 0;

        minPersonal = config->getJefeMinimoPersonal(pTipo);
        maxPersonal = config->getJefeMaximoPersonal(pTipo);

        cantidadLlamada = (rand() % (maxPersonal - minPersonal + 1)) + minPersonal;

        return new Persona(pTipo, cantidadLlamada);
    } // hilo, parametro es el tipo de trabajador que quiere llamar, retorna una cuadrilla de trabajadores
};

#endif