#include "facerecognizer.h"

facerecognizer::facerecognizer()
{
    model = EigenFaceRecognizer::create(200);
    model->read("Model_files/recognizer.xml");

}

void facerecognizer::train(vector<Mat> &imglist, vector<int> &labels){
    model->train(imglist, labels);
}

void facerecognizer::save(){
    model->write("Model_files/recognizer.xml");
}

void facerecognizer::recognize(Mat &img, int &label, double &confidence){
    model->predict(img, label, confidence);
}
