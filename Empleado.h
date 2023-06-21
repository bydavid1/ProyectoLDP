#include <iostream>
#include <string>


#ifndef EMPLEADO_H
#define EMPLEADO_H

using namespace std;

class Empleado {

    public:
    virtual ~Empleado() {}

private:
    string nombre;
    string Apellido;
    string direccion;
    string fechaNacimiento;
    char sexo;
    int Sueldo;

public:
    Empleado(string nombre,string Apellido, string direccion, string fechaNacimiento, char sexo, int Sueldo) {
        this->nombre = nombre;
        this->Apellido= Apellido;
        this->direccion = direccion;
        this->fechaNacimiento = fechaNacimiento;
        this->sexo = sexo;
        this->Sueldo = Sueldo;
    }

    string getNombre() {
        return nombre;
    }



    string getApellido() {
        return Apellido;
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

    int getSueldo() {
        return Sueldo;
    }
};

#endif