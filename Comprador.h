// clase para el comprador de materiales

#ifndef _COMPRADOR_
#define _COMPRADOR_

#include <string>
#include <iostream>
#include <vector>
#include <thread>

#include "Material.h"
#include "Config.h"

using namespace std;

class Comprador
{
private:
    int minCompra, maxCompra, duracionMin, duracionMax;

public:
    Comprador(Config *config)
    {
        minCompra = config->getCompradorCantidadMinima();
        maxCompra = config->getCompradorCantidadMaxima();
        duracionMin = config->getCompradorDuracionMinima();
        duracionMax = config->getCompradorDuracionMaxima();
    }

    Material comprar(string pTipo, int pCantidad)
    {
        int compra = 0;
        while (compra < pCantidad)
        {
            compra += (rand() % (maxCompra - minCompra + 1)) + minCompra;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(((rand() % (duracionMax - duracionMin + 1)) + duracionMin) * 1000));

        return Material(pTipo, compra);
    } // hilo, parametro es el tipo de material que quiere comprar, retorna un paquete del material comprado
};

#endif