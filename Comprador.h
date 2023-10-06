// clase para el comprador de materiales

#ifndef _COMPRADOR_
#define _COMPRADOR_

#include <string>
#include <iostream>
#include <vector>

#include "Material.h"

using namespace std;

class Comprador
{
private:
    int minCompra, maxCompra, duracionMin, duracionMax;

public:
    Comprador(int[] pConfig);

    Material comprar(string pTipo); // hilo, parametro es el tipo de material que quiere comprar, retorna un paquete del material comprado
};

#endif