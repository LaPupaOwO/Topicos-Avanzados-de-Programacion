#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat img_resized;

    // USA BARRAS NORMALES (/) para evitar errores de secuencia de escape
    // Asegúrate de que la carpeta OPEN_CV esté al mismo nivel que tu ejecutable
    Mat img = imread("../OPEN_CV/img/Roblox.png");

    // VALIDACIÓN: Si no encuentra la imagen, se detiene aquí sin "tronar"
    if (img.empty()) {
        cout << "ERROR: No se encontro el archivo Roblox.png" << endl;
        cout << "Revisa que la imagen este en la carpeta correcta." << endl;
        system("pause");
        return -1;
    }

    // Solo llegamos aquí si la imagen cargó bien
    resize(img, img_resized, Size(636, 316));

    imshow("Imagen Original", img);
    imshow("Imagen de prueba", img_resized);
    waitKey(0);

    return 0;
}

/***********************************************************************/
//  27-Enero-2026 Creación de Repositorio en Github 
//  27-Enero-2026 El pepe, etesech
/***********************************************************************/