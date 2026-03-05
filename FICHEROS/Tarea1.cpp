#include "Tarea1.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ejecutarTarea1() {
    string nombre, apPaterno, apMaterno, fecha, curp, domicilio;

    cout << "\n--- Ejecutando Tarea 1 (Registro) ---" << endl;

    // El 'ws' limpia el buffer por si venimos de un cin en el main
    cout << "Nombre(s): "; getline(cin >> ws, nombre); 
    cout << "Apellido Paterno: "; getline(cin, apPaterno);
    cout << "Apellido Materno: "; getline(cin, apMaterno);
    cout << "Fecha de nacimiento: "; getline(cin, fecha);
    cout << "CURP: "; getline(cin, curp);
    cout << "Domicilio: "; getline(cin, domicilio);
	// En esta parte se toman los datos del usuario y se almacenan en variables. 
    // El uso de 'getline' permite capturar espacios en los nombres y domicilios. 

    // Guardado en el archivo solicitado
	ofstream archivo("registro_tarea1.txt"); //ofstream se utiliza para crear y escribir en un archivo de texto.
    if (archivo.is_open()) {
        archivo << "Nombre(s): " << nombre << "\n"
            << "Apellido Paterno: " << apPaterno << "\n"
            << "Apellido Materno: " << apMaterno << "\n"
            << "Fecha de Nacimiento: " << fecha << "\n"
            << "CURP: " << curp << "\n"
            << "Domicilio: " << domicilio << "\n";
        archivo.close();
        cout << "\n[Datos guardados correctamente en 'registro_tarea1.txt']" << endl;
		// Aquí se crea un archivo de texto y se escriben los datos del usuario en un formato legible.
    }
}