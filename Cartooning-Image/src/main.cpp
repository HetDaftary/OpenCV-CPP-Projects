#include <iostream>
#include "lib.hpp"
#include <cstdlib>
#include <cstring>

using namespace std;
using namespace cv;

void showImage(cv::Mat img, std::string nameOfWindow, int timeInMilliSeconds = 0) {
    cv::imshow(nameOfWindow, img);
    cv::waitKey(timeInMilliSeconds);
    cv::destroyWindow(nameOfWindow);
}

int main() {
    cv::Mat img = cv::imread("data/input/2.jpg", -1);

    //showImage(img, "Original Image", 1000);

    Cartoonizer cartoonizer;

    cv::Mat cartoon = cartoonizer.render(img);

    showImage(cartoon, "Cartoon Image", 1000);

    char* path = new char[1024];

    strcpy(path, "data/output/Cartooning-Image");

    // If path does not exist, we create it.
    char* pathChecker = new char[1024];
    sprintf(pathChecker, "if [ ! -f %s ]; then mkdir -p %s; fi", path, path);

    system(pathChecker);

    strcat(path, "/Chris_Partt_Cartoon.jpg");

    cv::imwrite(path, cartoon);

    return 0;
}