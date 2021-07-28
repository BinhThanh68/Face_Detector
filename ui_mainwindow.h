/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *LB_MainView;
    QPushButton *BTN_CamOpen;
    QPushButton *BTN_ImageOpen;
    QPushButton *BTN_VideoOpen;
    QLabel *FacesNum;
    QLabel *label_2;
    QTabWidget *Algorithms;
    QWidget *tab;
    QCheckBox *CB_CascadeDetectorEnable;
    QLabel *LB_CascadeScaleFactorVal;
    QLabel *label;
    QSlider *SB_CascadeFactor;
    QLabel *LB_CascadeMinNeibourVal;
    QSlider *SB_CascadeMinNeigbour;
    QLabel *label_3;
    QWidget *tab_2;
    QCheckBox *CB_CFDetectorEnable;
    QLabel *LB_CaffeScoreThreshVal;
    QLabel *label_4;
    QLabel *LB_CaffeScaleFactorVal;
    QSlider *SB_CaffeScaleFactor;
    QSlider *SB_CaffeScoreThresh;
    QLabel *label_5;
    QPlainTextEdit *PTE_AppLog;
    QPushButton *BTNPause;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(827, 597);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        LB_MainView = new QLabel(centralwidget);
        LB_MainView->setObjectName(QString::fromUtf8("LB_MainView"));
        LB_MainView->setGeometry(QRect(10, 0, 721, 421));
        LB_MainView->setAutoFillBackground(false);
        LB_MainView->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);"));
        LB_MainView->setScaledContents(false);
        LB_MainView->setAlignment(Qt::AlignCenter);
        BTN_CamOpen = new QPushButton(centralwidget);
        BTN_CamOpen->setObjectName(QString::fromUtf8("BTN_CamOpen"));
        BTN_CamOpen->setGeometry(QRect(750, 10, 61, 51));
        BTN_ImageOpen = new QPushButton(centralwidget);
        BTN_ImageOpen->setObjectName(QString::fromUtf8("BTN_ImageOpen"));
        BTN_ImageOpen->setGeometry(QRect(750, 70, 61, 51));
        BTN_VideoOpen = new QPushButton(centralwidget);
        BTN_VideoOpen->setObjectName(QString::fromUtf8("BTN_VideoOpen"));
        BTN_VideoOpen->setGeometry(QRect(750, 130, 61, 51));
        FacesNum = new QLabel(centralwidget);
        FacesNum->setObjectName(QString::fromUtf8("FacesNum"));
        FacesNum->setGeometry(QRect(736, 390, 30, 31));
        QFont font;
        font.setPointSize(10);
        FacesNum->setFont(font);
        FacesNum->setAutoFillBackground(false);
        FacesNum->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);"));
        FacesNum->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(771, 390, 50, 31));
        label_2->setAutoFillBackground(true);
        label_2->setAlignment(Qt::AlignCenter);
        Algorithms = new QTabWidget(centralwidget);
        Algorithms->setObjectName(QString::fromUtf8("Algorithms"));
        Algorithms->setGeometry(QRect(484, 430, 331, 111));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        CB_CascadeDetectorEnable = new QCheckBox(tab);
        CB_CascadeDetectorEnable->setObjectName(QString::fromUtf8("CB_CascadeDetectorEnable"));
        CB_CascadeDetectorEnable->setGeometry(QRect(10, 20, 71, 22));
        CB_CascadeDetectorEnable->setAutoFillBackground(true);
        LB_CascadeScaleFactorVal = new QLabel(tab);
        LB_CascadeScaleFactorVal->setObjectName(QString::fromUtf8("LB_CascadeScaleFactorVal"));
        LB_CascadeScaleFactorVal->setGeometry(QRect(290, 8, 31, 21));
        LB_CascadeScaleFactorVal->setAutoFillBackground(false);
        LB_CascadeScaleFactorVal->setStyleSheet(QString::fromUtf8(""));
        LB_CascadeScaleFactorVal->setAlignment(Qt::AlignCenter);
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 7, 81, 20));
        SB_CascadeFactor = new QSlider(tab);
        SB_CascadeFactor->setObjectName(QString::fromUtf8("SB_CascadeFactor"));
        SB_CascadeFactor->setGeometry(QRect(180, 10, 101, 18));
        SB_CascadeFactor->setMinimum(11);
        SB_CascadeFactor->setMaximum(16);
        SB_CascadeFactor->setOrientation(Qt::Horizontal);
        LB_CascadeMinNeibourVal = new QLabel(tab);
        LB_CascadeMinNeibourVal->setObjectName(QString::fromUtf8("LB_CascadeMinNeibourVal"));
        LB_CascadeMinNeibourVal->setGeometry(QRect(289, 43, 31, 21));
        LB_CascadeMinNeibourVal->setAutoFillBackground(false);
        LB_CascadeMinNeibourVal->setStyleSheet(QString::fromUtf8(""));
        LB_CascadeMinNeibourVal->setAlignment(Qt::AlignCenter);
        SB_CascadeMinNeigbour = new QSlider(tab);
        SB_CascadeMinNeigbour->setObjectName(QString::fromUtf8("SB_CascadeMinNeigbour"));
        SB_CascadeMinNeigbour->setGeometry(QRect(181, 43, 101, 18));
        SB_CascadeMinNeigbour->setMinimum(1);
        SB_CascadeMinNeigbour->setMaximum(10);
        SB_CascadeMinNeigbour->setValue(6);
        SB_CascadeMinNeigbour->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(98, 40, 81, 20));
        Algorithms->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        CB_CFDetectorEnable = new QCheckBox(tab_2);
        CB_CFDetectorEnable->setObjectName(QString::fromUtf8("CB_CFDetectorEnable"));
        CB_CFDetectorEnable->setGeometry(QRect(10, 20, 71, 22));
        CB_CFDetectorEnable->setAutoFillBackground(true);
        LB_CaffeScoreThreshVal = new QLabel(tab_2);
        LB_CaffeScoreThreshVal->setObjectName(QString::fromUtf8("LB_CaffeScoreThreshVal"));
        LB_CaffeScoreThreshVal->setGeometry(QRect(291, 43, 31, 21));
        LB_CaffeScoreThreshVal->setAutoFillBackground(false);
        LB_CaffeScoreThreshVal->setStyleSheet(QString::fromUtf8(""));
        LB_CaffeScoreThreshVal->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 7, 81, 20));
        LB_CaffeScaleFactorVal = new QLabel(tab_2);
        LB_CaffeScaleFactorVal->setObjectName(QString::fromUtf8("LB_CaffeScaleFactorVal"));
        LB_CaffeScaleFactorVal->setGeometry(QRect(292, 8, 31, 21));
        LB_CaffeScaleFactorVal->setAutoFillBackground(false);
        LB_CaffeScaleFactorVal->setStyleSheet(QString::fromUtf8(""));
        LB_CaffeScaleFactorVal->setAlignment(Qt::AlignCenter);
        SB_CaffeScaleFactor = new QSlider(tab_2);
        SB_CaffeScaleFactor->setObjectName(QString::fromUtf8("SB_CaffeScaleFactor"));
        SB_CaffeScaleFactor->setGeometry(QRect(182, 10, 101, 18));
        SB_CaffeScaleFactor->setMinimum(11);
        SB_CaffeScaleFactor->setMaximum(20);
        SB_CaffeScaleFactor->setOrientation(Qt::Horizontal);
        SB_CaffeScoreThresh = new QSlider(tab_2);
        SB_CaffeScoreThresh->setObjectName(QString::fromUtf8("SB_CaffeScoreThresh"));
        SB_CaffeScoreThresh->setGeometry(QRect(183, 43, 101, 18));
        SB_CaffeScoreThresh->setMinimum(1);
        SB_CaffeScoreThresh->setMaximum(10);
        SB_CaffeScoreThresh->setValue(6);
        SB_CaffeScoreThresh->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(80, 40, 101, 20));
        Algorithms->addTab(tab_2, QString());
        PTE_AppLog = new QPlainTextEdit(centralwidget);
        PTE_AppLog->setObjectName(QString::fromUtf8("PTE_AppLog"));
        PTE_AppLog->setGeometry(QRect(10, 430, 471, 111));
        PTE_AppLog->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        PTE_AppLog->setReadOnly(true);
        BTNPause = new QPushButton(centralwidget);
        BTNPause->setObjectName(QString::fromUtf8("BTNPause"));
        BTNPause->setGeometry(QRect(760, 210, 41, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 827, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        Algorithms->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        LB_MainView->setText(QString());
#if QT_CONFIG(tooltip)
        BTN_CamOpen->setToolTip(QCoreApplication::translate("MainWindow", "Open camera", nullptr));
#endif // QT_CONFIG(tooltip)
        BTN_CamOpen->setText(QString());
#if QT_CONFIG(tooltip)
        BTN_ImageOpen->setToolTip(QCoreApplication::translate("MainWindow", "Open image", nullptr));
#endif // QT_CONFIG(tooltip)
        BTN_ImageOpen->setText(QString());
#if QT_CONFIG(tooltip)
        BTN_VideoOpen->setToolTip(QCoreApplication::translate("MainWindow", "Open video", nullptr));
#endif // QT_CONFIG(tooltip)
        BTN_VideoOpen->setText(QString());
        FacesNum->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "face\n"
"detected", nullptr));
#if QT_CONFIG(tooltip)
        CB_CascadeDetectorEnable->setToolTip(QCoreApplication::translate("MainWindow", "Enable cascade detector", nullptr));
