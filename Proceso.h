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
    vector<string> personalFaltante, materialFaltante;
    List<Material> *materialNecesario = new List<Material>();

public:
    Proceso(Config *config, string nombre);

    string getNombreProceso()
    {
        return this->nombreProceso;
    }

    List<Persona>* getPersonalNecesario()
    {
        return this->personalNecesario;
    }

    vector<string> getPersonalFaltante()
    {
        return this->personalFaltante;
    }

    List<Material>* getMaterialNecesario()
    {
        return this->materialNecesario;
    }

    vector<string> getMaterialFaltante()
    {
        return this->materialFaltante;
    }

    bool verificarPersonal(List<Persona>* pPersonal);
    bool verificarMaterial(int pCemento, int pMadera, int pDecor);
};

#endif