#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "Empleado.h"

class Supervisor : public Empleado {
public:
    Supervisor(string nombre, string direccion, string fechaNacimiento, char sexo)
        : Empleado(nombre, direccion, fechaNacimiento, sexo) {}

    void mostrarInformacion() {
        cout << "Tipo de empleado: Supervisor" << endl;
    }
};

#endif
