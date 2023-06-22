#include "Tecnico.h"

Tecnico::Tecnico(const string& nombre, const string& direccion, const string& fechaNacimiento, char sexo)
    : Empleado(nombre, direccion, fechaNacimiento, sexo), sueldo(350) {
}

Tecnico::~Tecnico() {
}

double Tecnico::calcularSalario() const {
    return sueldo - (sueldo * 0.075); // Descuento del 7.5% (ISSS)
}
