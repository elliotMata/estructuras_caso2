#ifndef CONFIG_H
#define CONFIG_H

#include "json.hpp"

using json = nlohmann::json;

class Config
{
private:
    json configProcesos;
    json configDuraciones;
    json configBusquedaRecursos;

public:
    nlohmann::json getConfigProcesos()
    {
        return configProcesos;
    }
}

#endif