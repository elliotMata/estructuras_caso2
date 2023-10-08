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
    // TODO
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