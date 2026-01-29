#include "Procesamiento.h"
#include <iostream>

using namespace cv;
using namespace std;

void mostrarDimensiones(Mat imagen) {
    cout << "--- DATOS DE LA IMAGEN ---" << endl;
    cout << "Ancho: " << imagen.cols << endl;
    cout << "Alto : " << imagen.rows << endl;
    cout << "Canales: " << imagen.channels() << endl;
    cout << "--------------------------" << endl;
}

void redimensionarYDibujar(Mat imagen) {
    Mat img_1024;
    resize(imagen, img_1024, Size(1024, 1024));

    // Dibujo solicitado por el profe
    rectangle(img_1024, Point(0, 0), Point(1023, 1023), Scalar(0, 0, 255), 10);
    circle(img_1024, Point(512, 512), 150, Scalar(0, 255, 0), -1);
    putText(img_1024, "OpenCV Tarea", Point(150, 900), FONT_HERSHEY_SIMPLEX, 1.5, Scalar(255, 255, 255), 3);

    imshow("Original", imagen);
    imshow("Redimensionada 1024x1024 con Figuras", img_1024);
    waitKey(0);
    destroyAllWindows();
}