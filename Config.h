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
    
    // metodos para los procesos
    vector<string> getProcesoTipoTrabajador(string proceso);
    int getProcesoMinimoTrabajadores(string proceso);
    int getProcesoMaximoTrabajadores(string proceso);
    vector<string> getProcesoTipoMaterial(string proceso);
    int getProcesoMinimoMateriales(string proceso);
    int getProcesoMaximoMateriales(string proceso);
    int getProcesoSizeRequisitos(string proceso);

    // metodos para el comprador
    int getCompradorCantidadMinima();
    int getCompradorCantidadMaxima();
    int getCompradorDuracionMinima();
    int getCompradorDuracionMaxima();

    // metodos para el jefe
    int getJefeMinimoPersonal(string tipo);
    int getJefeMaximoPersonal(string tipo);
    int getJefeDuracionMinima();
    int getJefeDuracionMaxima();

    // metodos para la duracion
    int getDuracionProcesoMinima();
    int getDuracionProcesoMaxima();
    int getDuracionRevisionMinima();
    int getDuracionRevisionMaxima();

    vector<string> getProcesos();
};

#endif