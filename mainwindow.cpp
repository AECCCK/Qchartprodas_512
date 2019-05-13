#include "mainwindow.h"
#include <QtCharts>
#include"backprocess.h"
#include<QMessageBox>
#include"external.h"

//QT_CHARTS_USE_NAMESPACE
//#include "ui_mainwindow.h"

HINSTANCE MainWindow::hdll2 = LoadLibraryA("EPHL.dll");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


//*********************************************

 //*****************************************

 //   QChart *chart4 = new QChart;
 //   series4 = new QLineSeries(this);
 //   series4->setUseOpenGL(true);
 //   chart4->addSeries(series4);
 //   chart4->createDefaultAxes();
    //设置范围
//    chart4->axisY()->setRange(-10, 10);
 //   chart4->axisX()->setRange(0, 20);
    //设置轴上字体
  //  chart4->axisX()->setTitleText("Time/sec");
  //  chart4->axisY()->setTitleText("Speed/m");
  //  chart4->setTitle("Dynamic spline chart4");
 //   chart4->legend()->hide();
 //   chart4->setAnimationOptions(QChart::AllAnimations);
 //   QChartView chartView4(chart4);
 //   chartView4.setRenderHint(QPainter::Antialiasing);


  //  ui->graphicsView_2->setChart(chart2);
  //  ui->graphicsView_3->setChart(chart3);
  //  ui->graphicsView_4->setChart(chart4);
  //  chart4 = new QChart;
   // series4 = new QLineSeries();
 //   series4->setUseOpenGL(true);
 //   chart4->addSeries(series4);
 //   m_axisX4=new QValueAxis;
  //  m_axisY4=new QValueAxis;
 //   series4->attachAxis(m_axisX4);
  //  series4->attachAxis(m_axisY4);
  //  m_axisX4->setTickCount(5);
  //  m_axisX4->setRange(0, 20);
   // m_axisY4->setRange(m_infomin[3],m_infomax[3]);
  //  chart4->addAxis(m_axisX4,Qt::AlignBottom);
  //  chart4->addAxis(m_axisY4,Qt::AlignLeft);
   // chart4->setTitle(m_channelnameget[3]);
 //   chart4->legend()->hide();
  //  chart4->setAnimationOptions(QChart::AllAnimations);
 //   QChartView chartView4(chart4);
 //   chartView4.setRenderHint(QPainter::Antialiasing);
 //   series4->append(3,390);
 //   ui->graphicsView_4->setChart(chart4);

    //实例化数据源更新子线程
    back = new BackProcess();
    QThread *datathread = new QThread();
    back->moveToThread(datathread);
    datathread->start();
    connect(datathread,&QThread::finished,datathread,&QObject::deleteLater); //防止内存泄漏
    connect(back, &BackProcess::sendSeries, this, &MainWindow::SlotUpdate);
 //   connect(this,SIGNAL(Run()),back,SLOT(DataProcess()));
    connect(this,SIGNAL(SendChannelName(QStringList)),back,SLOT(GetChannelName(QStringList)));
    connect(this,SIGNAL(ResetBackProcess()),back,SLOT(Reset()));

    //设置鼠标悬停显示
    ui->checkBox->setToolTip("气源供气压力");
    ui->checkBox_2->setToolTip("气源供气温度");
    ui->checkBox_3->setToolTip("水冷换热器空气进口温度");
    ui->checkBox_4->setToolTip("水冷换热器空气出口温度");
    ui->checkBox_5->setToolTip("冷却水进口温度");
    ui->checkBox_6->setToolTip("冷却水出口温度");
    ui->checkBox_7->setToolTip("冷却水流量");
    ui->checkBox_8->setToolTip("混合器出口温度");
    ui->checkBox_9->setToolTip("主文丘里流量");
    ui->checkBox_10->setToolTip("放气文丘里流量");
    ui->checkBox_11->setToolTip("TCV4205阀门开度");
    ui->checkBox_12->setToolTip("TCV4206阀门开度");
    ui->checkBox_13->setToolTip("PCV4208阀前压力");
    ui->checkBox_14->setToolTip("PCV4208阀门开度");
    ui->checkBox_15->setToolTip("PCV4211阀门开度");
    ui->checkBox_16->setToolTip("核心机进口压力");
    ui->checkBox_17->setToolTip("核心机进口温度");
    ui->checkBox_18->setToolTip("喇叭口测量流量");
    ui->checkBox_19->setToolTip("主文丘里流量与放气文丘里流量的差值");
    ui->checkBox_20->setToolTip("RV4210上下游压差");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GetChannelInfo(QStringList channelname)
{
    initfunc P_initfunc = (initfunc)GetProcAddress(hdll2, "EPHL_init");
    closefunc P_closefunc = (closefunc)GetProcAddress(hdll2, "EPHL_close");
    read_channel_info P_info=(read_channel_info)GetProcAddress(hdll2,"EPHL_read_channel_info");

    for(int i=0;i<4;i++)
    {
        P_initfunc(EPHL_SOCKET,"ex_serv");
        char *temp_name;
        EPHL_CHAN_INFO* info=new EPHL_CHAN_INFO;
        QByteArray ba = channelname[i].toLatin1();
        temp_name=ba.data();
        P_info(temp_name,info);
        m_infomin[i]=info->min;
        m_infomax[i]=info->max;
        delete info;
        P_closefunc();
    }

}

