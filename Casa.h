#ifndef CASA_H
#define CASA_H

#include <string>
#include <iostream>
#include <unordered_map> 
#include <vector>

#include "List.h"
#include "Proceso.h"
#include "Config.h"

using namespace std;

class Casa
{
private:
    Queue<Proceso> *procesos;                               // esta es la cola de procesos para llevar a cabo a lo largo de la construccion
    Stack<Material> *cemento, *madera, *decoraciones;       // pilas de los diferentes materiales
    Queue<Persona> *trabajadores;                           // esta es la cola que simula el check-in y check-out de los trabajadores
    unordered_map<string, Stack<Material>*> pilasMateriales;

    void crearMapaPilas();

public:
    Casa(Config *config, vector<string> procesos);

    List<Persona>* getTrabajadoresDisponibles();
    Queue<Persona>* getTrabajadores();
    void sacarMaterial(int cantidad, string material);
    void guardarMaterial(int cantidad, string material);
    int getCantidadMaterial(string material);

    Proceso *getProcesoActual();            // devuelve el proceso actual para acceder a su informacion
    void siguienteProceso();                // avanza la cola de procesos
    bool hayMasProcesos ();                 // indica si hay mas procesos por ejecutar
    void agregarProceso(Proceso *pProceso); // añade un proceso a la cola
    void checkIn(Persona *trabajadores);    // hilo, simula el check in de cada trabajador en la cola y lo añade a la cantidad disponible para el proceso actual
    void checkOut();                        // hilo, simula el check out de cada trabajador en la cola (todos los del proceso se añaden a la cola cuando se termine para simular que terminaron y se van a ir)
};

#endif