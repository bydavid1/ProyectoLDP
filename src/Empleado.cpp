#include "Empleado.h"

Empleado::Empleado(const string& nombre, const string& direccion, const string& fechaNacimiento, char sexo)
    : nombre(nombre), direccion(direccion), fechaNacimiento(fechaNacimiento), sexo(sexo) {
}

Empleado::~Empleado() {
}

string Empleado::getNombre() const {
    return nombre;
}

string Empleado::getDireccion() const {
    return direccion;
}

string Empleado::getFechaNacimiento() const {
    return fechaNacimiento;
}

char Empleado::getSexo() const {
    return sexo;
}
