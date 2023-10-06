#include <iostream>
#include <fstream>
#include "json.hpp"
#include "Constructora.h"

using namespace std;

int main()
{
    ifstream config_file("configuracion.json");
    nlohmann::json config;
    config_file >> config;
    config_file.close();
}