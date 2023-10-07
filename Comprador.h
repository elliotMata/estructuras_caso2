// clase para el comprador de materiales

#ifndef _COMPRADOR_
#define _COMPRADOR_

#include <string>
#include <iostream>
#include <vector>

#include "Material.h"

using json = nlohmann::json;

using namespace std;

class Comprador
{
private:
    int minCompra, maxCompra, duracionMin, duracionMax;

public:
    Comprador(json pConfig){
        minCompra = pConfig["Cantidades"]["minimo"];
        maxCompra = pConfig["Cantidades"]["maximo"];
        duracionMin = pConfig["Duracion"]["minimo"];
        duracionMax = pConfig["Duracion"]["maximo"];
    }

    Material* comprar(string pTipo){
        int compra = (rand() % (maxCompra - minCompra + 1)) + minCompra;
        Material *materialComprado = new Material (pTipo, compra);
        return materialComprado;
    } // hilo, parametro es el tipo de material que quiere comprar, retorna un paquete del material comprado
};

#endif