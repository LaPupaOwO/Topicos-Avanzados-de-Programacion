#include "Notas_Imagen_Basica.h"

using namespace cv;

void ejecutarRedimensionadoBasico(Mat img) {
    Mat img_resized;
    // Tu lógica original: Redimensionar a 636x316
    resize(img, img_resized, Size(636, 316));

    imshow("Imagen Original", img);
    imshow("Imagen de prueba", img_resized);

    cv::waitKey(0);
    cv::destroyAllWindows();
}