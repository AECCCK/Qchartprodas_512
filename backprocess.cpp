#include"backprocess.h"
#include"external.h"
#include<windows.h>
#include<QDebug>
#include"mainwindow.h"


HINSTANCE BackProcess::hdll = LoadLibraryA("EPHL.dll");

void BackProcess::DataProcess()
{
   // NetFloatData data;
    //调用prodas函数反复读取通道数值
    //m_channelvalue.resize(m_channelqantity);//修改通道值容器元素个数

    m_channelqantity=4;
    //m_channelvalue.resize(m_channelqantity);

    readfunc P_readfunc = (readfunc)GetProcAddress(hdll, "EPHL_read_channel");
    initfunc P_initfunc = (initfunc)GetProcAddress(hdll, "EPHL_init");
     closefunc P_closefunc = (closefunc)GetProcAddress(hdll, "EPHL_close");


      for(int i=0;i<m_channelqantity;i++)
      {
            P_initfunc(EPHL_SOCKET,"ex_serv");
            eEPHL_RETURN return_code;
            float *temp_value=new float(0);
         //   temp_value=new float;
            char *temp_name;
            QByteArray ba;
            ba=m_channelname[i].toLatin1();
            temp_name=ba.data();
            //调用函数提取i的通道数据
            return_code=P_readfunc(temp_name,temp_value);
            qDebug()<<*temp_value;
         //   qDebug()<<return_code;
            float temp;
            temp=*temp_value;
           // float* temp_data=&channelvalue;
           // m_channelvalue.push_back(temp);
            m_channelvalue[i]=temp;

            delete temp_value;
            P_closefunc();
      }

        m_data1.push_back(QPointF(count,m_channelvalue[0]));
        m_data2.push_back(QPointF(count,m_channelvalue[1]));
        m_data3.push_back(QPointF(count,m_channelvalue[2]));
        m_data4.push_back(QPointF(count,m_channelvalue[3]));
        //删除第一个数据，以保证数据个数不会超出最大范围
        //存20秒的数据
            if (m_data1.size() >= 200)
            {
                m_data1.removeFirst();
            }
            if (m_data2.size() >= 200)
            {
                m_data2.removeFirst();
            }
            if (m_data3.size() >= 200)
            {
                m_data3.removeFirst();
            }
            if (m_data4.size() >= 200)
            {
                m_data4.removeFirst();
            }
            QList<QPointF> _data1;
            QList<QPointF> _data2;
            QList<QPointF> _data3;
            QList<QPointF> _data4;
                //将数据向x轴左移
                for(int loop = 0; loop < m_data1.count(); loop++)
                {
                    _data1.append(QPointF(loop, m_data1.at(loop).y()));
                }
                for(int loop = 0; loop < m_data2.count(); loop++)
                {
                    _data2.append(QPointF(loop, m_data2.at(loop).y()));
                }
                for(int loop = 0; loop < m_data3.count(); loop++)
                {
                    _data3.append(QPointF(loop, m_data3.at(loop).y()));
                }
                for(int loop = 0; loop < m_data4.count(); loop++)
                {
                    _data4.append(QPointF(loop, m_data4.at(loop).y()));
                }
                count=count+0.1;
                //发送处理后的数据出去
                emit sendSeries(_data1,_data2,_data3,_data4);

       // emit SendChannelvalue(m_channelvalue);


}

void BackProcess::SlotStartInit()
{
    timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &BackProcess::DataProcess);
        //添加于512，用于停止计时器，待验证(验证通过)
        connect(this,&BackProcess::Stop,timer,&QTimer::stop);
        //开始定时器，0.1s刷新一次数据
        timer->start(100);
}

BackProcess::BackProcess(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<QList<QPointF>>("QList<QPointF>");
    connect(this, &BackProcess::startInit, this, &BackProcess::SlotStartInit);
}

void BackProcess::GetChannelName(QStringList a)
{
    m_channelname=a;
}

void BackProcess::Reset()
{
    count=0;
    m_channelname.clear();
    m_data1.clear();
    m_data2.clear();
    m_data3.clear();
    m_data4.clear();
}
