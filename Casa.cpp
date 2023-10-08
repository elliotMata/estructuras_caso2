#include "Casa.h"
#include <map>

Casa::Casa(json configProcesos, vector<string> procesos)
{
    this->procesos = new List<Proceso>();
    this->cemento = new List<Material>();
    this->madera = new List<Material>();
    this->decoraciones = new List<Material>();
    this->trabajadores = new List<Persona>();
    for (const string &proceso : procesos)
    {
        agregarProceso(new Proceso(configProcesos[proceso], proceso));
    }
}

void Casa::agregarProceso(Proceso *proceso)
{
    procesos->enqueue(proceso);
}

Proceso *Casa::getProcesoActual()
{
    return procesos->front();
}

void Casa::siguienteProceso()
{
    procesos->dequeue();
    checkOut();
}

void Casa::sacarCemento(int cantidad)
{
    while (cantidad-- > 0)
    {
        cemento->pop();
    }
}

void Casa::sacarDecoracion(int cantidad)
{
    while (cantidad-- > 0)
    {
        decoraciones->pop();
    }
}

void Casa::sacarMadera(int cantidad)
{
    while (cantidad-- > 0)
    {
        madera->pop();
    }
}

void Casa::guardarCemento(int cantidad)
{
    while (cantidad-- > 0)
    {
        cemento->push(new Material("Cemento", 1));
    }
}

void Casa::guardarDecoracion(int cantidad)
{
    while (cantidad-- > 0)
    {
        decoraciones->push(new Material("Decoraciones", 1));
    }
}

void Casa::guardarMadera(int cantidad)
{
    while (cantidad-- > 0)
    {
        madera->push(new Material("Madera", 1));
    }
}

int Casa::getCantidadCemento()
{
    return cemento->getSize();
}

int Casa::getCantidadDecoraciones()
{
    return decoraciones->getSize();
}

int Casa::getCantidadMadera()
{
    return madera->getSize();
}

void Casa::checkIn(Persona *pTrabajadores)
{
    int count = pTrabajadores->getCantidadPersona();
    string tipo = pTrabajadores->getTipoPersona();
    while (count-- > 0)
    {
        trabajadores->enqueue(new Persona(tipo, 1));
    }
}

void Casa::checkOut()
{
    while (!trabajadores->isEmpty())
    {
        trabajadores->dequeue();
    }
}

Queue<Persona>* Casa::getTrabajadores()
{
    return this->trabajadores;
}

Queue<Persona>* Casa::getTrabajadoresDisponibles()
{
    List<Persona> *result = new List<Persona>();
    Queue<Persona> *trabajadoresTemp = trabajadores;
    map<string, int> counts;
    while (!trabajadoresTemp->isEmpty())
    {
        string tipo = trabajadoresTemp->front()->getTipoPersona();
        counts[tipo]++;
        trabajadoresTemp->dequeue();
    }
    for (const auto &pair : counts)
    {
        result->add(new Persona(pair.first, pair.second));
    }
    return result;
}