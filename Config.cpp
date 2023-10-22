#include <fstream>
#include <vector>
#include <string>
#include <iostream>

#include "Config.h"

using namespace std;

Config::Config()
{
    ifstream config_file("configuracion.json");
    json config;
    config_file >> config;
    config_file.close();

    this->configComprador = config["Comprador"];
    this->configJefe = config["Jefe"];
    this->configProcesos = config["ProcesosRequerimientos"];
    for (string item : config["procesos"])
    {
        this->procesos.push_back(item);
    }
    this->configDuraciones = config["Duraciones"];
    createMap();
}

void Config::createMap()
{
    for (string proceso : procesos)
    {
        requisitosProcesos.insert(make_pair(proceso, configProcesos[proceso]));
    }
}

vector<string> Config::getProcesoTipoTrabajador(string proceso)
{
    json items = requisitosProcesos.at(proceso);
    return items["tipoTrabajadores"];
}

int Config::getProcesoMinimoTrabajadores(string proceso)
{
    json items = requisitosProcesos.at(proceso);
    return items["minimoTrabajadores"];
}

int Config::getProcesoMaximoTrabajadores(string proceso)
{
    json items = requisitosProcesos.at(proceso);
    return items["maximoTrabajadores"];
}

vector<string> Config::getProcesoTipoMaterial(string proceso)
{
    json items = requisitosProcesos.at(proceso);
    return items["tipoMateriales"];
}

int Config::getProcesoMinimoMateriales(string proceso)
{
    json items = requisitosProcesos.at(proceso);
    return items["minimoMateriales"];
}

int Config::getProcesoMaximoMateriales(string proceso)
{
    json items = requisitosProcesos.at(proceso);
    return items["maximoMateriales"];
}

int Config::getProcesoSizeRequisitos(string proceso)
{
    json items = requisitosProcesos.at(proceso);
    return items.size();
}

int Config::getCompradorCantidadMinima()
{
    return configComprador["Cantidades"]["minimo"];
}

int Config::getCompradorCantidadMaxima()
{
    return configComprador["Cantidades"]["maximo"];
}

int Config::getCompradorDuracionMinima()
{
    return configComprador["Duracion"]["minimo"];
}

int Config::getCompradorDuracionMaxima()
{
    return configComprador["Duracion"]["maximo"];
}

int Config::getJefeMinimoPersonal(string tipo)
{
    return configJefe[tipo]["minimo"];
}

int Config::getJefeMaximoPersonal(string tipo)
{
    return configJefe[tipo]["maximo"];
}

int Config::getJefeDuracionMinima()
{
    return configJefe["DuracionLlamadaPersonal"]["minimo"];
}

int Config::getJefeDuracionMaxima()
{
    return configJefe["DuracionLlamadaPersonal"]["maximo"];
}

int Config::getDuracionProcesoMinima()
{
    return configDuraciones["Procesos"]["minimo"];
}

int Config::getDuracionProcesoMaxima()
{
    return configDuraciones["Procesos"]["maximo"];
}

int Config::getDuracionRevisionMinima()
{
    return configDuraciones["Revision"]["minimo"];
}

int Config::getDuracionRevisionMaxima()
{
    return configDuraciones["Revision"]["maximo"];
}

int Config::getDuracionHoraSimulador()
{
    return configDuraciones["HoraSimulador"];
}

vector<string> Config::getProcesos()
{
    return this->procesos;
}