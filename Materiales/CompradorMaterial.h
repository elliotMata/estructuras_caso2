// clase para el comprador de materiales

#ifndef _COMPRADOR_
#define _COMPRADOR_

#include <string>
#include <iostream>
#include <vector>

#include "Material.h"

using namespace std;

class Comprador {
    private:
        vector<Material> materiales;
        string nombreMaterial;
        int cantidadMinima, cantidadMaxima;

        /* para determinar la cantidad de materiales que se van a comprar
         * de acuerdo con los datos del json
         */
        int getCantidadComprar (){}

    public:
        Comprador (string nombreMaterial){
            this->nombreMaterial = nombreMaterial;
        }

        vector<Material> getMateriales (){
            return this->materiales; // retorna los materiales comprados
        }

        int comprar (){} // comprar los materiales pedidos
                         // la cantidad se obtiene de getCantidadComprar()
};

#endif