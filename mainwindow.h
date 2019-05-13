#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QVector>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>
#include"backprocess.h"
#include <QtCharts>

QT_CHARTS_USE_NAMESPACE
#include "ui_mainwindow.h"

//using namespace QT_CHARTS_NAMESPACE;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    static HINSTANCE hdll2;

private:
    Ui::MainWindow *ui;
    QStringList m_channelnameget;//储存复选框得到的通道表
    QList<float> m_channelvalueget;//用于曲线显示的通道数据
    QLineSeries  *series1;
    QLineSeries  *series2;
    QLineSeries  *series3;
    QLineSeries  *series4;
    QChart *chart1;
    QValueAxis *m_axisX;
    QValueAxis *m_axisY1;
    QValueAxis *m_axisY2;
    QValueAxis *m_axisY3;
    QValueAxis *m_axisY4;
    BackProcess *back;
    void GetChannelInfo(QStringList);
    int getchannelname();
    float m_infomin[4];//储存4曲线通道最小值
    float m_infomax[4];//储存4曲线通道最大值
    QChartView *chartView1;
    bool ResetButton=0;//曲线是否重置的标识符

signals:
    void SendChannelName(QStringList);
    void ResetBackProcess();

private slots:
    void on_pushButton_Refresh_clicked();
    void GetChannelValue(QList<float>);
    void on_pushButton_Reset_clicked();
    void SlotUpdate(QList<QPointF>,QList<QPointF>,QList<QPointF>,QList<QPointF>);

};

#endif // MAINWINDOW_H
