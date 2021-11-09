#include <iostream>
#include "lib.hpp"

using namespace std;

void showImage(cv::Mat img, std::string nameOfWindow, int timeInMilliSeconds = 0) {
    cv::imshow(nameOfWindow, img);
    cv::waitKey(timeInMilliSeconds);
    cv::destroyWindow(nameOfWindow);
}

int main() {
    int size = 1;
    int blurSize = 7;

    string* inputNames = new string[size];
    inputNames[0] = "data/input/1.jpg";

    cv::Mat* blurredImages = BlurImages::blurImages(normal, inputNames, 1, 5);   

    showImage(blurredImages[0], "Blurred Image", 10000);

    return 0;
}