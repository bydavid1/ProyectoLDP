#include <iostream>
#include <string>


#ifndef EMPLEADO_H
#define EMPLEADO_H

using namespace std;

class Empleado {
private:
    string nombre;
    string direccion;
    string fechaNacimiento;
    char sexo;

public:
    Empleado(string nombre, string direccion, string fechaNacimiento, char sexo) {
        this->nombre = nombre;
        this->direccion = direccion;
        this->fechaNacimiento = fechaNacimiento;
        this->sexo = sexo;
    }

    string getNombre() {
        return nombre;
    }

    string getDireccion() {
        return direccion;
    }

    string getFechaNacimiento() {
        return fechaNacimiento;
    }

    char getSexo() {
        return sexo;
    }
};

#endif