int MainWindow::getchannelname()
{
   int i=0;

   if(ui->checkBox->isChecked())
   {m_channelnameget+="PT4210_IntakeAir";
       ++i;}
   if(ui->checkBox_2->isChecked())
      { m_channelnameget+="TT4203_Intake_Temp";
       ++i;}
   if(ui->checkBox_3->isChecked())
   {
       m_channelnameget+="T_Cooler_Inlet_Air";
       ++i;
   }
   if(ui->checkBox_4->isChecked())
   {
       m_channelnameget+="T_Cooler_Outlet_Air";
       ++i;
   }
   if(ui->checkBox_5->isChecked())
   {
       m_channelnameget+="T_Cooler_Inlet_Water";
       ++i;
   }
   if(ui->checkBox_6->isChecked())
   {
       m_channelnameget+="T_Cooler_Outlet_Water";
       ++i;
   }
   if(ui->checkBox_7->isChecked())
   {
       m_channelnameget+="Cooler_Inlet_Water_FLow";
       ++i;
   }
   if(ui->checkBox_8->isChecked())
   {
       m_channelnameget+="TT4204_PreStartAir";
       ++i;
   }
   if(ui->checkBox_9->isChecked())
   {
       m_channelnameget+="Mdot_FE4201";
       ++i;
   }
   if(ui->checkBox_10->isChecked())
   {
       m_channelnameget+="Mdot_FE4202";
       ++i;
   }
   if(ui->checkBox_11->isChecked())
   {
       m_channelnameget+="TCV4205_MD_FBTemp";
       ++i;
   }
   if(ui->checkBox_12->isChecked())
   {
       m_channelnameget+="TCV4206_MD_FBTemp";
       ++i;
   }
   if(ui->checkBox_13->isChecked())
   {
       m_channelnameget+="PT4207_NormBleed";
       ++i;
   }
   if(ui->checkBox_14->isChecked())
   {
       m_channelnameget+="PCV4208_MD_FBPosn";
       ++i;
   }
   if(ui->checkBox_15->isChecked())
   {
       m_channelnameget+="PCV4211_MD_FBPosn";
       ++i;
   }
   if(ui->checkBox_16->isChecked())
   {
       m_channelnameget+="PCV4208_SettlingCham_avg";
       ++i;
   }
   if(ui->checkBox_17->isChecked())
   {
       m_channelnameget+="TE4206_BellMouth";
       ++i;
   }
   if(ui->checkBox_18->isChecked())
   {
       m_channelnameget+="Mdot_Bellmouth";
       ++i;
   }
   if(ui->checkBox_19->isChecked())
   {
       m_channelnameget+="Cal_Mass_Flow";
       ++i;
   }
   if(ui->checkBox_20->isChecked())
   {
       m_channelnameget+="PDT4203";
       ++i;
   }
   if(i!=4)
   {
       m_channelnameget.clear();//重置通道并且报错
       QMessageBox::warning(this,"错误",tr("选择的通道不等于4个，请重新选择"));
       return i;
   }
   if(i==4)
   {



   //获取通道最大最小值
   GetChannelInfo(m_channelnameget);
 //生产曲线实例
//***********************************
//曲线1
     chart1 = new QChart;

      series1 = new QLineSeries(this);
      series1->setUseOpenGL(true);
      series2 = new QLineSeries(this);
      series2->setUseOpenGL(true);
      series3 = new QLineSeries(this);
      series3->setUseOpenGL(true);
      series4 = new QLineSeries(this);
      series4->setUseOpenGL(true);

      series1->setColor(Qt::red);
      series2->setColor(Qt::blue);
      series3->setColor(Qt::green);
      series4->setColor(Qt::black);
      series1->setName(m_channelnameget[0]);
      series2->setName(m_channelnameget[1]);
      series3->setName(m_channelnameget[2]);
      series4->setName(m_channelnameget[3]);

      chart1->addSeries(series1);
      chart1->addSeries(series2);
      chart1->addSeries(series3);
      chart1->addSeries(series4);
      chart1->createDefaultAxes();
      //设置范围
      m_axisX=new QValueAxis;
      m_axisY1=new QValueAxis;
      m_axisY2=new QValueAxis;
      m_axisY3=new QValueAxis;
      m_axisY4=new QValueAxis;

      m_axisY1->setLabelsColor(Qt::darkRed);
      m_axisY2->setLabelsColor(Qt::darkBlue);
      m_axisY3->setLabelsColor(Qt::darkGreen);
      m_axisY4->setLabelsColor(Qt::black);

      m_axisY1->setRange(m_infomin[0], m_infomax[0]);
      m_axisY2->setRange(m_infomin[1], m_infomax[1]);
      m_axisY3->setRange(m_infomin[2], m_infomax[2]);
      m_axisY4->setRange(m_infomin[3], m_infomax[3]);
      m_axisX->setRange(0, 20);
      m_axisX->setTitleText("Time/Seconds");
      //坐标轴与数据源关联
      chart1->setAxisX(m_axisX,series1);
      chart1->setAxisX(m_axisX,series2);
      chart1->setAxisX(m_axisX,series3);
      chart1->setAxisX(m_axisX,series4);
      chart1->setAxisY(m_axisY1,series1);
      chart1->setAxisY(m_axisY2,series2);
      chart1->setAxisY(m_axisY3,series3);
      chart1->setAxisY(m_axisY4,series4);

 //     QLinearGradient plotAreaGradient;
  //        plotAreaGradient.setStart(QPointF(0, 1));
  //        plotAreaGradient.setFinalStop(QPointF(1, 0));
  //        plotAreaGradient.setColorAt(0.0, QRgb(0x555555));
 //         plotAreaGradient.setColorAt(1.0, QRgb(0x55aa55));
  //        plotAreaGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
  //        chart1->setPlotAreaBackgroundBrush(plotAreaGradient);
  //        chart1->setPlotAreaBackgroundVisible(true);



  //    chart1->axisY()->setTitleText("Speed/m");
      QString temp;
      for (int i=0;i<4;i++)
      {
          temp+=m_channelnameget[i]+",";
      }
      chart1->setTitle(temp);
    //  chart1->legend()->hide();
      chart1->setAnimationOptions(QChart::AllAnimations);
    //  chart1->setTheme(QChart::ChartThemeQt);
      chartView1 =new QChartView;
      QChartView chartView1(chart1);
      chartView1.setRenderHint(QPainter::Antialiasing);
      ui->graphicsView->setChart(chart1);

//*********************

   ResetButton=0;
   emit SendChannelName(m_channelnameget); //通道名发送给子线程
   return i;//返回通道数，用于判断是否触发计时器（当i==4时触发计时器）
   }


}

