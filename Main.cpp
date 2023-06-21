#include <iostream>
#include <vector>
#include <algorithm>
#include "Empleado.h"
#include "Gerente.h"
#include "JefeArea.h"
#include "Supervisor.h"
#include "Tecnico.h"

using namespace std;

int main() {
    vector<Empleado*> empleados;
   int contadorGerentes = 0;
   int contadorJefesArea = 0;
   int contadorSupervisores = 0;
   int contadorTecnicos = 0;

    int opcion;
    do {
        cout << "Menú:" << endl;
        cout << "1. Ordenar empleados por apellido" << endl;
        cout << "2. Ordenar empleados por sueldo" << endl;
        cout << "3. Mostrar cantidad de empleados según roles" << endl;
        cout << "4. Agregar nuevo empleado" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Ordenar empleados por apellido
                sort(empleados.begin(), empleados.end(), [](Empleado* emp1, Empleado* emp2) {
                    return emp1->getApellido() < emp2->getApellido();
                });
                break;
            case 2:
                // Ordenar empleados por sueldo
                sort(empleados.begin(), empleados.end(), [](Empleado* emp1, Empleado* emp2) {
                    return emp1->getSueldo() < emp2->getSueldo();
                });
                break;
            case 3:
                
                for (Empleado* emp : empleados) {
                    if (dynamic_cast<Gerente*>(emp) != nullptr) {
                        contadorGerentes++;
                    } else if (dynamic_cast<JefeArea*>(emp) != nullptr) {
                        contadorJefesArea++;
                    } else if (dynamic_cast<Supervisor*>(emp) != nullptr) {
                        contadorSupervisores++;
                    } else if (dynamic_cast<Tecnico*>(emp) != nullptr) {
                        contadorTecnicos++;
                    }
                }

                cout << "Cantidad de empleados según roles:" << endl;
                cout << "Gerentes: " << contadorGerentes << endl;
                cout << "Jefes de Área: " << contadorJefesArea << endl;
                cout << "Supervisores: " << contadorSupervisores << endl;
                cout << "Técnicos: " << contadorTecnicos << endl;
                break;
            case 4:
            {
                string nombre, Apellido, direccion, fechaNacimiento;
                char sexo;
                int Sueldo;

                cout << "Agregar nuevo empleado" << endl;
                cout << "Nombre: ";
                cin >> nombre;
                cout << "Apellido: ";
                cin >> Apellido;
                cout << "Dirección: ";
                cin >> direccion;
                cout << "Fecha de Nacimiento: ";
                cin >> fechaNacimiento;
                cout << "Sexo: ";
                cin >> sexo;
                cout << "Sueldo: ";
                cin >> Sueldo;

                // Agregar nuevo empleado al vector empleados
                // Puedes implementar la lógica para crear la instancia del empleado correspondiente según su rol y agregarlo al vector

                break;
            }
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
        }

                
    } while (opcion != 0);

    // Liberar memoria de los empleados
    for (Empleado* emp : empleados) {
        delete emp;
    }

    return 0;
}