#endif // QT_CONFIG(tooltip)
        CB_CascadeDetectorEnable->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
        LB_CascadeScaleFactorVal->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Scale Factor", nullptr));
#if QT_CONFIG(tooltip)
        SB_CascadeFactor->setToolTip(QCoreApplication::translate("MainWindow", "Adjust scale factor", nullptr));
#endif // QT_CONFIG(tooltip)
        LB_CascadeMinNeibourVal->setText(QString());
#if QT_CONFIG(tooltip)
        SB_CascadeMinNeigbour->setToolTip(QCoreApplication::translate("MainWindow", "Adjust min neigbor", nullptr));
#endif // QT_CONFIG(tooltip)
        label_3->setText(QCoreApplication::translate("MainWindow", "Min Neigbour", nullptr));
        Algorithms->setTabText(Algorithms->indexOf(tab), QCoreApplication::translate("MainWindow", "CascadeDetector", nullptr));
        CB_CFDetectorEnable->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
        LB_CaffeScoreThreshVal->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Scale Factor", nullptr));
        LB_CaffeScaleFactorVal->setText(QString());
#if QT_CONFIG(tooltip)
        SB_CaffeScaleFactor->setToolTip(QCoreApplication::translate("MainWindow", "Adjust scale factor", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        SB_CaffeScoreThresh->setToolTip(QCoreApplication::translate("MainWindow", "Adjust min neigbor", nullptr));
#endif // QT_CONFIG(tooltip)
        label_5->setText(QCoreApplication::translate("MainWindow", "Score Threshold", nullptr));
        Algorithms->setTabText(Algorithms->indexOf(tab_2), QCoreApplication::translate("MainWindow", "DeepLearning", nullptr));
        BTNPause->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
