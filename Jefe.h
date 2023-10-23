// clase para llamar a los trabajadores para que vayan a realizar un proceso

#ifndef _JEFE_
#define _JEFE_

#include <string>
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>

#include "Persona.h"
#include "Config.h"

using namespace std::chrono;

class Jefe
{
private:
    int minDuracion, maxDuracion;
    int minPersonal, maxPersonal;
    Config *config;

    void imprimirHeaderLlamado()
    {
        cout << "Llamando personal necesario\n" << endl;
        cout << "\n*********************************" << endl;
        cout << "*     LLAMADO - PERSONAL        *" << endl;
        cout << "*-------------------------------*" << endl;
    }

    void imprimirLlamado(string nombre, int cantidad)
    {
        cout << "* " << std::setw(19) << std::setfill(' ') << nombre << " > " << std::setw(5) << std::setfill(' ') << cantidad << "   *" << endl;
    }

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

        imprimirHeaderLlamado();
        while (cantidadLlamada < pCant)
        {
            int nuevaCantidad = (rand() % (maxPersonal - minPersonal + 1)) + minPersonal;
            cantidadLlamada += nuevaCantidad;
            imprimirLlamado(pTipo, nuevaCantidad);
        }
        cout << "*********************************\n\n";

        auto inicioPersonal = high_resolution_clock::now();
        std::this_thread::sleep_for(milliseconds(((rand() % (maxDuracion - minDuracion + 1)) + minDuracion) * config->getDuracionHoraSimulador()));
        auto finPersonal = high_resolution_clock::now();
        auto duracionPersonal = duration_cast<microseconds>(finPersonal - inicioPersonal);
        cout << "Tiempo transcurrido en personal: " << duracionPersonal.count()/config->getDuracionHoraSimulador() << endl;

        return new Persona(pTipo, cantidadLlamada);
    } // hilo, parametro es el tipo de trabajador que quiere llamar, retorna una cuadrilla de trabajadores
};

#endif