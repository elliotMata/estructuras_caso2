#include "Constructora.h"

Constructora::Constructora()
{
    config = new Config();
    casa = new Casa(config->getConfigProcesos(), config->getProcesos());
    jefe = new Jefe(config->getConfigJefe());
    comprador = new Comprador(config->getConfigComprador());
}

void Constructora::llamarTrabajadores()
{
    vector<string> trabajadores = casa->getProcesoActual()->getPersonalFaltante();
    for (const string &trabajador : trabajadores)
    {
        Persona cuadrilla = jefe->llamarTrabajadores(trabajador);
        casa->checkIn(cuadrilla);
    }
}

void Constructora::comprarMaterial()
{
    vector<string> materiales = casa->getProcesoActual()->getMaterialFaltante();
    for (const string &material : materiales)
    {
        Material paquete = comprador->comprar(material);
        if (material == "Cemento")
        {
            casa->guardarCemento(paquete->getCantidadMaterial());
        }
        else if (material == "Madera")
        {
            casa->guardarMadera(paquete->getCantidadMaterial());
        }
        else
        {
            casa->guardarDecoracion(paquete->getCantidadMaterial());
        }
    }
}