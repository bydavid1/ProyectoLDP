#include "Gerente.h"

Gerente::Gerente(const string& nombre, const string& direccion, const string& fechaNacimiento, char sexo)
    : Empleado(nombre, direccion, fechaNacimiento, sexo), sueldo(5000) {
}

Gerente::~Gerente() {
}

double Gerente::calcularSalario() const {
    return sueldo - (sueldo * 0.075); // Descuento del 7.5% (ISSS)
}
