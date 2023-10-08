#include "Config.h"

#include <fstream>
#include <vector>
#include <string>
#include <iostream>

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
    this->procesos = config["procesos"];
    this->configDuraciones = config["Duraciones"];
}