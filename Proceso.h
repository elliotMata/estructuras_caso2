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
    vector<string> personalFaltante;
    List<Material> *materialNecesario = new List<Material>();
    unordered_map<string, int> materialFaltante;

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

    vector<string> getPersonalFaltante()
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

    bool verificarPersonal(List<Persona> *pPersonal);
    bool verificarMaterial(unordered_map<string, int> disponibles);
};

#endif