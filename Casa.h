#ifndef CASA_H
#define CASA_H

#include "List.h"
#include "Proceso.h"
#include <string>

class Casa
{
private:
    Queue <Proceso> *procesos;                       // esta es la cola de procesos para llevar a cabo a lo largo de la construccion
    Stack <Material> *cemento, *madera, *decoraciones; // pilas de los diferentes materiales
    Queue <Persona> *trabajadores;                   // esta es la cola que simula el check-in y check-out de los trabajadores
public:
    Node <Material> *sacarCemento();                            // simula el sacar un saco de cemento de la bodega
    void guardarCemento();                           // simula el guardar un saco de cemento en la bodega
    Node <Material> *sacarMadera();                             // simuila el sacar una regla de madera de la bodega
    void guardarMadera();                            // simula el guardar una regla de madera en la bodega
    Node <Material> *sacarDecoracion();                         // simula el sacar una decoracion de la bodega
    void guardarDecoracion();                        // simula el guardar una decoracion en la bodega
    Proceso *getProcesoActual();                     // devuelve el proceso actual para acceder a su informacion
    void siguienteProceso();                         // avanza la cola de procesos
    void agregarProceso(Proceso *pProceso);          // añade un proceso a la cola
    void llegadaTrabajadores(Persona *trabajadores); // hilo, grupo de trabajadores que llegan, se agregan a la cola de trabajadores
    void checkIn();                                  // hilo, simula el check in de cada trabajador en la cola y lo añade a la cantidad disponible para el proceso actual
    void checkOut();                                 // hilo, simula el check out de cada trabajador en la cola (todos los del proceso se añaden a la cola cuando se termine para simular que terminaron y se van a ir)
};

#endif