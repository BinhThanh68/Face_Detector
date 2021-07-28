#ifndef CASCADEFACEDETECTOR_H
#define CASCADEFACEDETECTOR_H

#include <QObject>
#include <opencv2/objdetect.hpp>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/videoio/videoio.hpp>

using namespace cv;
using namespace std;

class CascadeFaceDetector : public QObject
{
public:
    explicit CascadeFaceDetector(QObject *parent = nullptr);

    void deTectFace(Mat inputImg, vector<Rect> &outPut);
    inline void SetScaleFactor(double scalefactor) {ScaleFactor = scalefactor;}
    inline void SetminNeigbor(int min_neigbor) {minNeigbor = min_neigbor;}
private:
    CascadeClassifier Detector;
    double ScaleFactor;
    int minNeigbor;
signals:

};

#endif // CASCADEFACEDETECTOR_H
