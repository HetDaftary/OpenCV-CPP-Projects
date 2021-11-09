#include <iostream>
#include "lib.hpp"

using namespace std;
using namespace cv;

void showImage(cv::Mat img, std::string nameOfWindow, int timeInMilliSeconds = 0) {
    cv::imshow(nameOfWindow, img);
    cv::waitKey(timeInMilliSeconds);
    cv::destroyWindow(nameOfWindow);
}

int main() {
    int size = 2;
    int blurSize = 9;

    string* inputNames = new string[size];
    inputNames[0] = "data/input/1.jpg";
    inputNames[1] = "data/input/2.jpg";

    Mat* blurredImages = BlurImages::blurImages(normal, inputNames, size, blurSize);   

    for (int i = 0; i < size; i++) {
        if (blurredImages[i].data) {
            showImage(blurredImages[i], inputNames[i], 1000);           
        }
    }

    return 0;
}