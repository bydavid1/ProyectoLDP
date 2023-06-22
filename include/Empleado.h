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
    Empleado(const string& nombre, const string& direccion, const string& fechaNacimiento, char sexo);
    virtual ~Empleado();

    string getNombre() const;
    
    string getDireccion() const;
    
    string getFechaNacimiento() const;

    char getSexo() const;

    virtual double calcularSalario() const = 0; 
};

#endif
