// clase para los materiales

#ifndef _MATERIAL_
#define _MATERIAL_

#include <string>
#include <iostream>

using namespace std;

class Material {
    private:
        string nombreMaterial;
        int cantidad; // asumiendo que el material se trabajaria en paquetes
                      // entonces cada paquete tiene una cierta cantidad

    public:
        Material (string nombreMaterial, int cantidad){
            this->nombreMaterial = nombreMaterial;
            this->cantidad = cantidad;
        }

        string getNombreMaterial (){
            return this->nombreMaterial;
        }

        int getCantidadMaterial (){
            return this->cantidad;
        }
};

#endif