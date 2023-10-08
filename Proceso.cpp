#include "Proceso.h"
#include "List.h"
#include "Persona.h"
#include <vector>

using namespace std;
using json = nlohmann::json;

bool Proceso::verificarPersonal(List<Persona> pPersonal)
{
    Persona *necesario, *disponible;
    for (int pos = 0; pos < personalNecesario.getSize(); pos++)
    {
        necesario = personalNecesario.find(pos);
        disponible = pPersonal.find(pos);
        if (necesario->getCantidadPersona() > disponible->getCantidadPersona())
        {
            personalFaltante.add(new Persona(necesario->getTipoPersona(), 0));
        }
    }
    return personalFaltante.isEmpty();
}

bool Proceso::verificarMaterial(int pCemento, int pMadera, int pDecor)
{
    Material *necesario;
    for (int pos = 0; pos < materialNecesario.getSize(); pos++)
    {
        necesario = materialNecesario.find(pos);
        if (necesario->getNombreMaterial() == "Cemento")
        {
            if (necesario->getCantidadMaterial() > pCemento)
            {
                materialFaltante.add(new Material("Cemento", 0));
            }
        }
        if (necesario->getNombreMaterial() == "Madera")
        {
            if (necesario->getCantidadMaterial() > pMadera)
            {
                materialFaltante.add(new Material("Madera", 0));
            }
        }
        if (necesario->getNombreMaterial() == "Decoraciones")
        {
            if (necesario->getCantidadMaterial() > pDecor)
            {
                materialFaltante.add(new Material("Decoraciones", 0));
            }
        }
    }
    return materialFaltante.isEmpty();
}

Proceso::Proceso(json configProceso, string nombre)
{
    this->nombreProceso = nombre;
    int minPersonal = configProceso["minimoTrabajadores"];
    int maxPersonal = configProceso["maximoTrabajadores"];
    vector<string> personal = configProceso["tipoTrabajadores"];
    for (const string &trabajador : personal)
    {
        int cantidadNecesaria = (rand() % (maxPersonal - minPersonal + 1)) + minPersonal;
        this->personalNecesario.add(new Persona(trabajador, cantidadNecesaria));
    }
    if (configProceso.size() > 3)
    {
        int minMaterial = configProceso["minimoMateriales"];
        int maxMaterial = configProceso["maximoMateriales"];
        vector<string> materiales = configProceso["tipoMateriales"];
        for (const string &material : materiales)
        {
            int cantidadNecesaria = (rand() % (maxMaterial - minMaterial + 1)) + minMaterial;
            this->materialNecesario.add(new Material(material, cantidadNecesaria));
        }
    }
}