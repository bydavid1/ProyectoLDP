#include "JefeArea.h"

JefeArea::JefeArea(const string& nombre, const string& direccion, const string& fechaNacimiento, char sexo)
    : Empleado(nombre, direccion, fechaNacimiento, sexo), sueldo(1500) {
}

JefeArea::~JefeArea() {
}

double JefeArea::calcularSalario() const {
    return sueldo - (sueldo * 0.075) - (sueldo * 0.0775) - (sueldo * 0.20);
}
