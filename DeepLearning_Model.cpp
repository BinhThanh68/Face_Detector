#include "DeepLearning_Model.h"

DeepLearning_Model::DeepLearning_Model()
{
    net = dnn::readNetFromCaffe("Model_files\\caffemodeldeploy.prototxt.txt",
                                "Model_files\\res10_300x300_ssd_iter_140000_fp16.caffemodel");
}

void DeepLearning_Model::detectFaceCaffe(Mat &image, int &faceNum){
    //cvtColor(image, grayImg, COLOR_BGR2GRAY);
    Mat inputBlob = dnn::blobFromImage(image, 1, Size(300, 300), Scalar(104.0, 177.0, 123.0), false, false);
    net.setInput(inputBlob, "data");
    Mat detection = net.forward("detection_out");
    Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());

    faceNum = 0;
    for(int i = 0; i < detectionMat.rows; i++){
            float confidence = detectionMat.at<float>(i, 2);

            if(confidence > caffeCfdThreshold)
            {
                faceNum++;
                int x1 = static_cast<int>(detectionMat.at<float>(i, 3) * image.cols);
                int y1 = static_cast<int>(detectionMat.at<float>(i, 4) * image.rows);
                int x2 = static_cast<int>(detectionMat.at<float>(i, 5) * image.cols);
                int y2 = static_cast<int>(detectionMat.at<float>(i, 6) * image.rows);

                rectangle(image, Point(x1, y1), Point(x2, y2), Scalar(0, 255, 0),2, 4);
            }
        }
}
