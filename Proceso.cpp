#include <vector>

#include "Proceso.h"
#include "List.h"
#include "Persona.h"

using namespace std;

bool Proceso::verificarPersonal(List<Persona> *pPersonal)
{
    Persona *necesario, *disponible;
    personalFaltante.clear();
    for (int pos = 0; pos < personalNecesario->getSize(); pos++)
    {
        necesario = personalNecesario->find(pos);
        if (!pPersonal->isEmpty())
        {
            for (int j = 0; j < pPersonal->getSize(); j++)
            {
                disponible = pPersonal->find(j);
                if (necesario->getCantidadPersona() > disponible->getCantidadPersona())
                {
                    personalFaltante.push_back(necesario->getTipoPersona());
                }
            }
        }
        else
        {
            personalFaltante.push_back(necesario->getTipoPersona());
        }
    }
    return personalFaltante.empty();
}

bool Proceso::verificarMaterial(int pCemento, int pMadera, int pDecor)
{
    Material *necesario;
    materialFaltante.clear();
    for (int pos = 0; pos < materialNecesario->getSize(); pos++)
    {
        necesario = materialNecesario->find(pos);
        if (necesario->getNombreMaterial() == "Cemento")
        {
            if (necesario->getCantidadMaterial() > pCemento)
            {
                materialFaltante.push_back("Cemento");
            }
        }
        if (necesario->getNombreMaterial() == "Madera")
        {
            if (necesario->getCantidadMaterial() > pMadera)
            {
                materialFaltante.push_back("Madera");
            }
        }
        if (necesario->getNombreMaterial() == "Decoraciones")
        {
            if (necesario->getCantidadMaterial() > pDecor)
            {
                materialFaltante.push_back("Decoraciones");
            }
        }
    }
    return materialFaltante.empty();
}

Proceso::Proceso(Config *config, string nombre)
{
    this->nombreProceso = nombre;
    int minPersonal = config->getProcesoMinimoTrabajadores(nombre);
    int maxPersonal = config->getProcesoMaximoTrabajadores(nombre);
    vector<string> personal = config->getProcesoTipoTrabajador(nombre);
    for (const string &trabajador : personal)
    {
        int cantidadNecesaria = (rand() % (maxPersonal - minPersonal + 1)) + minPersonal;
        this->personalNecesario->add(new Persona(trabajador, cantidadNecesaria));
    }
    if (config->getProcesoSizeRequisitos(nombre) > 3)
    {
        int minMaterial = config->getProcesoMinimoMateriales(nombre);
        int maxMaterial = config->getProcesoMaximoMateriales(nombre);
        vector<string> materiales = config->getProcesoTipoMaterial(nombre);
        for (const string &material : materiales)
        {
            int cantidadNecesaria = (rand() % (maxMaterial - minMaterial + 1)) + minMaterial;
            this->materialNecesario->add(new Material(material, cantidadNecesaria));
        }
    }
}