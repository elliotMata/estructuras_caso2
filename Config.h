#ifndef CONFIG_H
#define CONFIG_H

#include "json.hpp"

using json = nlohmann::json;

class Config
{
private:
    string[] procesos;
    string[] tipoPersonal;
    int[] jefeConfig;
    int[] personalNecesarioConfig;
    int[] compradorConfig;
    int[] procesoConfig;

public:
}

#endif