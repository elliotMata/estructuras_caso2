// clase para el comprador de materiales

#ifndef _COMPRADOR_
#define _COMPRADOR_

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <thread>
#include <chrono>

#include "Material.h"
#include "Config.h"

using namespace std::chrono;
using namespace std;

class Comprador
{
private:
    int minCompra, maxCompra, duracionMin, duracionMax;
    Config *config;

    void imprimirHeaderCompra()
    {
        cout << "Comprando materiales necesarios\n" << endl;
        cout << "\n*********************************" << endl;
        cout << "*     COMPRA DE MATERIAL        *" << endl;
        cout << "*-------------------------------*" << endl;
    }

    void imprimirCompra(string nombre, int cantidad)
    {
        cout << "* " << std::setw(19) << std::setfill(' ') << nombre << " > " << std::setw(5) << std::setfill(' ') << cantidad << "   *" << endl;
    }

public:
    Comprador(Config *config)
    {
        minCompra = config->getCompradorCantidadMinima();
        maxCompra = config->getCompradorCantidadMaxima();
        duracionMin = config->getCompradorDuracionMinima();
        duracionMax = config->getCompradorDuracionMaxima();
        this->config = config;
    }

    Material comprar(string pTipo, int pCantidad)
    {
        int compra = 0;
        imprimirHeaderCompra();
        while (compra < pCantidad)
        {
            int nuevaCantidad = (rand() % (maxCompra - minCompra + 1)) + minCompra;
            compra += nuevaCantidad;
            imprimirCompra(pTipo, nuevaCantidad);

        }
        cout << "*********************************\n\n";

        auto inicioMateriales = high_resolution_clock::now();
        std::this_thread::sleep_for(milliseconds(((rand() % (duracionMax - duracionMin + 1)) + duracionMin) * config->getDuracionHoraSimulador()));
        auto finMateriales = high_resolution_clock::now();
        auto duracionMateriales = duration_cast<microseconds>(finMateriales - inicioMateriales);
        cout << "Tiempo transcurrido en materiales: " << duracionMateriales.count()/config->getDuracionHoraSimulador() << endl;

        return Material(pTipo, compra);
    } // hilo, parametro es el tipo de material que quiere comprar, retorna un paquete del material comprado
};

#endif