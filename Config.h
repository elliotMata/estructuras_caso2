#ifndef CONFIG_H
#define CONFIG_H

#include "json.hpp"

#include <string>
#include <iostream>
#include <vector>

using json = nlohmann::json;
using namespace std;

class Config
{
private:
    json configProcesos;
    json configDuraciones;
    json configComprador;
    json configJefe;
    vector<string> procesos;

public:
    Config();

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

    vector<string> getProcesos()
    {
        return this->procesos;
    }
};

#endif