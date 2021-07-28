#include "cascadefacedetector.h"

CascadeFaceDetector::CascadeFaceDetector(QObject *parent) : QObject(parent)
{
    Detector = CascadeClassifier("Model_files\\haarcascade_frontalface_default.xml");
}

void CascadeFaceDetector::deTectFace(Mat inputImg, vector<Rect> &outPut){
    if(inputImg.cols!=0 && inputImg.rows!=0){
        Mat img_gray;
        cvtColor(inputImg, img_gray, COLOR_BGR2GRAY);
        Detector.detectMultiScale(img_gray, outPut, ScaleFactor, minNeigbor);
    }

}
