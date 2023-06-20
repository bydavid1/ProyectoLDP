#ifndef TECNICO_H
#define TECNICO_H

#include "Empleado.h"

class Tecnico : public Empleado {
public:
    Tecnico(string nombre, string direccion, string fechaNacimiento, char sexo)
        : Empleado(nombre, direccion, fechaNacimiento, sexo) {}

    void mostrarInformacion() {
        cout << "Tipo de empleado: Técnico" << endl;
    }
};

#endif
