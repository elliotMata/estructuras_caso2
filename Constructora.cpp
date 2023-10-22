#include <iostream>
#include <iomanip>

#include "Constructora.h"

Constructora::Constructora()
{
    config = new Config();
    casa = new Casa(config, config->getProcesos());
    jefe = new Jefe(config);
    comprador = new Comprador(config);
}

void Constructora::llamarTrabajadores()
{
    vector<string> trabajadores = casa->getProcesoActual()->getPersonalFaltante();
    for (const string &trabajador : trabajadores)
    {
        Persona *cuadrilla = jefe->llamarTrabajadores(trabajador);
        casa->checkIn(cuadrilla);
    }
}

void Constructora::comprarMaterial()
{
    unordered_map<string, int> materiales = casa->getProcesoActual()->getMaterialFaltante();
    for (const auto &pair : materiales)
    {
        Material paquete = comprador->comprar(pair.first, pair.second);
        casa->guardarMaterial(paquete.getCantidadMaterial(), paquete.getNombreMaterial());
    }
}

void imprimirMateriales(Casa *casa)
{
    cout << "\n*********************************" << endl;
    cout << "*      CANTIDAD MATERIALES      *" << endl;
    cout << "*-------------------------------*" << endl;
    cout << "* Cemento > " << std::setw(3) << std::setfill(' ') << casa->getCantidadMaterial("Cemento") << "                 *" << endl;
    cout << "*  Madera > " << std::setw(3) << std::setfill(' ') << casa->getCantidadMaterial("Madera") << "                 *" << endl;
    cout << "*   Decor > " << std::setw(3) << std::setfill(' ') << casa->getCantidadMaterial("Decoraciones") << "                 *" << endl;
    cout << "*********************************\n"
         << endl;
}

void imprimirMaterialNecesario(Casa *casa)
{
    List<Material> *materialNecesario = casa->getProcesoActual()->getMaterialNecesario();
    cout << "\n*********************************" << endl;
    cout << "*    MATERIALES NECESARIOS      *" << endl;
    cout << "*-------------------------------*" << endl;
    for (int i = 0; i < materialNecesario->getSize(); i++)
    {
        Material *material = materialNecesario->find(i);
        string nombre = material->getNombreMaterial();
        if (nombre == "Decoraciones")
        {
            nombre = "Decor";
        }
        cout << "* " << std::setw(7) << std::setfill(' ') << nombre << " > " << material->getCantidadMaterial() << "                  *" << endl;
    }
    cout << "*********************************\n"
         << endl;
}

void Constructora::iniciarConstruccion()
{
    cout << "\n\033[1;36m*** CONSTRUCCION DE LA CASA ***\033[0m" << endl;
    while (casa->hayMasProcesos())
    {
        Proceso *procesoActual = casa->getProcesoActual();
        cout << "\n\033[1;36m---------------------------------------------\033[0m" << endl;
        cout << "\n\033[1;36mIniciando proceso: " << procesoActual->getNombreProceso() << "\033[0m" << endl;
        imprimirMaterialNecesario(casa);
        while (!procesoActual->verificarMaterial(casa->getMaterialesDisponibles()))
        {
            cout << "Comprando materiales necesarios" << endl;
            comprarMaterial();
            imprimirMateriales(casa);
        }

        /*while (!procesoActual->verificarPersonal(casa->getTrabajadoresDisponibles()))
        {
            // cout << "Llamando personal necesario" << endl;
            // cout << casa->getTrabajadoresDisponibles()->getSize() << endl;
            llamarTrabajadores();
        }*/

        cout << "Finalizando proceso: " << procesoActual->getNombreProceso() << endl;
        casa->siguienteProceso();
    }
    cout << "\n\033[1;36mCONSTRUCCION FINALIZADA!\033[0m\n"
         << endl;
}