#ifndef TECNICO_H
#define TECNICO_H

#include "Empleado.h"

class Tecnico : public Empleado {
public:
    Tecnico(string nombre, string Apellido, string direccion, string fechaNacimiento, char sexo, int Sueldo)
        : Empleado(nombre,Apellido, direccion, fechaNacimiento, sexo, Sueldo) {}

    void mostrarInformacion() {
        cout << "Tipo de empleado: Técnico" << endl;
    }
};

#endif
