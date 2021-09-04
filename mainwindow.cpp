#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);   
    connect(&timer, SIGNAL(timeout()), this, SLOT(on_DisplayTimer()));

    ui->LB_CascadeScaleFactorVal->setText(QString::number(double(ui->SB_CascadeFactor->value() / 10.0)));
    ui->LB_CascadeMinNeibourVal->setText(QString::number(ui->SB_CascadeMinNeigbour->value()));

    cascadeDetector.SetScaleFactor(double(ui->SB_CascadeFactor->value() / 10.0));
    cascadeDetector.SetminNeigbor(ui->SB_CascadeMinNeigbour->value());

    DL.setScaleFactor(float(ui->SB_CaffeScaleFactor->value()/10.0));
    DL.setCfdThreshold(float(ui->SB_CaffeScoreThresh->value()/10.0));
    ui->LB_CaffeScaleFactorVal->setText(QString::number(float(ui->SB_CaffeScaleFactor->value()/10.0)));
    ui->LB_CaffeScoreThreshVal->setText(QString::number(float(ui->SB_CaffeScoreThresh->value()/10.0)));

    MainViewBG = QPixmap(":/Images/Default_background.PNG");
    ui->LB_MainView->setPixmap(MainViewBG.scaled(ui->LB_MainView->width(), ui->LB_MainView->height(), Qt::IgnoreAspectRatio));

    ui->FacesNum->setText(QString::number(0));



    pixCamOff =    QPixmap(":/Images/camera_off.png");
    pixCamOn =     QPixmap(":/Images/camera_on.png");
    pixImgOff =    QPixmap(":/Images/image_off.png");
    pixImgOn =     QPixmap(":/Images/image_on.png");
    pixVideoOff =  QPixmap(":/Images/video_off.png");
    pixVideoOn =   QPixmap(":/Images/video_on.png");
    pixpauseDflt = QPixmap(":/Images/Pause_disabled.png");
    pixPauseStart = QPixmap(":/Images/Resume.png");
    pixPauseStop = QPixmap(":/Images/Pause.png");


    QIcon BTIconCamOff(pixCamOff);
    ui->BTN_CamOpen->setIcon(BTIconCamOff);
    ui->BTN_CamOpen->setIconSize(pixCamOff.rect().size());


    QIcon BTIconImgOff(pixImgOff);
    ui->BTN_ImageOpen->setIcon(BTIconImgOff);
    ui->BTN_ImageOpen->setIconSize(pixImgOff.rect().size());


    QIcon BTIconVideoOff(pixVideoOff);
    ui->BTN_VideoOpen->setIcon(BTIconVideoOff);
    ui->BTN_VideoOpen->setIconSize(pixVideoOff.rect().size());

    QIcon BTIPauseDflt(pixpauseDflt);
    ui->BTNPause->setIcon(BTIPauseDflt);
    ui->BTNPause->setIconSize(ui->BTNPause->rect().size());

    ui->PTE_AppLog->appendPlainText("Application Started!");


    timer_value = 10;
    timer.start(timer_value);

}