void MainWindow::on_pushButton_Refresh_clicked()
{
    int n;
    n=getchannelname();
    if(n==4)
    {
        back->startInit();
    }

}

void MainWindow::GetChannelValue(QList<float> a)
{
    m_channelvalueget=a;
}

void MainWindow::on_pushButton_Reset_clicked()
{
    ui->checkBox->setCheckState(Qt::Unchecked);
    ui->checkBox_2->setCheckState(Qt::Unchecked);
    ui->checkBox_3->setCheckState(Qt::Unchecked);
    ui->checkBox_4->setCheckState(Qt::Unchecked);
    ui->checkBox_5->setCheckState(Qt::Unchecked);
    ui->checkBox_6->setCheckState(Qt::Unchecked);
    ui->checkBox_7->setCheckState(Qt::Unchecked);
    ui->checkBox_8->setCheckState(Qt::Unchecked);
    ui->checkBox_9->setCheckState(Qt::Unchecked);
    ui->checkBox_10->setCheckState(Qt::Unchecked);
    ui->checkBox_11->setCheckState(Qt::Unchecked);
    ui->checkBox_12->setCheckState(Qt::Unchecked);
    ui->checkBox_13->setCheckState(Qt::Unchecked);
    ui->checkBox_14->setCheckState(Qt::Unchecked);
    ui->checkBox_15->setCheckState(Qt::Unchecked);
    ui->checkBox_16->setCheckState(Qt::Unchecked);
    ui->checkBox_17->setCheckState(Qt::Unchecked);
    ui->checkBox_18->setCheckState(Qt::Unchecked);
    ui->checkBox_19->setCheckState(Qt::Unchecked);
    ui->checkBox_20->setCheckState(Qt::Unchecked);

    m_channelnameget.clear();

    back->Stop(); //停止子线程计时器
    ResetButton=1;
    //重置子线程的记录事件
    emit ResetBackProcess();
  //  delete chartView1;
   // delete chart1;
  //  delete series1;
  //  delete series2;
  //  delete series3;
  //  delete series4;
  //  delete m_axisX;
  //  delete m_axisY1;
 //   delete m_axisY2;
  //  delete m_axisY3;
  //  delete m_axisY4;
}


//数据源更新
void MainWindow::SlotUpdate(QList<QPointF>temp1,QList<QPointF>temp2,QList<QPointF>temp3,QList<QPointF>temp4)
{
   if(ResetButton==0)
   {
    series1->replace(temp1);
    series2->replace(temp2);
    series3->replace(temp3);
    series4->replace(temp4);
   }
   else
   {
       //触发重置按钮，函数on_pushButton_Reset_clicked停止计时器后，slotupdate函数还会运行一次
       //重置图表
         delete series1;
         delete series2;
         delete series3;
         delete series4;
         delete m_axisX;
         delete m_axisY1;
         delete m_axisY2;
         delete m_axisY3;
         delete m_axisY4;
         chart1->setTitle("");
       //return;
   }

    if(temp1.size()>=20||temp2.size()>=20||temp3.size()>=20||temp4.size()>=20)
    {
        chart1->scroll(1,0);
    }

}


