// clase para llamar a los trabajadores para que vayan a realizar un proceso

#ifndef _JEFE_
#define _JEFE_

#include <string>
#include <vector>
#include <iostream>
#include <thread>

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

    Persona *llamarTrabajadores(string pTipo, int pCant)
    {
        int cantidadLlamada = 0;

        minPersonal = config->getJefeMinimoPersonal(pTipo);
        maxPersonal = config->getJefeMaximoPersonal(pTipo);

        while (cantidadLlamada < pCant)
        {
            cantidadLlamada += (rand() % (maxPersonal - minPersonal + 1)) + minPersonal;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(((rand() % (maxDuracion - minDuracion + 1)) + minDuracion) * 1000));

        return new Persona(pTipo, cantidadLlamada);
    } // hilo, parametro es el tipo de trabajador que quiere llamar, retorna una cuadrilla de trabajadores
};

#endif