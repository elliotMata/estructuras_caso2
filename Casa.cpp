#include "Casa.h"
#include <unordered_map>

Casa::Casa(Config *config, vector<string> procesos)
{
    this->procesos = new List<Proceso>();
    this->cemento = new List<Material>();
    this->madera = new List<Material>();
    this->decoraciones = new List<Material>();
    this->trabajadores = new List<Persona>();
    for (const string &proceso : procesos)
    {
        agregarProceso(new Proceso(config, proceso));
    }
    crearMapaPilas();
}

void Casa::crearMapaPilas()
{
    pilasMateriales.insert(make_pair("Cemento", cemento));
    pilasMateriales.insert(make_pair("Madera", madera));
    pilasMateriales.insert(make_pair("Decoraciones", decoraciones));
}

void Casa::agregarProceso(Proceso *proceso)
{
    procesos->enqueue(proceso);
}

Proceso *Casa::getProcesoActual()
{
    return procesos->front()->getData();
}

void Casa::siguienteProceso()
{
    List<Material> *materiales = procesos->front()->getData()->getMaterialNecesario();
    List<Persona> *personal = procesos->front()->getData()->getPersonalNecesario();
    Material *materialActual;
    for (int pos = 0; pos < materiales->getSize(); pos++)
    {
        materialActual = materiales->find(pos);
        sacarMaterial(materialActual->getCantidadMaterial(), materialActual->getNombreMaterial());
    }
    for (int pos = 0; pos < personal->getSize(); pos++)
    {
        checkOut(personal->find(pos));
    }
    procesos->dequeue();
}

bool Casa::hayMasProcesos()
{
    if (procesos->isEmpty())
    {
        return false;
    }
    return true;
}

void Casa::sacarMaterial(int cantidad, string material)
{
    Stack<Material> *pila = pilasMateriales.at(material);
    while (cantidad-- > 0)
    {
        pila->pop();
    }
}

void Casa::guardarMaterial(int cantidad, string material)
{
    Stack<Material> *pila = pilasMateriales.at(material);
    while (cantidad-- > 0)
    {
        pila->push(new Material(material, 1));
    }
}

int Casa::getCantidadMaterial(string material)
{
    Stack<Material> *pila = pilasMateriales.at(material);
    return pila->getSize();
}

void Casa::checkIn(Persona *pTrabajadores)
{
    if (!trabajadores->isEmpty())
    {
        for (int i = 0; i < trabajadores->getSize(); i++)
        {
            Persona *trabajador = trabajadores->find(i);
            if (trabajador->getTipoPersona() == pTrabajadores->getTipoPersona())
            {
                trabajador->setCantidadPersona(trabajador->getCantidadPersona() + pTrabajadores->getCantidadPersona());
            }
            else
            {
                trabajadores->add(pTrabajadores);
            }
        }
    }
    else
    {
        trabajadores->add(pTrabajadores);
    }
}

void Casa::checkOut(Persona *pTrabajadores)
{
    for (int i = 0; i < trabajadores->getSize(); i++)
    {
        Persona *trabajador = trabajadores->find(i);
        if (trabajador->getTipoPersona() == pTrabajadores->getTipoPersona())
        {
            trabajador->setCantidadPersona(trabajador->getCantidadPersona() - pTrabajadores->getCantidadPersona());
        }
    }
}

List<Persona> *Casa::getTrabajadores()
{
    return this->trabajadores;
}

List<Persona> *Casa::getTrabajadoresDisponibles()
{
    List<Persona> *result = new List<Persona>();
    Queue<Persona> *trabajadoresTemp = new List<Persona>();
    trabajadores->resetSearch();
    while (trabajadores->next() != nullptr)
    {
        Persona *trabajador = trabajadores->next();
        trabajadoresTemp->enqueue(new Persona(*trabajador));
    }
    map<string, int> counts;
    while (!trabajadoresTemp->isEmpty())
    {
        string tipo = trabajadoresTemp->front()->getData()->getTipoPersona();
        counts[tipo]++;
        trabajadoresTemp->dequeue();
    }
    for (const auto &pair : counts)
    {
        result->add(new Persona(pair.first, pair.second));
    }
    return result;
}

unordered_map<string, int> Casa::getMaterialesDisponibles()
{
    unordered_map<string, int> result;
    for (const auto &pair : pilasMateriales)
    {
        result[pair.first] = pair.second->getSize();
    }
    return result;
}