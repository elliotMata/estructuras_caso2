#ifndef CONSTRUCTORA_h
#define CONSTRUCTORA_H

#include "json.hpp"
#include "Casa.h"
#include "Materiales\CompradorMaterial.h"
#include "Personas\Jefe.h"

using json = nlohmann::json;

class Constructora
{
private:
    Casa *casa;
    Jefe *jefe;
    Comprador *tienda;

public:
    Constructora(); // se saca la info del json para darle valores a los atributos de los objetos

    void iniciarConstruccion(); // aqui va a estar el hilo principal del programa, donde se realiza el ciclo de procesos de la casa y mostrar mensajes respectivos
    void llamarTrabajadores();  // se habilida el hilo de llamado de trabajadores para pedir mas personal y mostrar mensajes respectivos
    void comprarMaterial();     // se habilita el hilo de compra de materiales para abastecer bodegas y mostrar mensajes respectivos
}

#endif