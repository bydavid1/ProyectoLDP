#ifndef GERENTE_H
#define GERENTE_H

#include "Empleado.h"

class Gerente : public Empleado {
private:
    double sueldo;

public:
    Gerente(const string& nombre, const string& direccion, const string& fechaNacimiento, char sexo);
    virtual ~Gerente();

    double calcularSalario() const;
};

#endif

