// clase "asbtracta" para los procesos de construccion

#ifndef _PROCESO_
#define _PROCESO_

#include <string>
#include <iostream>
#include "List.h"
#include "Persona.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

class Proceso
{
private:
    string nombreProceso;
    List<Persona> personalNecesario, personalFaltante;
    List<Material> materialNecesario, materialFaltante;

public:
    Proceso(json configProceso) {}

    string getNombreProceso()
    {
        return this->nombreProceso;
    }

    List getPersonalNecesario()
    {
        return this->personalNecesario;
    }

    List getPersonalFaltante()
    {
        return this->personalFaltante;
    }

    List getMaterialNecesario()
    {
        return this->materialNecesario;
    }

    List getMaterialFaltante()
    {
        return this->materialFaltante;
    }

    bool verificarPersonal(List pPersonal) {}
    bool verificarMaterial(int pCemento, int pMadera, int pDecor) {}
};

#endif