void MainWindow::on_DisplayTimer(){

    ImgInput.GetNextFrame(frame);

    if(!frame.empty()){
        if(ui->CB_CascadeDetectorEnable->isChecked()){
            vector<Rect> faceBoxes;
            cascadeDetector.deTectFace(frame, faceBoxes);

            //face present
            if(faceBoxes.size() > 0){
                ui->FacesNum->setText(QString::number(int(faceBoxes.size())));
                cvtColor(frame, displayFrame, COLOR_BGR2RGB);
                for(int i=0; i<faceBoxes.size(); i++){
                    rectangle(displayFrame, faceBoxes[i], Scalar(0,255,0), 3);
                }
            }
            else {
                ui->FacesNum->setText("0");
                //Show original frame if detetor disabled
                cvtColor(frame, displayFrame, COLOR_BGR2RGB);
            }
        }else if(ui->CB_CFDetectorEnable->isChecked()){

            //detect face by caffe model
            Mat imgtodetect; int facenum;
            frame.copyTo(imgtodetect);
            DL.detectFaceCaffe(imgtodetect, facenum, dtectedFaceList);
            cvtColor(imgtodetect, displayFrame, COLOR_BGR2RGB);
            ui->FacesNum->setText(QString::number(facenum));


        }
        else{
            //Show original frame if detetor disabled
            cvtColor(frame, displayFrame, COLOR_BGR2RGB);
        }

        QImage qimg = QImage((uchar*)displayFrame.data, displayFrame.cols, displayFrame.rows,
                             displayFrame.step, QImage::Format_RGB888);
        ui->LB_MainView->setPixmap(QPixmap::fromImage(qimg).scaled(ui->LB_MainView->width(),
                                                                   ui->LB_MainView->height(), Qt::KeepAspectRatio));
    }else{

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BTN_CamOpen_clicked()
{
    if(ImgInput.GetImageSource() != FROM_CAMERA){
        if(ImgInput.CamOpen()){
        ui->PTE_AppLog->appendPlainText("Camera opened");
        ImgInput.SetImageSource(FROM_CAMERA);

        QIcon BTIconCamOn(pixCamOn);
        ui->BTN_CamOpen->setIcon(BTIconCamOn);
        ui->BTN_CamOpen->setIconSize(pixCamOn.rect().size());

        QIcon BTIconImgOff(pixImgOff);
        ui->BTN_ImageOpen->setIcon(BTIconImgOff);
        ui->BTN_ImageOpen->setIconSize(pixImgOff.rect().size());

        QIcon BTIconVideoOff(pixVideoOff);
        ui->BTN_VideoOpen->setIcon(BTIconVideoOff);
        ui->BTN_VideoOpen->setIconSize(pixVideoOff.rect().size());

        QIcon BTIconPause(pixPauseStop);
        ui->BTNPause->setIcon(BTIconPause);
        ui->BTNPause->setIconSize(ui->BTNPause->rect().size());

        //avoid input source changed while timer is disabled
        if(!timer.isActive()) {timer.start(timer_value);}
        }else{
            ui->PTE_AppLog->appendPlainText("Failed to open camera");
        }
    }else{
        ImgInput.CamClose();
        ui->PTE_AppLog->appendPlainText("Camera closed");
        ImgInput.SetImageSource(IDLE);

//        ui->LB_MainView->setPixmap(MainViewBG.scaled(ui->LB_MainView->width(), ui->LB_MainView->height(),
//                                                     Qt::IgnoreAspectRatio));

        QIcon BTIconCamOff(pixCamOff);
        ui->BTN_CamOpen->setIcon(BTIconCamOff);
        ui->BTN_CamOpen->setIconSize(pixCamOff.rect().size());

        QIcon BTIPauseDflt(pixpauseDflt);
        ui->BTNPause->setIcon(BTIPauseDflt);
        ui->BTNPause->setIconSize(ui->BTNPause->rect().size());
    }
}


void MainWindow::on_SB_CascadeFactor_valueChanged(int value)
{
    cascadeDetector.SetScaleFactor(double(double(value)/10.0));
    ui->LB_CascadeScaleFactorVal->setText(QString::number(double(value / 10.0)));
}


void MainWindow::on_SB_CascadeMinNeigbour_valueChanged(int value)
{
    cascadeDetector.SetminNeigbor(value);
    ui->LB_CascadeMinNeibourVal->setText(QString::number(value));
}


void MainWindow::on_BTN_ImageOpen_clicked()
{
    //Close cam if operating
    if(ImgInput.GetImageSource() == FROM_CAMERA){
        ImgInput.CamClose();
        ui->PTE_AppLog->appendPlainText("Camera closed");

        QIcon BTIconCamOff(pixCamOff);
        ui->BTN_CamOpen->setIcon(BTIconCamOff);
        ui->BTN_CamOpen->setIconSize(pixCamOff.rect().size());

        QIcon BTIPause(pixpauseDflt);
        ui->BTNPause->setIcon(BTIPause);
        ui->BTNPause->setIconSize(ui->BTNPause->rect().size());

    }else if((ImgInput.GetImageSource() == FROM_VIDEO)){
        ImgInput.CamClose();
        ui->PTE_AppLog->appendPlainText("Video opened");

        QIcon BTIconVideoOff(pixVideoOff);
        ui->BTN_VideoOpen->setIcon(BTIconVideoOff);
        ui->BTN_VideoOpen->setIconSize(pixVideoOff.rect().size());

        QIcon BTIconPause(pixpauseDflt);
        ui->BTNPause->setIcon(BTIconPause);
        ui->BTNPause->setIconSize(ui->BTNPause->rect().size());
    }
    timer.stop();
    QString filename =  QFileDialog::getOpenFileName(
              this,
              "Open Image",
              QDir::currentPath(),
              "All files (*.*) ;; JPG files (*.jpg);; PNG files (*.png)");

    if(!filename.isNull()){
       ImgInput.SetFileName(filename);
       ImgInput.SetImageSource(FROM_IMAGE);

       QIcon BTIconImgOn(pixImgOn);
       ui->BTN_ImageOpen->setIcon(BTIconImgOn);
       ui->BTN_ImageOpen->setIconSize(pixImgOn.rect().size());

       QIcon BTIPauseStop(pixPauseStop);
       ui->BTNPause->setIcon(BTIPauseStop);
       ui->BTNPause->setIconSize(ui->BTNPause->rect().size());

       //avoid input source changed while timer is disabled
       if(!timer.isActive()) {timer.start(timer_value);}
    }else{
        ImgInput.SetImageSource(IDLE);
        ui->PTE_AppLog->appendPlainText("File invalid");
    }
    timer.start(timer_value);
}


void MainWindow::on_CB_CascadeDetectorEnable_stateChanged(int arg1)
{
    if(arg1){
        ui->CB_CFDetectorEnable->setChecked(false);
    }
}


void MainWindow::on_BTN_VideoOpen_clicked()
{
    //Close cam if operating
    if(ImgInput.GetImageSource() == FROM_CAMERA){
        ImgInput.CamClose();
        ui->PTE_AppLog->appendPlainText("Camera closed");

        QIcon BTIconCamOff(pixCamOff);
        ui->BTN_CamOpen->setIcon(BTIconCamOff);
        ui->BTN_CamOpen->setIconSize(pixCamOff.rect().size());
    }else if(ImgInput.GetImageSource() == FROM_IMAGE){
        QIcon BTIconImgOff(pixImgOff);
        ui->BTN_ImageOpen->setIcon(BTIconImgOff);
        ui->BTN_ImageOpen->setIconSize(pixImgOff.rect().size());
    }

    QString filename =  QFileDialog::getOpenFileName(
              this,
              "Open Video",
              QDir::currentPath(),
              "All files (*.*) ;; MP4 files (*.mp4);; MOV files (*.mov)");

    if(!filename.isNull()){
       ImgInput.SetImageSource(FROM_VIDEO);
       ImgInput.VideoOpen(filename);

       QIcon BTIconVideoOn(pixVideoOn);
       ui->BTN_VideoOpen->setIcon(BTIconVideoOn);
       ui->BTN_VideoOpen->setIconSize(pixVideoOn.rect().size());

       QIcon BTIPauseStop(pixPauseStop);
       ui->BTNPause->setIcon(BTIPauseStop);
       ui->BTNPause->setIconSize(pixPauseStop.rect().size());

       //avoid input source changed while timer is disabled
       if(!timer.isActive()) {timer.start(timer_value);}
    }else{
        ImgInput.SetImageSource(IDLE);
        ui->PTE_AppLog->appendPlainText("File invalid");
    }
}


void MainWindow::on_CB_CFDetectorEnable_stateChanged(int arg1)
{
    if(arg1){
        ui->CB_CascadeDetectorEnable->setChecked(false);
    }
}





void MainWindow::on_SB_CaffeScaleFactor_valueChanged(int value)
{
    DL.setScaleFactor(float(ui->SB_CaffeScaleFactor->value()/10.0));
    ui->LB_CaffeScaleFactorVal->setText(QString::number(float(ui->SB_CaffeScaleFactor->value()/10.0)));
}


void MainWindow::on_SB_CaffeScoreThresh_valueChanged(int value)
{
    DL.setCfdThreshold(float(ui->SB_CaffeScoreThresh->value()/10.0));
    ui->LB_CaffeScoreThreshVal->setText(QString::number(float(ui->SB_CaffeScoreThresh->value()/10.0)));
}


void MainWindow::on_BTNPause_clicked()
{
    if(ImgInput.GetImageSource() != IDLE){
        if(timer.isActive()){
            timer.stop();
            QIcon BTIPauseStart(pixPauseStart);
            ui->BTNPause->setIcon(BTIPauseStart);
            ui->BTNPause->setIconSize(pixPauseStart.rect().size());

        }else{
            timer.start(timer_value);

            QIcon BTIPauseStop(pixPauseStop);
            ui->BTNPause->setIcon(BTIPauseStop);
            ui->BTNPause->setIconSize(ui->BTNPause->rect().size());
        }
    }
}

