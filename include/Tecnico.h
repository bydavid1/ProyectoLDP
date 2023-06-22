#ifndef TECNICO_H
#define TECNICO_H

#include "Empleado.h"

class Tecnico : public Empleado {
private:
    double sueldo;

public:
    Tecnico(const string& nombre, const string& direccion, const string& fechaNacimiento, char sexo);
    virtual ~Tecnico();

    double calcularSalario() const;
};

#endif
