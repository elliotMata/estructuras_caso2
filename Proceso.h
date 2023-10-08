// clase "asbtracta" para los procesos de construccion

#ifndef _PROCESO_
#define _PROCESO_

#include <string>
#include <iostream>

#include "Material.h"
#include "List.h"
#include "Persona.h"
#include "json.hpp"
#include <vector>

using namespace std;
using json = nlohmann::json;

class Proceso
{
private:
    string nombreProceso;
    List<Persona> personalNecesario;
    vector<string> personalFaltante, materialFaltante;
    List<Material> materialNecesario;

public:
    Proceso(json configProceso, string nombre) {}

    string getNombreProceso()
    {
        return this->nombreProceso;
    }

    List<Persona> getPersonalNecesario()
    {
        return this->personalNecesario;
    }

    vector<string> getPersonalFaltante()
    {
        return this->personalFaltante;
    }

    List<Material> getMaterialNecesario()
    {
        return this->materialNecesario;
    }

    vector<string> getMaterialFaltante()
    {
        return this->materialFaltante;
    }

    bool verificarPersonal(List<Persona> pPersonal) {}
    bool verificarMaterial(int pCemento, int pMadera, int pDecor) {}
};

#endif