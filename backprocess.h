#ifndef BACKPROCESS_H
#define BACKPROCESS_H
#include<QObject>
#include<QVector>
#include<windows.h>
#include<QTimer>
#include<QPointF>

const int maxSize=10;

class BackProcess:public QObject
{
    Q_OBJECT
public:
    static HINSTANCE hdll;
  //  BackProcess(){RunorStop=1;}
    explicit BackProcess(QObject *parent=nullptr);

public slots:
    void DataProcess();   //prodas数据提取并串行化
  //  void GetChannelQantity(int,QStringList);  //从主线程共享通道表
 //   void StopProcess();
   // void RunProcess();
    void GetChannelName(QStringList);
    void SlotStartInit();
    void Reset();
//
private:
    int m_channelqantity;   //通道数
    QStringList m_channelname;//通道名
   // QVector<float> m_channelvalue;//储存prodas得到的通道数值
    float m_channelvalue[4];
    QList<QPointF> m_data1;//第一条曲线显示数据源
    QList<QPointF> m_data2;
    QList<QPointF> m_data3;
    QList<QPointF> m_data4;

    QTimer *timer;
    float count = 0;

signals:
  void SendChannelvalue(QVector<float>);
  void sendSeries(QList<QPointF>,QList<QPointF>,QList<QPointF>,QList<QPointF>);
  void Stop();
  void startInit();

};
#endif // BACKPROCESS_H
