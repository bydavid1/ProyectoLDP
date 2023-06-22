#include "Supervisor.h"

Supervisor::Supervisor(const string& nombre, const string& direccion, const string& fechaNacimiento, char sexo)
    : Empleado(nombre, direccion, fechaNacimiento, sexo), sueldo(750) {
}

Supervisor::~Supervisor() {
}

double Supervisor::calcularSalario() const {
    return sueldo - (sueldo * 0.075); // Descuento del 7.5% (ISSS)
}
