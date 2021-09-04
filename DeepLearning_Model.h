#ifndef DEEPLEARNING_MODEL_H
#define DEEPLEARNING_MODEL_H

#include <opencv2/dnn/dnn.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

class DeepLearning_Model
{


public:
    DeepLearning_Model();

    void detectFaceCaffe(Mat &image, int &faceNum, vector<Rect> &facelist);
    void inline setScaleFactor(float scale) {scaleFactor = scale;}
    void inline setCfdThreshold(float thresh) {caffeCfdThreshold = thresh;}

private:
    dnn::Net net;
    Mat grayImg;
    float caffeCfdThreshold;
    float scaleFactor;
};


#endif // DEEPLEARNING_MODEL_H
