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
    int minDuracion, maxDuracion, minAbogados, maxAbogados, minCableado, maxCableado, minPlomeria, maxPlomeria, minConstructores, maxConstructores, minDecoradores, maxDecoradores, minMaquinaria, maxMaquinaria, minTechos, maxTechos;

public:
    Jefe(int[] pConfig);

    Persona llamarTrabajadores(string pTipo); // hilo, parametro es el tipo de trabajador que quiere llamar, retorna una cuadrilla de trabajadores
};

#endif