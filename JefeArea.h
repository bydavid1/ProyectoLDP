#ifndef JEFEAREA_H
#define JEFEAREA_H

#include "Empleado.h"

class JefeArea : public Empleado {
public:
    JefeArea(string nombre, string Apellido, string direccion, string fechaNacimiento, char sexo, int Sueldo)
        : Empleado(nombre, Apellido, direccion, fechaNacimiento, sexo, Sueldo) {}

    void mostrarInformacion() {
        cout << "Tipo de empleado: Jefe de área" << endl;
    }
};

#endif