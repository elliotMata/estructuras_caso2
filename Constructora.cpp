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
        // cout << trabajador << endl;
        Persona *cuadrilla = jefe->llamarTrabajadores(trabajador);
        // cout << cuadrilla.getCantidadPersona() << endl;
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
            casa->guardarCemento(paquete.getCantidadMaterial());
            // cout << "comprando cemento" << endl;
        }
        else if (material == "Madera")
        {
            casa->guardarMadera(paquete.getCantidadMaterial());
            // cout << "comprando madera" << endl;
        }
        else
        {
            casa->guardarDecoracion(paquete.getCantidadMaterial());
            // cout << "comprando decoraciones" << endl;
        }
    }
}

void Constructora::iniciarConstruccion()
{
    while (casa->hayMasProcesos())
    {
        Proceso *procesoActual = casa->getProcesoActual();
        cout << "Iniciando proceso: " << procesoActual->getNombreProceso() << endl;
        while (!procesoActual->verificarMaterial(casa->getCantidadCemento(), casa->getCantidadMadera(), casa->getCantidadDecoraciones()))
        {
            cout << "Comprando materiales necesarios" << endl;
            comprarMaterial();
        }
        // cout << procesoActual->getPersonalNecesario()->getSize() << endl;
        while (!procesoActual->verificarPersonal(casa->getTrabajadoresDisponibles()))
        {
            // cout << "Llamando personal necesario" << endl;
            // cout << casa->getTrabajadoresDisponibles()->getSize() << endl;
            llamarTrabajadores();
        }
        cout << "Finalizando proceso: " << procesoActual->getNombreProceso() << endl;
        casa->siguienteProceso();
    }
    cout << "Construccion finalizada!" << endl;
}