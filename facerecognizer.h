#ifndef FACERECOGNIZER_H
#define FACERECOGNIZER_H


#include <opencv2/dnn/dnn.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/face.hpp>

using namespace cv;
using namespace std;
using namespace cv::face;
class facerecognizer
{
public:
    facerecognizer();
    void train(vector<Mat> &imglist, vector<int> &labels);
    void save();
    void recognize(Mat &img, int &label, double &confidence);
private:
    Ptr<FaceRecognizer> model;
};

#endif // FACERECOGNIZER_H
