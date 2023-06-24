#include <iostream>
#include <vector>
#include <algorithm>
#include "Empleado.h"
#include "Gerente.h"
#include "JefeArea.h"
#include "Supervisor.h"
#include "Tecnico.h"

using namespace std;

int main()
{
    vector<Empleado *> empleados;
    int contadorGerentes = 0;
    int contadorJefesArea = 0;
    int contadorSupervisores = 0;
    int contadorTecnicos = 0;


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
            // Ordenar empleados por apellido
            sort(empleados.begin(), empleados.end(), [](Empleado *emp1, Empleado *emp2)
                 { return emp1->getNombre() < emp2->getNombre(); });
            break;
        case 2:
            // Ordenar empleados por sueldo
            sort(empleados.begin(), empleados.end(), [](const Empleado &emp1, const Empleado &emp2)
                 { return emp1.calcularSalario() < emp2.calcularSalario(); });
            break;
        case 3:

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
            break;
        case 4:
        
            string nombre, direccion, fechaNacimiento;
            char sexo;
            int Sueldo;

            cout << "Agregar nuevo empleado" << endl;
            cout << "Nombre: ";
            cin >> nombre;
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
             // Solicitar información adicional según el rol del empleado

         string rol;
         cout << "Rol (Gerente/JefeArea/Supervisor/Tecnico): ";
         cin >> rol;

         if (rol == "Gerente.h") {
            string sucursal;
            cout << "sucursal: ";
            cin >> sucursal;

            // Crear instancia de Gerente y agregarlo al vector
          Gerente* nuevoGerente = new Gerente(nombre, direccion, fechaNacimiento, sexo);
             empleados.push_back(nuevoGerente);

           } else if (rol == "JefeArea") {
            string Area;
            cout << "Nombre Area: ";
            cin >> Area;

            // Crear instancia de JefeArea y agregarlo al vector
           JefeArea* nuevoJefeArea = new JefeArea(nombre, direccion, fechaNacimiento, sexo);
          empleados.push_back(nuevoJefeArea);

         }else if (rol == "Supervisor") {
            string departamento;
            cout << "Departamento: ";
            cin >> departamento;

         // Crear instancia de Supervisor y agregarlo al vector
                
            Supervisor *nuevoSupervisor = new Supervisor(nombre, direccion, fechaNacimiento, sexo);
           empleados.push_back(nuevoSupervisor);

            }else if (rol == "Tecnico") {
            
           
            string campo;
            cout << "Nombre del campo: ";
            cin >> campo;

                // Crear instancia de Tecnico y agregarlo al vector
                Tecnico* nuevoTecnico = new Tecnico(nombre, direccion, fechaNacimiento, sexo);
                 empleados.push_back(nuevoTecnico);

            } else {
          
            
                cout << "Rol no válido. No se agregó ningún empleado." << endl;
            }
            break;
        }

    } while (opcion != 0);

    // Liberar memoria de los empleados
    for (Empleado *emp : empleados)
    {
        delete emp;
    }

    return 0;
} 