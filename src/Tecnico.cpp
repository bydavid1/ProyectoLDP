#include "Tecnico.h"

Tecnico::Tecnico(const string& nombre, const string& direccion, const string& fechaNacimiento, char sexo)
    : Empleado(nombre, direccion, fechaNacimiento, sexo), sueldo(350) {
}

Tecnico::~Tecnico() {
}

double Tecnico::calcularSalario() const {
    // El tecnico no recibe descuento de renta
    return sueldo - (sueldo * 0.075) - (sueldo * 0.0775);
}
