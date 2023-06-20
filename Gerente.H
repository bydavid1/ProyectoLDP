#ifndef GERENTE_H
#define GERENTE_H

#include "Empleado.h"

class Gerente : public Empleado {
public:
    Gerente(string nombre, string direccion, string fechaNacimiento, char sexo)
        : Empleado(nombre, direccion, fechaNacimiento, sexo) {}

    void mostrarInformacion() {
        cout << "Tipo de empleado: Gerente" << endl;
    }
};

#endif
