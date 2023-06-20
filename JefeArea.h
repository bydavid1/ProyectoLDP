#ifndef JEFEAREA_H
#define JEFEAREA_H

#include "Empleado.h"

class JefeArea : public Empleado {
public:
    JefeArea(string nombre, string direccion, string fechaNacimiento, char sexo)
        : Empleado(nombre, direccion, fechaNacimiento, sexo) {}

    void mostrarInformacion() {
        cout << "Tipo de empleado: Jefe de área" << endl;
    }
};

#endif
