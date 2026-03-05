#include "Fichero.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ejecutarFichero() {
    // Proceso original: Escritura y lectura básica
	ofstream archivo("datos.txt"); // ofstream se utiliza para crear y escribir en un archivo de texto.
	archivo << "Hola mundo\n"; // Escribe una línea de texto en el archivo.
	archivo << "12345\n"; // Escribe un número en el archivo.
	archivo.close(); // Cierra el archivo después de escribir para asegurar que los datos se guarden correctamente.

	ifstream leer("datos.txt"); // ifstream se utiliza para abrir y leer un archivo de texto.
    string linea; 
    cout << "\n--- Ejecutando Fichero (Original) ---" << endl;
    while (getline(leer, linea)) {
        cout << "Leido: " << linea << endl;
    }
    leer.close();
	// Aquí se abre el archivo para lectura, se lee línea por línea y se muestra en la consola.
}