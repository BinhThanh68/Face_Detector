#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QFileDialog>
#include "imageinput.h"
#include "cascadefacedetector.h"
#include "Struct_and_Enum.h"
#include "DeepLearning_Model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void on_DisplayTimer();



private slots:
    void on_BTN_CamOpen_clicked();



    void on_SB_CascadeFactor_valueChanged(int value);

    void on_SB_CascadeMinNeigbour_valueChanged(int value);

    void on_BTN_ImageOpen_clicked();

    void on_CB_CascadeDetectorEnable_stateChanged(int arg1);

    void on_BTN_VideoOpen_clicked();

    void on_CB_CFDetectorEnable_stateChanged(int arg1);


    void on_SB_CaffeScaleFactor_valueChanged(int value);

    void on_SB_CaffeScoreThresh_valueChanged(int value);

    void on_BTNPause_clicked();

private:
    Ui::MainWindow *ui;
    ImageInput ImgInput;
    CascadeFaceDetector cascadeDetector;
    DeepLearning_Model DL;
    QTimer timer;
    Mat frame, displayFrame;
    int timer_value;
    QPixmap MainViewBG;
    QPixmap pixCamOff, pixCamOn, pixImgOff, pixImgOn, pixVideoOff, pixVideoOn, pixpauseDflt,
    pixPauseStart, pixPauseStop;


};
#endif // MAINWINDOW_H
