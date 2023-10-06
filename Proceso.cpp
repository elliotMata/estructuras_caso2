#include "Proceso.h"

using namespace std;

bool Proceso::verificarPersonal(List pPersonal)
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

Proceso::Proceso(nlohmann::json configProceso)
{
    this->nombreProceso = configProceso.find(0);
    int minPersonal, maxPersonal, minMaterial, maxMaterial;
    minPersonal = configProceso.find(2);
    maxPersonal = configProceso.find(3);
    List<string> personal = configProceso.find(1);
    for (int i = 0; i < personal.getSize(); i++)
    {
        int cantidadNecesaria = (rand() % (maxPersonal - minPersonal + 1)) + minPersonal;
        this->personalNecesario.add(new Persona(personal.find(i), cantidadNecesaria));
    }
    if (configProceso.getSize() > 4)
    {
        minMaterial = configProceso.find(5);
        maxMaterial = configProceso.find(6);
        List<string> materiales = configProceso.find(4);
        for (int i = 0; i < materiales.getSize(); i++)
        {
            int cantidadNecesaria = (rand() % (maxMaterial - minMaterial + 1)) + minMaterial;
            this->materialNecesario.add(new Material(materiales.find(1), cantidadNecesaria));
        }
    }
}