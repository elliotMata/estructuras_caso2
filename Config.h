#ifndef CONFIG_H
#define CONFIG_H

#include "json.hpp"

using json = nlohmann::json;

class Config
{
private:
    json configProcesos;
    json configDuraciones;
    json configComprador;
    json configJefe;
    string[] procesos;

public:
    Config() {}

    json getConfigProcesos()
    {
        return this->configProcesos;
    }

    json getConfigDuraciones()
    {
        return this->configDuraciones;
    }

    json getConfigComprador()
    {
        return this->configComprador;
    }

    json getConfigJefe()
    {
        return this->configJefe;
    }

    string[] getProcesos()
    {
        return this->procesos;
    }
}

#endif