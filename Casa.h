#ifndef CASA_H
#define CASA_H

#include "EnumProcesos.h"
#include "List.h"
#include <string>

class Casa
{
private:
    Queue<Proceso> procesos;    // esta es la cola de procesos para llevar a cabo a lo largo de la construccion
    Stack<void *> cemento;      // esta es una pila de cemento, simulando una bodega con sacos de cemento
    Stack<void *> madera;       // esta es una pila de madera, simulando una bodega con reglas de madera
    Stack<void *> decoraciones; // esta es una pila de decoraciones, simulando una bodega con cajas de lavamanos, inodoros, ventanas, etc
    Queue<void *> trabajadores; // esta es la cola que simula el check-in y check-out de los trabajadores
public:
    Node *sacarCemento();         // simula el sacar un saco de cemento de la bodega
    void guardarCemento();        // simula el guardar un saco de cemento en la bodega
    Node *sacarMadera();          // simuila el sacar una regla de madera de la bodega
    void guardarMadera();         // simula el guardar una regla de madera en la bodega
    Node *sacarDecoracion();      // simula el sacar una decoracion de la bodega
    void guardarDecoracion();     // simula el guardar una decoracion en la bodega
    void ejecutarProcesoActual(); /*despliega un mensaje indicando el proceso en el que se encuentra, verifica la disponibilidad de trabajadores y materiales para realizar el proceso
                                    actual, de no cumplir con alguno de los dos espera a que los hilos respectivos suplan al programa de los recursos necesitados,
                                    en caso de ser materiales indica al programa que se requiere el tipo de material especifico para que se habilite la "compra" de este material*/
    void siguienteProceso();      // avanza en la cola de procesos para cambiar al siguiente proceso
    void agregarProceso();        // añade procesos a la cola de procesos
}

#endif