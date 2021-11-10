#include <opencv2/opencv.hpp>
#include <iostream>

class Cartoonizer {
public: 
    cv::Mat render(std::string imageName) {
        return this -> render(cv::imread(imageName));
    }

    cv::Mat render(cv::Mat img) {
        int i, numDownSamples = 2, numBilateralFilters = 50;

        cv::Mat img_color = img.clone(), img_blur, img_gray;

        for (int i = 0; i < numDownSamples; i++) {
            cv::pyrDown(img_color, img_color);
        }

        for (int i = 0; i < numBilateralFilters; i++) {
            cv::Mat imgFilt;
            cv::bilateralFilter(img_color, imgFilt, -1, 20.0, 20.0);
            img = imgFilt.clone();
        }

        for (int i = 0; i < numDownSamples; i++) {
            cv::pyrUp(img_color, img_color);
        }

        cv::cvtColor(img_color, img_gray, cv::COLOR_BGR2GRAY);
        cv::medianBlur(img_gray, img_blur, 3);

        cv::Mat edges;
        cv::adaptiveThreshold(img_blur, edges, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 9, 2);
        cv::cvtColor(edges, edges, cv::COLOR_GRAY2BGR);

        cv::bitwise_and(img_color, edges, img_color);

        return img_color;

    }
};