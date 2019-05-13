/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QChartView *graphicsView;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QPushButton *pushButton_Refresh;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_11;
    QCheckBox *checkBox_12;
    QCheckBox *checkBox_13;
    QCheckBox *checkBox_14;
    QLabel *label;
    QCheckBox *checkBox_15;
    QCheckBox *checkBox_16;
    QCheckBox *checkBox_17;
    QCheckBox *checkBox_18;
    QCheckBox *checkBox_19;
    QCheckBox *checkBox_20;
    QLabel *label_2;
    QPushButton *pushButton_Reset;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1920, 1080);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphicsView = new QChartView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(60, 90, 1781, 661));
        graphicsView->setResizeAnchor(QGraphicsView::AnchorViewCenter);
        checkBox = new QCheckBox(centralWidget);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->setExclusive(false);
        buttonGroup->addButton(checkBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(90, 850, 181, 21));
        checkBox_2 = new QCheckBox(centralWidget);
        buttonGroup->addButton(checkBox_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(300, 850, 201, 21));
        checkBox_3 = new QCheckBox(centralWidget);
        buttonGroup->addButton(checkBox_3);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(530, 850, 191, 21));
        checkBox_4 = new QCheckBox(centralWidget);
        buttonGroup->addButton(checkBox_4);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(750, 850, 201, 21));
        checkBox_5 = new QCheckBox(centralWidget);
        buttonGroup->addButton(checkBox_5);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(970, 850, 231, 21));
        checkBox_6 = new QCheckBox(centralWidget);
        buttonGroup->addButton(checkBox_6);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setGeometry(QRect(1240, 850, 231, 21));
        pushButton_Refresh = new QPushButton(centralWidget);
        pushButton_Refresh->setObjectName(QString::fromUtf8("pushButton_Refresh"));
        pushButton_Refresh->setGeometry(QRect(1240, 790, 104, 32));
        checkBox_7 = new QCheckBox(centralWidget);
        buttonGroup->addButton(checkBox_7);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setGeometry(QRect(1500, 850, 281, 21));
        checkBox_8 = new QCheckBox(centralWidget);
        buttonGroup->addButton(checkBox_8);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        checkBox_8->setGeometry(QRect(300, 900, 181, 21));
        checkBox_9 = new QCheckBox(centralWidget);
        buttonGroup->addButton(checkBox_9);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));
        checkBox_9->setGeometry(QRect(90, 900, 191, 21));
        checkBox_10 = new QCheckBox(centralWidget);
        buttonGroup->addButton(checkBox_10);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));
        checkBox_10->setGeometry(QRect(530, 900, 181, 21));
        checkBox_11 = new QCheckBox(centralWidget);
        buttonGroup->addButton(checkBox_11);
        checkBox_11->setObjectName(QString::fromUtf8("checkBox_11"));
        checkBox_11->setGeometry(QRect(750, 900, 211, 21));
        checkBox_12 = new QCheckBox(centralWidget);
        buttonGroup->addButton(checkBox_12);
        checkBox_12->setObjectName(QString::fromUtf8("checkBox_12"));
        checkBox_12->setGeometry(QRect(970, 900, 211, 21));
        checkBox_13 = new QCheckBox(centralWidget);
        buttonGroup->addButton(checkBox_13);
        checkBox_13->setObjectName(QString::fromUtf8("checkBox_13"));
        checkBox_13->setGeometry(QRect(1240, 900, 221, 21));
        checkBox_14 = new QCheckBox(centralWidget);
        buttonGroup->addButton(checkBox_14);
        checkBox_14->setObjectName(QString::fromUtf8("checkBox_14"));
        checkBox_14->setGeometry(QRect(1500, 900, 241, 21));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(850, 790, 151, 41));
        label->setScaledContents(false);
        label->setMargin(0);
        checkBox_15 = new QCheckBox(centralWidget);
        buttonGroup->addButton(checkBox_15);
        checkBox_15->setObjectName(QString::fromUtf8("checkBox_15"));
        checkBox_15->setGeometry(QRect(90, 950, 201, 21));
        checkBox_16 = new QCheckBox(centralWidget);
        buttonGroup->addButton(checkBox_16);
        checkBox_16->setObjectName(QString::fromUtf8("checkBox_16"));
        checkBox_16->setGeometry(QRect(300, 950, 231, 21));
        checkBox_17 = new QCheckBox(centralWidget);
        buttonGroup->addButton(checkBox_17);
        checkBox_17->setObjectName(QString::fromUtf8("checkBox_17"));
        checkBox_17->setGeometry(QRect(530, 950, 211, 21));
        checkBox_18 = new QCheckBox(centralWidget);
        buttonGroup->addButton(checkBox_18);
        checkBox_18->setObjectName(QString::fromUtf8("checkBox_18"));
        checkBox_18->setGeometry(QRect(750, 950, 181, 21));
        checkBox_19 = new QCheckBox(centralWidget);
        buttonGroup->addButton(checkBox_19);
        checkBox_19->setObjectName(QString::fromUtf8("checkBox_19"));
        checkBox_19->setGeometry(QRect(970, 950, 191, 21));
        checkBox_20 = new QCheckBox(centralWidget);
        buttonGroup->addButton(checkBox_20);
        checkBox_20->setObjectName(QString::fromUtf8("checkBox_20"));
        checkBox_20->setGeometry(QRect(1240, 950, 100, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(650, 10, 681, 71));
        pushButton_Reset = new QPushButton(centralWidget);
        pushButton_Reset->setObjectName(QString::fromUtf8("pushButton_Reset"));
        pushButton_Reset->setGeometry(QRect(1120, 790, 104, 32));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1920, 29));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "PT4210_IntakeAir", nullptr));
        checkBox_2->setText(QApplication::translate("MainWindow", "TT4203_Intake_Temp", nullptr));
        checkBox_3->setText(QApplication::translate("MainWindow", "T_Cooler_Inlet_Air", nullptr));
        checkBox_4->setText(QApplication::translate("MainWindow", "T_Cooler_Outlet_Air", nullptr));
        checkBox_5->setText(QApplication::translate("MainWindow", "T_Cooler_Inlet_Water", nullptr));
        checkBox_6->setText(QApplication::translate("MainWindow", "T_Cooler_Outlet_Water", nullptr));
        pushButton_Refresh->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260", nullptr));
        checkBox_7->setText(QApplication::translate("MainWindow", "Cooler_Inlet_Water_Flow", nullptr));
        checkBox_8->setText(QApplication::translate("MainWindow", "Mdot_FE4201", nullptr));
        checkBox_9->setText(QApplication::translate("MainWindow", "TT4204_PreStartAir", nullptr));
        checkBox_10->setText(QApplication::translate("MainWindow", "Mdot_FE4202", nullptr));
        checkBox_11->setText(QApplication::translate("MainWindow", "TCV4205_MD_FBTemp", nullptr));
        checkBox_12->setText(QApplication::translate("MainWindow", "TCV4206_MD_FBTemp", nullptr));
        checkBox_13->setText(QApplication::translate("MainWindow", "PT4207_NormBleed", nullptr));
        checkBox_14->setText(QApplication::translate("MainWindow", "PCV4208_MD_FBPosn", nullptr));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt;\">                  \345\217\202\346\225\260\351\200\211\346\213\251</span></p></body></html>", nullptr));
        checkBox_15->setText(QApplication::translate("MainWindow", "PCV4211_MD_FBPosn", nullptr));
        checkBox_16->setText(QApplication::translate("MainWindow", "PT4208_SettlingCham", nullptr));
        checkBox_17->setText(QApplication::translate("MainWindow", "TE4206_Bellmouth", nullptr));
        checkBox_18->setText(QApplication::translate("MainWindow", "Mdot_Bellmouth", nullptr));
        checkBox_19->setText(QApplication::translate("MainWindow", "Cal_Mass_Flow", nullptr));
        checkBox_20->setText(QApplication::translate("MainWindow", "PDT4203", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">C1H-201\345\212\240\346\270\251\345\212\240\345\216\213\350\257\225\351\252\214\350\256\276\345\244\207\345\217\202\346\225\260\347\233\221\346\216\247</span></p></body></html>", nullptr));
        pushButton_Reset->setText(QApplication::translate("MainWindow", "\351\207\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
