#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "Empleado.h"

class Supervisor : public Empleado {
private:
    double sueldo;

public:
    Supervisor(const string& nombre, const string& direccion, const string& fechaNacimiento, char sexo);
    virtual ~Supervisor();

    double calcularSalario() const;
};

#endif
