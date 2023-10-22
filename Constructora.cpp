#include <iostream>
#include <iomanip>
#include <thread>

#include "Constructora.h"

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

void imprimirPersonal(Casa *casa)
{
    int cantidadTrabajadores = casa->getTrabajadores()->getSize();
    cout << "\n*********************************" << endl;
    cout << "*       CANTIDAD PERSONAL       *" << endl;
    cout << "*-------------------------------*" << endl;
    // cout << cantidadTrabajadores << endl;

    for (int i = 0; i < cantidadTrabajadores; i++)
    {
        cout << "* " << std::setw(16) << std::setfill(' ') << casa->getTrabajadores()->find(i)->getTipoPersona() + " > " << std::setw(9) << std::setfill(' ') << casa->getTrabajadores()->find(i)->getCantidadPersona() << "     *" << endl;
    }

    cout << "*********************************\n"
         << endl;
}

Constructora::Constructora()
{
    config = new Config();
    casa = new Casa(config, config->getProcesos());
    jefe = new Jefe(config);
    comprador = new Comprador(config);
}

void Constructora::llamarTrabajadores()
{
    unordered_map<string, int> trabajadores = casa->getProcesoActual()->getPersonalFaltante();
    for (const auto &pair : trabajadores)
    {
        Persona *cuadrilla = jefe->llamarTrabajadores(pair.first, pair.second);
        casa->checkIn(cuadrilla);
    }
    imprimirPersonal(casa);
}

void Constructora::comprarMaterial()
{
    unordered_map<string, int> materiales = casa->getProcesoActual()->getMaterialFaltante();
    for (const auto &pair : materiales)
    {
        Material paquete = comprador->comprar(pair.first, pair.second);
        casa->guardarMaterial(paquete.getCantidadMaterial(), paquete.getNombreMaterial());
    }
    imprimirMateriales(casa);
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
    thread thread1;
    thread thread2;
    while (casa->hayMasProcesos())
    {
        Proceso *procesoActual = casa->getProcesoActual();
        cout << "\n\033[1;36m---------------------------------------------\033[0m" << endl;
        cout << "\n\033[1;36mIniciando proceso: " << procesoActual->getNombreProceso() << "\033[0m" << endl;
        imprimirMaterialNecesario(casa);
        if (!procesoActual->verificarMaterial(casa->getMaterialesDisponibles()))
        {
            cout << "Comprando materiales necesarios" << endl;
            thread1 = thread(&Constructora::comprarMaterial, this);
        }

        if (!procesoActual->verificarPersonal(casa->getTrabajadores()))
        {
            cout << "Llamando personal necesario" << endl;
            thread2 = thread(&Constructora::llamarTrabajadores, this);
        }
        if (thread1.joinable())
            thread1.join();
        if (thread2.joinable())
            thread2.join();
        cout << "Finalizando proceso: " << procesoActual->getNombreProceso() << endl;
        casa->siguienteProceso();
    }
    cout << "\n\033[1;36mCONSTRUCCION FINALIZADA!\033[0m\n"
         << endl;
}