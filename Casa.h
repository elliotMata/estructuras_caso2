#ifndef CASA_H
#define CASA_H

#include "List.h"
#include "Proceso.h"
#include "Config.h"

#include <string>
#include <vector>

class Casa
{
private:
    Queue<Proceso> *procesos;                         // esta es la cola de procesos para llevar a cabo a lo largo de la construccion
    Stack<Material> *cemento, *madera, *decoraciones; // pilas de los diferentes materiales
    Queue<Persona> *trabajadores;                     // esta es la cola que simula el check-in y check-out de los trabajadores
public:
    Casa(Config *config, vector<string> procesos);

    List<Persona>* getTrabajadoresDisponibles();
    Queue<Persona>* getTrabajadores();
    void sacarCemento(int cantidad);        // simula el sacar un saco de cemento de la bodega
    void guardarCemento(int cantidad);      // simula el guardar un saco de cemento en la bodega
    int getCantidadCemento();               // hace inventario de cuantos sacos de cemento hay en la bodega
    void sacarMadera(int cantidad);         // simula el sacar una regla de madera de la bodega
    void guardarMadera(int cantidad);       // simula el guardar una regla de madera en la bodega
    int getCantidadMadera();                // hace inventario de cuantas reglas de madera hay en la bodega
    void sacarDecoracion(int cantidad);     // simula el sacar una decoracion de la bodega
    void guardarDecoracion(int cantidad);   // simula el guardar una decoracion en la bodega
    int getCantidadDecoraciones();          // hace inventario de cuantas decoraciones hay en la bodega
    Proceso *getProcesoActual();            // devuelve el proceso actual para acceder a su informacion
    void siguienteProceso();                // avanza la cola de procesos
    bool hayMasProcesos ();                 // indica si hay mas procesos por ejecutar
    void agregarProceso(Proceso *pProceso); // añade un proceso a la cola
    void checkIn(Persona *trabajadores);    // hilo, simula el check in de cada trabajador en la cola y lo añade a la cantidad disponible para el proceso actual
    void checkOut();                        // hilo, simula el check out de cada trabajador en la cola (todos los del proceso se añaden a la cola cuando se termine para simular que terminaron y se van a ir)
};

#endif