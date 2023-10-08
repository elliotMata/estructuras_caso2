#include "Casa.h"

Casa::Casa(json configProcesos, vector<string> procesos)
{
    procesos = new Queue<Proceso>();
    cemento = new Stack<Material>();
    madera = new Stack<Material>();
    decoraciones = new Stack<Material>();
    trabajadores = new Queue<Persona>();
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
}

void Casa::sacarCemento(int cantidad)
{
    while (cantidad-- > 0)
    {
        cemento.pop();
    }
}

void Casa::sacarDecoracion(int cantidad)
{
    while (cantidad-- > 0)
    {
        decoraciones.pop();
    }
}

void Casa::sacarMadera(int cantidad)
{
    while (cantidad-- > 0)
    {
        madera.pop();
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