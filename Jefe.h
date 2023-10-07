// clase para llamar a los trabajadores para que vayan a realizar un proceso

#ifndef _JEFE_
#define _JEFE_

#include <string>
#include <vector>
#include <iostream>
#include "json.hpp"
#include "Persona.h"

using json = nlohmann::json;

class Jefe
{
private:
    int minDuracion, maxDuracion, minAbogados, maxAbogados, minCableado, maxCableado, minPlomeria, maxPlomeria, minConstructores, maxConstructores, minDecoradores, maxDecoradores, minMaquinaria, maxMaquinaria, minTechos, maxTechos;

public:
    Jefe(json pConfig){
        minDuracion = pConfig["DuracionLlamadaPersonal"]["minimo"];
        maxDuracion = pConfig["DuracionLlamadaPersonal"]["maximo"];
        minAbogados = pConfig["Abogados"]["minimo"];
        maxAbogados = pConfig["Abogados"]["maximo"];
        minConstructores = pConfig["Constructores"]["minimo"];
        maxConstructores = pConfig["Constructores"]["maximo"];
        minMaquinaria = pConfig["Maquinaria"]["minimo"];
        maxMaquinaria = pConfig["Maquinaria"]["maximo"];
        minTechos = pConfig["Techos"]["minimo"];
        maxTechos = pConfig["Techos"]["maximo"];
        minPlomeria = pConfig["Plomeria"]["minimo"];
        maxPlomeria = pConfig["Plomeria"]["maximo"];
        minCableado = pConfig["Cableado"]["minimo"];
        maxCableado = pConfig["Cableado"]["maximo"];
        minDecoradores = pConfig["Decoradores"]["minimo"];
        maxDecoradores = pConfig["Decoradores"]["maximo"];
    };

    Persona* llamarTrabajadores(string pTipo){
        int cantidadLlamada = 0;
        Persona *empleadosLlamados;

        if (pTipo == "Abogados"){
            cantidadLlamada = (rand() % (maxAbogados - minAbogados + 1)) + minAbogados;
        } else if (pTipo == "Constructores"){
            cantidadLlamada = (rand() % (maxConstructores - minConstructores + 1)) + minConstructores;
        } else if (pTipo == "Maquinarias"){
            cantidadLlamada = (rand() % (maxMaquinaria - minMaquinaria + 1)) + minMaquinaria;
        } else if (pTipo == "Techos"){
            cantidadLlamada = (rand() % (maxTechos - minTechos + 1)) + minTechos;
        } else if (pTipo == "Plomeria"){
            cantidadLlamada = (rand() % (maxPlomeria - minPlomeria + 1)) + minPlomeria;
        } else if (pTipo == "Cableado"){
            cantidadLlamada = (rand() % (maxCableado - minCableado + 1)) + minCableado;
        } else if (pTipo == "Decoradores"){
            cantidadLlamada = (rand() % (maxDecoradores - minDecoradores + 1)) + minDecoradores;
        }

        empleadosLlamados = new Persona(pTipo, cantidadLlamada);

        return empleadosLlamados;
    } // hilo, parametro es el tipo de trabajador que quiere llamar, retorna una cuadrilla de trabajadores
};

#endif