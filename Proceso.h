// clase "asbtracta" para los procesos de construccion

#ifndef _PROCESO_
#define _PROCESO_

#include <string>
#include <iostream>
#include <vector>

#include "Material.h"
#include "List.h"
#include "Persona.h"
#include "Config.h"

using namespace std;

class Proceso
{
private:
    string nombreProceso;
    List<Persona> *personalNecesario = new List<Persona>();
    unordered_map<string, int> personalFaltante;
    List<Material> *materialNecesario = new List<Material>();
    unordered_map<string, int> materialFaltante;
    int minDuracionRevision, maxDuracionRevision, minDuracion, maxDuracion;

public:
    Proceso(Config *config, string nombre);

    string getNombreProceso()
    {
        return this->nombreProceso;
    }

    List<Persona> *getPersonalNecesario()
    {
        return this->personalNecesario;
    }

    unordered_map<string, int> getPersonalFaltante()
    {
        return this->personalFaltante;
    }

    List<Material> *getMaterialNecesario()
    {
        return this->materialNecesario;
    }

    unordered_map<string, int> getMaterialFaltante()
    {
        return this->materialFaltante;
    }

    int getMinDuracion()
    {
        return this->minDuracion;
    }

    int getMaxDuracion()
    {
        return this->maxDuracion;
    }

    int getMinDuracionRevision()
    {
        return this->minDuracionRevision;
    }

    int getMaxDuracionRevision()
    {
        return this->maxDuracionRevision;
    }

    bool verificarPersonal(List<Persona> *pPersonal);
    bool verificarMaterial(unordered_map<string, int> disponibles);
};

#endif