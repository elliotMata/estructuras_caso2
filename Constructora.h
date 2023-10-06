#ifndef CONSTRUCTORA_h
#define CONSTRUCTORA_H

#include "Casa.h"
#include "Comprador.h"
#include "Jefe.h"

class Constructora
{
private:
    Casa *casa;
    Jefe *jefe;
    Comprador *tienda;

public:
    Constructora(); // se saca la info del json para darle valores a los atributos de los objetos

    void iniciarConstruccion();         // aqui va a estar el hilo principal del programa, donde se realiza el ciclo de procesos de la casa y mostrar mensajes respectivos
    void llamarTrabajadores();          // se indica a jefe que debe llamar trabajadores y se agregan a la cola de checkin de la casa
    void comprarMaterial(string pTipo); // se indica al comprador que debe comprar material y se almacena en la pila correspondiente de la casa
}

#endif