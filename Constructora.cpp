#include <iostream>
#include <iomanip>
#include <thread>

#include "Constructora.h"

void imprimirProcesos (Casa *casa)
{
    int cantidadProcesos = casa->getProcesos()->getSize();
    cout << "\n*********************************" << endl;
    cout << "*       COLA DE PROCESOS        *" << endl;
    cout << "*-------------------------------*" << endl;
    casa->getProcesos()->resetSearch();
    for (int i = 0; i < cantidadProcesos; i++)
    {
        cout << "* " << std::setw(22) << std::setfill(' ') << casa->getProcesos()->next()->getNombreProceso() <<  "        *" << endl;
    }
    cout << "*********************************" << endl;
}

void imprimirMateriales(Casa *casa)
{
    cout << "*********************************" << endl;
    cout << "*      CANTIDAD MATERIALES      *" << endl;
    cout << "*-------------------------------*" << endl;
    cout << "* " << std::setw(19) << std::setfill(' ') << "Pila cemento" << " > " << std::setw(5) << std::setfill(' ') << casa->getCantidadMaterial("Cemento") << "   *" << endl;
    cout << "* " << std::setw(19) << std::setfill(' ') << "Pila madera" << " > " << std::setw(5) << std::setfill(' ') << casa->getCantidadMaterial("Madera") << "   *" << endl;
    cout << "* " << std::setw(19) << std::setfill(' ') << "Pila decoraciones" << " > " <<std::setw(5) << std::setfill(' ') << casa->getCantidadMaterial("Decoraciones") << "   *" << endl;
    cout << "*********************************\n" << endl;
}

void imprimirPersonal(Casa *casa)
{
    int cantidadTrabajadores = casa->getTrabajadores()->getSize();
    cout << "\n*********************************" << endl;
    cout << "*       CANTIDAD PERSONAL       *" << endl;
    cout << "*-------------------------------*" << endl;
   
    for (int i = 0; i < cantidadTrabajadores; i++)
    {
        cout << "* " << std::setw(22) << std::setfill(' ') << casa->getTrabajadores()->find(i)->getTipoPersona() + " > " << std::setw(5) << std::setfill(' ') << casa->getTrabajadores()->find(i)->getCantidadPersona() << "   *" << endl;
    }

    cout << "*********************************\n" << endl;
}

void imprimirMaterialNecesario(Casa *casa)
{
    List<Material> *materialNecesario = casa->getProcesoActual()->getMaterialNecesario();
    cout << "*********************************" << endl;
    cout << "*    MATERIALES NECESARIOS      *" << endl;
    cout << "*-------------------------------*" << endl;
    for (int i = 0; i < materialNecesario->getSize(); i++)
    {
        Material *material = materialNecesario->find(i);
        string nombre = material->getNombreMaterial();
        cout << "* " << std::setw(19) << std::setfill(' ') << nombre << " > " << std::setw(5) << std::setfill(' ') << material->getCantidadMaterial() << "   *" << endl;
    }
    cout << "*********************************\n" << endl;
}

void imprimirPersonalNecesario(Casa *casa)
{
    List<Persona> *personalNecesario = casa->getProcesoActual()->getPersonalNecesario();
    cout << "*********************************" << endl;
    cout << "*     PERSONAL NECESARIO        *" << endl;
    cout << "*-------------------------------*" << endl;
    for (int i = 0; i < personalNecesario->getSize(); i++)
    {
        Persona *persona = personalNecesario->find(i);
        string nombre = persona->getTipoPersona();
        cout << "* " << std::setw(19) << std::setfill(' ') << nombre << " > " << std::setw(5) << std::setfill(' ') << persona->getCantidadPersona() << "   *" << endl;
    }
    cout << "*********************************\n\n" << endl;
    cout << "---------------------------------\n\n" << endl;
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
        imprimirProcesos(casa);
        imprimirPersonal(casa);
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
        cout << "Realizando proceso: " << procesoActual->getNombreProceso() << endl;
        this_thread::sleep_for(chrono::milliseconds(((rand() % (procesoActual->getMaxDuracion() - procesoActual->getMinDuracion() + 1)) + procesoActual->getMinDuracion()) * config->getDuracionHoraSimulador()));
        if (thread1.joinable())
            thread1.join();
        if (thread2.joinable())
            thread2.join();
        cout << "Revisando finalizacion de proceso: " << procesoActual->getNombreProceso() << endl;
        this_thread::sleep_for(chrono::milliseconds(((rand() % (procesoActual->getMaxDuracionRevision() - procesoActual->getMinDuracionRevision() + 1)) + procesoActual->getMinDuracionRevision()) * config->getDuracionHoraSimulador()));
        casa->siguienteProceso();
    }
    cout << "\n\033[1;36m---------------------------------------------\033[0m" << endl;
    cout << "\n\033[1;36mCONSTRUCCION FINALIZADA!\033[0m\n"
         << endl;
}