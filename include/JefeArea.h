#ifndef JEFEAREA_H
#define JEFEAREA_H

#include "Empleado.h"

class JefeArea : public Empleado {
private:
    double sueldo;

public:
    JefeArea(const string& nombre, const string& direccion, const string& fechaNacimiento, char sexo);
    virtual ~JefeArea();

    double calcularSalario() const;
};

#endif
