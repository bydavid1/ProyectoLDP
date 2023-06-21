#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "Empleado.h"

class Supervisor : public Empleado {
public:
    Supervisor(string nombre,string Apellido, string direccion, string fechaNacimiento, char sexo, int Sueldo)
        : Empleado(nombre,Apellido, direccion, fechaNacimiento, sexo, Sueldo) {}

    void mostrarInformacion() {
        cout << "Tipo de empleado: Supervisor" << endl;
    }
};

#endif
