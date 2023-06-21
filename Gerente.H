#ifndef GERENTE_H
#define GERENTE_H

#include "Empleado.h"

class Gerente : public Empleado {
public:
    Gerente(string nombre, string Apellido, string direccion, string fechaNacimiento, char sexo, int Sueldo)
        : Empleado(nombre, Apellido, direccion, fechaNacimiento, sexo, Sueldo) {}

    void mostrarInformacion() {
        cout << "Tipo de empleado: Gerente" << endl;
    }
};

#endif
