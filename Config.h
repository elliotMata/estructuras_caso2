#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <iostream>
#include <unordered_map> 
#include <vector>

#include "json.hpp"

using json = nlohmann::json;
using namespace std;

class Config
{
private:
    json configProcesos;
    json configDuraciones;
    json configComprador;
    json configJefe;
    unordered_map <string, json> requisitosProcesos;
    vector<string> procesos;

    void createMap ();

public:
    Config();
    
    vector<string> getProcesoTipoTrabajador(string proceso);
    int getProcesoMinimoTrabajadores(string proceso);
    int getProcesoMaximoTrabajadores(string proceso);
    vector<string> getProcesoTipoMaterial(string proceso);
    int getProcesoMinimoMateriales(string proceso);
    int getProcesoMaximoMateriales(string proceso);
    int getProcesoSizeRequisitos(string proceso);

    int getCompradorCantidadMinima();
    int getCompradorCantidadMaxima();
    int getCompradorDuracionMinima();
    int getCompradorDuracionMaxima();

    int getJefeMinimoPersonal(string tipo);
    int getJefeMaximoPersonal(string tipo);
    int getJefeDuracionMinima();
    int getJefeDuracionMaxima();

    int getDuracionProcesoMinima();
    int getDuracionProcesoMaxima();
    int getDuracionRevisionMinima();
    int getDuracionRevisionMaxima();

    vector<string> getProcesos();
};

#endif