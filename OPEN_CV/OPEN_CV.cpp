/***********************************************************************/
//  21-Enero-2026 Alain Reyes   SetUp de OpenCV en Visual Studio 2026
//  27-Enero-2026 Alain Reyes   Creación de Repositorio en Github 
//  29-Enero-2026 Alain Reyes   Modularización y Ejercicios de Clase
/***********************************************************************/

#include <opencv2/opencv.hpp>
#include <iostream>

// Incluimos todos los encabezados
#include "Notas_Imagen_Basica.h"
#include "Procesamiento.h"
#include "Camara.h"

using namespace cv;
using namespace std;

int main() {
    // 1. Cargar imagen con tu validacion original
    Mat img = imread("../OPEN_CV/img/Roblox.png");

    if (img.empty()) {
        cout << "ERROR: No se encontro el archivo Roblox.png" << endl;
        system("pause");
        return -1;
    }

    // --- EJECUCIÓN POR PASOS ---

    cout << "Ejecutando: Codigo Original (Redimension 636x316)..." << endl;
    ejecutarRedimensionadoBasico(img);

    cout << "Ejecutando: Ejercicio 1 (Dimensiones)..." << endl;
    mostrarDimensiones(img);

    cout << "Ejecutando: Ejercicio 2 y 3 (Redimension 1024 y Dibujos)..." << endl;
    redimensionarYDibujar(img);

    cout << "Ejecutando: Ejercicio 4 (Video en Tiempo Real)..." << endl;
    ejecutarCamara();

    cout << "Proceso finalizado correctamente." << endl;
    return 0;
}