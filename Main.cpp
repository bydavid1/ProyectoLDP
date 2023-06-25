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
    // Crear empleados de prueba
    Empleado *empleado1 = new Gerente("John Doe", "123 Main St", "01/01/1990", 'M');
    Empleado *empleado2 = new JefeArea("Jane Smith", "456 Elm St", "02/02/1991", 'F');
    Empleado *empleado3 = new Supervisor("Mike Johnson", "789 Oak St", "03/03/1992", 'M');
    Empleado *empleado4 = new Tecnico("Emily Davis", "987 Pine St", "04/04/1993", 'F');
    Empleado *empleado5 = new Gerente("Robert Brown", "321 Maple St", "05/05/1994", 'M');

    // Agregar empleados al vector
    empleados.push_back(empleado1);
    empleados.push_back(empleado2);
    empleados.push_back(empleado3);
    empleados.push_back(empleado4);
    empleados.push_back(empleado5);
}
