#include "Camara.h"
#include <iostream>

using namespace cv;

void ejecutarCamara() {
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cout << "Error al abrir la camara" << std::endl;
        return;
    }

    Mat frame, gray_frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        cvtColor(frame, gray_frame, COLOR_BGR2GRAY);

        imshow("Camara Color", frame);
        imshow("Camara Gris", gray_frame);

        if (waitKey(30) == 27) break; // ESC para salir
    }
    destroyAllWindows();
}
