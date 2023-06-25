#include <iostream>
#include <vector>
#include <algorithm>
#include "include/Empleado.h"
#include "include/Gerente.h"
#include "include/JefeArea.h"
#include "include/Supervisor.h"
#include "include/Tecnico.h"

using namespace std;

void ordenarEmpleadosPorApellido(vector<Empleado *> &empleados);
void ordenarEmpleadosPorSueldo(vector<Empleado *> &empleados);
void mostrarCantidadEmpleadosSegunRoles(const vector<Empleado *> &empleados);
void agregarNuevoEmpleado(vector<Empleado *> &empleados);
void generarEmpleadosPrueba(vector<Empleado *> &empleados);

int main()
{
    vector<Empleado *> empleados;

    generarEmpleadosPrueba(empleados);

    int opcion;
    do
    {
        cout << "Menú:" << endl;
        cout << "1. Ordenar empleados por apellido" << endl;
        cout << "2. Ordenar empleados por sueldo" << endl;
        cout << "3. Mostrar cantidad de empleados según roles" << endl;
        cout << "4. Agregar nuevo empleado" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            ordenarEmpleadosPorApellido(empleados);
            break;
        case 2:
            ordenarEmpleadosPorSueldo(empleados);
            break;
        case 3:
            mostrarCantidadEmpleadosSegunRoles(empleados);
            break;
        case 4:
            agregarNuevoEmpleado(empleados);
            break;
        }

    } while (opcion != 0);

    return 0;
}

void ordenarEmpleadosPorApellido(vector<Empleado *> &empleados)
{
    sort(empleados.begin(), empleados.end(), [](Empleado *emp1, Empleado *emp2)
         { return emp1->getNombre() < emp2->getNombre(); });

    cout << "Empleados ordenados por apellido:" << endl;
    for (Empleado *emp : empleados)
    {
        cout << emp->getNombre() << endl;
    }
}

void ordenarEmpleadosPorSueldo(vector<Empleado *> &empleados)
{
    sort(empleados.begin(), empleados.end(), [](Empleado *emp1, Empleado *emp2)
         { return emp1->calcularSalario() < emp2->calcularSalario(); });

    // Mostrar la lista ordenada de empleados
    cout << "Empleados ordenados por sueldo:" << endl;
    for (Empleado *emp : empleados)
    {
        cout << emp->getNombre() << ": " << emp->calcularSalario() << endl;
    }
}

void mostrarCantidadEmpleadosSegunRoles(const vector<Empleado *> &empleados)
{
    int contadorGerentes = 0;
    int contadorJefesArea = 0;
    int contadorSupervisores = 0;
    int contadorTecnicos = 0;

    for (Empleado *emp : empleados)
    {
        if (dynamic_cast<Gerente *>(emp) != nullptr)
        {
            contadorGerentes++;
        }
        else if (dynamic_cast<JefeArea *>(emp) != nullptr)
        {
            contadorJefesArea++;
        }
        else if (dynamic_cast<Supervisor *>(emp) != nullptr)
        {
            contadorSupervisores++;
        }
        else if (dynamic_cast<Tecnico *>(emp) != nullptr)
        {
            contadorTecnicos++;
        }
    }

    cout << "Cantidad de empleados según roles:" << endl;
    cout << "Gerentes: " << contadorGerentes << endl;
    cout << "Jefes de Área: " << contadorJefesArea << endl;
    cout << "Supervisores: " << contadorSupervisores << endl;
    cout << "Técnicos: " << contadorTecnicos << endl;
}

void agregarNuevoEmpleado(vector<Empleado *> &empleados)
{
    string nombre, direccion, fechaNacimiento;
    char sexo;

    cout << "Agregar nuevo empleado" << endl;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Dirección: ";
    cin >> direccion;
    cout << "Fecha de Nacimiento: ";
    cin >> fechaNacimiento;
    cout << "Sexo: ";
    cin >> sexo;

    string rol;
    cout << "Rol (Gerente/JefeArea/Supervisor/Tecnico): ";
    cin >> rol;

    if (rol == "Gerente")
    {
        Gerente *nuevoGerente = new Gerente(nombre, direccion, fechaNacimiento, sexo);
        empleados.push_back(nuevoGerente);
    }
    else if (rol == "JefeArea")
    {
        JefeArea *nuevoJefeArea = new JefeArea(nombre, direccion, fechaNacimiento, sexo);
        empleados.push_back(nuevoJefeArea);
    }
    else if (rol == "Supervisor")
    {
        Supervisor *nuevoSupervisor = new Supervisor(nombre, direccion, fechaNacimiento, sexo);
        empleados.push_back(nuevoSupervisor);
    }
    else if (rol == "Tecnico")
    {
        Tecnico *nuevoTecnico = new Tecnico(nombre, direccion, fechaNacimiento, sexo);
        empleados.push_back(nuevoTecnico);
    }
    else
    {
        cout << "Rol inválido. No se agrega empleado." << endl;
    }
}

void generarEmpleadosPrueba(vector<Empleado *> &empleados)
{
    // Nombres de empleados
    vector<string> nombres = {
        "John Doe", "Jane Smith", "Michael Johnson", "Emily Davis", "Robert Brown",
        "Olivia Wilson", "James Miller", "Sophia Anderson", "Daniel Taylor", "Mia Martinez",
        "William Thomas", "Isabella Garcia", "Benjamin Hernandez", "Ava Lopez", "David Gonzalez",
        "Emma Lee", "Alexander Clark", "Sofia Rodriguez", "Matthew Lewis", "Abigail Young",
        "Elijah Hall", "Charlotte Moore", "Joseph Adams", "Scarlett Wright", "Andrew King"
    };

    // Crear 5 supervisores
    for (int i = 0; i < 5; i++) {
        string nombre = nombres[i];
        string direccion = "Dirección " + to_string(i + 1);
        string fechaNacimiento = "01/01/1980";
        char sexo = (i % 2 == 0) ? 'M' : 'F';
        Empleado* supervisor = new Supervisor(nombre, direccion, fechaNacimiento, sexo);
        empleados.push_back(supervisor);
    }

    // Crear 2 gerentes
    for (int i = 5; i < 7; i++) {
        string nombre = nombres[i];
        string direccion = "Dirección " + to_string(i + 1);
        string fechaNacimiento = "01/01/1975";
        char sexo = (i % 2 == 0) ? 'M' : 'F';
        Empleado* gerente = new Gerente(nombre, direccion, fechaNacimiento, sexo);
        empleados.push_back(gerente);
    }

    // Crear 3 jefes de área
    for (int i = 7; i < 10; i++) {
        string nombre = nombres[i];
        string direccion = "Dirección " + to_string(i + 1);
        string fechaNacimiento = "01/01/1982";
        char sexo = (i % 2 == 0) ? 'M' : 'F';
        Empleado* jefeArea = new JefeArea(nombre, direccion, fechaNacimiento, sexo);
        empleados.push_back(jefeArea);
    }

    // Crear 15 técnicos
    for (int i = 10; i < 25; i++) {
        string nombre = nombres[i];
        string direccion = "Dirección " + to_string(i + 1);
        string fechaNacimiento = "01/01/1990";
        char sexo = (i % 2 == 0) ? 'M' : 'F';
        Empleado* tecnico = new Tecnico(nombre, direccion, fechaNacimiento, sexo);
        empleados.push_back(tecnico);
    }
}