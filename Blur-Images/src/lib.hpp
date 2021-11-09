#include <vector>
#include <opencv2/opencv.hpp>

enum BlurType {
    normal, median, gaussian
};

// Class is used for function over-loading.
class BlurImages {
private:
    static void blurImage(BlurType type, std::string name, int blurSize, cv::Mat& returnImage) {
        cv::Mat img = cv::imread(name);
        blurImage(type, img, blurSize, returnImage);
    }

    static void blurImage(BlurType type, cv::Mat img, int blurSize, cv::Mat& returnImage) {
        if (type == normal) {
            return cv::blur(img, returnImage, cv::Size(blurSize, blurSize));
        } else if (type == median) {
            return cv::medianBlur(img, returnImage, blurSize);
        } else if (type == gaussian) {
            return cv::GaussianBlur(img, returnImage, cv::Size(blurSize, blurSize), 0, 0, 4);
        }
    }

public:
    static cv::Mat* blurImages(BlurType type, std::string* names, size_t numberOfImages, int blurSize) {
        cv::Mat* toReturn = new cv::Mat[numberOfImages];
        for (int i = 0; i < numberOfImages; i++) {
            blurImage(type, names[i], blurSize, toReturn[i]);
        }

        return toReturn;
    }

    static cv::Mat* blurImages(BlurType type, std::vector<std::string> names, int blurSize) {
        size_t numberOfImages = names.size();
        cv::Mat* toReturn = new cv::Mat[numberOfImages];

        for (int i = 0; i < numberOfImages; i++) {
            blurImage(type, names[i], blurSize, toReturn[i]);
        }

        return toReturn;
    }

    static cv::Mat* blurImages(BlurType type, cv::Mat* images, size_t numberOfImages, int blurSize) {
        cv::Mat* toReturn = new cv::Mat[numberOfImages];

        for (int i = 0; i < numberOfImages; i++) {
            blurImage(type, images[i], blurSize, toReturn[i]);
        }

        return toReturn;
    }

    static cv::Mat* blurImages(BlurType type, std::vector<cv::Mat> images, int blurSize) {
        size_t numberOfImages = images.size();
        cv::Mat* toReturn = new cv::Mat[numberOfImages];

        for (int i = 0; i < numberOfImages; i++) {
            blurImage(type, images[i], blurSize, toReturn[i]);
        }

        return toReturn;
    }
};