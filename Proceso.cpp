#include <vector>
#include <unordered_map>

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

bool Proceso::verificarMaterial(unordered_map<string, int> disponibles)
{
    Material *necesario;
    materialFaltante.clear();
    for (int pos = 0; pos < materialNecesario->getSize(); pos++)
    {
        necesario = materialNecesario->find(pos);
        if (necesario->getCantidadMaterial() > disponibles[necesario->getNombreMaterial()])
        {
            materialFaltante[necesario->getNombreMaterial()] = necesario->getCantidadMaterial() - disponibles[necesario->getNombreMaterial()];
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