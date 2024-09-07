#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QTimer>
#include <QDebug>
#include <QPainter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_isForward(true)
{
    ui->setupUi(this);
    // 创建电池控件并设置初始电量
    batteryWidget = new BatteryWidget(this);
//    batteryWidget->setFixedSize(70, 120); // 设置控件大小
    // 获取占位符的布局
    QVBoxLayout *layout = new QVBoxLayout(ui->widget_battery);
    // 将自定义 Widget 添加到这个布局中
    layout->addWidget(batteryWidget);
    ui->widget_battery->setLayout(layout);
    // 使用定时器模拟电量变化
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, [this]() {
        ui->label_timeShow->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));//开始仿真前默认显示当前时间
    });
    m_timer->start(1000);
    m_timer_updateArrow = new QTimer(this);
    connect(m_timer_updateArrow, SIGNAL(timeout()), this, SLOT(updateArrowValue()));
//    m_timer_updateArrow->start(100);
    m_dataShow = new DataShow(this);
    ui->widget_dataShow->setLayout(m_dataShow->layout());
    ui->dateTimeEdit->setTime(QTime::currentTime());
//    ui->btn_stop->setStyleSheet("background-color: green; color: white;");
    ui->label_timeShow->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    connect(m_dataShow,&DataShow::valueUpdated,this, &MainWindow::updateValue);//连接子控件的信号到主窗体的槽函数
    batteryWidget->setBatteryLevel(m_curBatteryVal);//电池初始状态设置为20%的电量
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_dataSel_clicked()
{
    // 创建一个模态对话框来显示日期时间编辑控件
    QDialog dateTimeDialog(this);
    dateTimeDialog.setWindowTitle("选择日期时间");
    QDateTimeEdit *dateTimeWidget = new QDateTimeEdit(&dateTimeDialog);
    dateTimeWidget->setCalendarPopup(true);
    dateTimeWidget->setDateTime(ui->dateTimeEdit->dateTime());  // 设置初始日期时间为 QDateTimeEdit 的日期时间
    QString style = ui->dateTimeEdit->styleSheet();
    dateTimeWidget->setStyleSheet(style);
    QVBoxLayout *dialogLayout = new QVBoxLayout(&dateTimeDialog);
    dialogLayout->addWidget(dateTimeWidget);

    // 添加确定按钮
    QPushButton *okButton = new QPushButton("OK", &dateTimeDialog);
    okButton->setStyleSheet(ui->btn_start->styleSheet());
    dialogLayout->addWidget(okButton);

    // 连接确定按钮的点击信号到槽函数
    connect(okButton, &QPushButton::clicked, &dateTimeDialog, &QDialog::accept);

    // 显示对话框并等待用户操作
    if (dateTimeDialog.exec() == QDialog::Accepted)
    {
        // 如果用户点击了确定按钮，则将选中的日期时间设置到 QDateTimeEdit 中
        ui->dateTimeEdit->setDateTime(dateTimeWidget->dateTime());
    }
    ui->btn_start->setEnabled(true);
}

void MainWindow::updateArrowValue()
{
    if(true)
    {
        m_offset += 0.5;
    }
    else
    {
        m_offset -= 0.5;
    }
    if(m_offset > 100)
    {
        m_offset = 0;
    }
    qDebug() << "m_offset: " << m_offset ;
    update();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
   QPainter painter(this);
   QPen pen(Qt::green);
   pen.setJoinStyle(Qt::RoundJoin);    // MiterJoin, BevelJoin, RoundJoin
   pen.setStyle(Qt::SolidLine);
   pen.setWidth(5);
   pen.setCapStyle(Qt::RoundCap);      // FlatCap, SquareCap, RoundCap
   painter.setPen(pen);
   QPointF sBnt1Pos1(180,60);    //btn0左中点
   QPointF sBnt1Pos3(180,140);
   painter.drawLine(sBnt1Pos1, sBnt1Pos3); //画一条直线

   QPen pen1(Qt::blue);
   QVector<qreal> dashes;
   qreal space = 2;
   dashes << 3 << space << 3 << space;
   pen1.setDashPattern(dashes); //自定义虚线的格式，---  ---
   pen1.setWidth(5);
   pen1.setJoinStyle(Qt::RoundJoin);    // MiterJoin, BevelJoin, RoundJoin
   pen1.setCapStyle(Qt::RoundCap);      // FlatCap, SquareCap, RoundCap
   pen1.setDashOffset(m_offset);
   painter.setPen(pen1);
   painter.drawLine(sBnt1Pos1, sBnt1Pos3);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    // index为0时为normal

   if(index == 0)
   {
       m_dataShow->setRunMode(NORMAL);
   }
   else
   {
       m_dataShow->setRunMode(Accelerate);
   }
}
//开始展示
void MainWindow::on_btn_start_clicked()
{
    QDateTime dataTime = ui->dateTimeEdit->dateTime();
    int year = dataTime.date().year();
    int month = dataTime.date().month();
    int day = dataTime.date().day();
    int hour = dataTime.time().hour();
    int minute = dataTime.time().minute();
    ChooseDataDate dataData;
    if(year == 2024 && month == 8 && day == 28)
    {
        dataData = Data_1;
    }
    else if(year == 2024 && month == 8 && day == 27)
    {
        dataData = Data_2;
    }
    else if(year == 2024 && month == 8 && day == 26)
    {
        dataData = Data_3;
    }
    else
    {
        //弹出消息框说明选择的日期里没有相关数据
        // 创建一个错误消息弹窗
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical); // 设置图标为错误类型
        msgBox.setWindowTitle("错误"); // 设置弹窗标题
        msgBox.setText("选择的日期没有相关数据"); // 设置弹窗内容
        msgBox.setInformativeText("当前20240828,20240827,20240826有数据"); // 设置附加信息
        msgBox.setStandardButtons(QMessageBox::Ok); // 设置标准按钮
        msgBox.setDefaultButton(QMessageBox::Ok); // 设置默认按钮
        msgBox.exec();
        return;
    }
    m_dataShow->setDataDateTime(dataData, hour, minute);
    m_dataShow->timerStart();
    ui->btn_start->setEnabled(false);
    ui->btn_stop->setText("暂停");
//    ui->btn_stop->setStyleSheet("background-color: green; color: white;");
    m_btn_goOn = true;
    ui->comboBox->setCurrentIndex(0);
    m_timer->stop();//停止主界面的定时器
}
//暂停按钮
void MainWindow::on_btn_stop_clicked()
{
    m_btn_goOn =  !m_btn_goOn;
    if(m_btn_goOn)
    {
        ui->btn_stop->setText("暂停");
        ui->btn_stop->setStyleSheet(    "QPushButton {"
                                        "    background-color: #1e2a38;"    /* 深蓝灰色背景 */
                                        "    color: #ffffff;"               /* 白色文本 */
                                        "    border: 2px solid #4a90e2;"    /* 亮蓝色边框 */
                                        "    border-radius: 10px;"          /* 圆角按钮 */
                                        "    padding: 10px 20px;"           /* 增加内边距 */
                                        "    font-size: 16px;"              /* 字体大小 */
                                        "    font-weight: bold;"            /* 加粗字体 */
                                        "}"
                                        "QPushButton:hover {"
                                        "    background-color: #4a90e2;"    /* 悬停时的亮蓝色背景 */
                                        "    border: 2px solid #ffffff;"    /* 悬停时的白色边框 */
                                        "}"
                                        "QPushButton:pressed {"
                                        "    background-color: #0f1a24;"    /* 按下时的深色背景 */
                                        "    border: 2px solid #4a90e2;"    /* 按下时的亮蓝色边框 */
                                        "}");          // 应用新的样式表
        m_dataShow->timerStart();
    }
    else
    {
        ui->btn_stop->setText("继续");
        ui->btn_stop->setStyleSheet(    "QPushButton {"
                                        "    background-color: #1e2a38;"    /* 深蓝灰色背景 */
                                        "    color: #ff0000;"               /* 白色文本 */
                                        "    border: 2px solid #4a90e2;"    /* 亮蓝色边框 */
                                        "    border-radius: 10px;"          /* 圆角按钮 */
                                        "    padding: 10px 20px;"           /* 增加内边距 */
                                        "    font-size: 16px;"              /* 字体大小 */
                                        "    font-weight: bold;"            /* 加粗字体 */
                                        "}"
                                        "QPushButton:hover {"
                                        "    background-color: #4a90e2;"    /* 悬停时的亮蓝色背景 */
                                        "    border: 2px solid #ffffff;"    /* 悬停时的白色边框 */
                                        "}"
                                        "QPushButton:pressed {"
                                        "    background-color: #0f1a24;"    /* 按下时的深色背景 */
                                        "    border: 2px solid #4a90e2;"    /* 按下时的亮蓝色边框 */
                                        "}");          // 应用新的样式表
        m_dataShow->timerStop();
    }
}

void MainWindow::updateValue(QString time,double fuheValue, double pv_value, double exchangeValue, double eneryValue,ShowMode mode,double chuNengPercent)
{
    //时间更新
    ui->label_timeShow->setText(time);
    //各部件功率更新
    double value = 0;
    value = fuheValue*1000;
    ui->label_fuHe->setText(QString::number(value,'f',3)+ "kW");
    value = pv_value*1000;
    ui->label_pv->setText(QString::number(value,'f',3)+ "kW");
    value = exchangeValue*1000;
    ui->label_exchange->setText(QString::number(value,'f',3)+ "kW");
    value = eneryValue*1000;
    ui->label_chuNeng->setText(QString::number(value,'f',3)+ "kW");
    m_curBatteryVal = chuNengPercent;
//    if(mode == NORMAL)//每秒
//    {
//        m_curBatteryVal += eneryValue /60/60/2;
//    }
//    else if(mode == Accelerate) //每15分钟
//    {
//        m_curBatteryVal+= eneryValue/4/2;
//    }
    //光伏状态更新
    if(fabs(pv_value) < 1e-6)
    {
        ui->label_pv_status->setText("待机中");
    }
    else if (pv_value > 0)
    {
         ui->label_pv_status->setText("出力中");
    }
    //电网状态更新
    if(fabs(exchangeValue) < 1e-6)
    {
        ui->label_GridStatus->setText("全绿电供应");
    }
    else if (exchangeValue < 0)
    {
         ui->label_GridStatus->setText("绿电反送电网");
    }
    else if(exchangeValue >0)
    {
        ui->label_GridStatus->setText("市电补充");
    }

    //储能状态更新
    if(fabs(eneryValue) < 1e-6)
    {
        ui->label->setText("待机中");
    }
    else if (eneryValue < 0)
    {
         ui->label->setText("放电中");
    }
    else if(eneryValue >0)
    {
        ui->label->setText("充电中");
    }
    //策略更新
    //储能功率为0，光伏功率为0
    //光伏待机、储能待机、市电供电只有一种情况
    if(fabs(pv_value)< 1e-6 &&fabs(eneryValue) < 1e-6 &&  exchangeValue >0) //1
    {
        ui->label_ceLue->setText("1.光伏待机、储能待机、电网供电");
    }
    //光伏待机、储能充电、市电供电只有一种情况
    else if(fabs(pv_value)< 1e-6 &&eneryValue > 0 &&  exchangeValue >0) //2
    {
        ui->label_ceLue->setText("2.光伏待机、储能谷价充电、电网供电");
    }
    //光伏待机、储能放电、有两种情况，一种是储能全供电，一种是市电补充
    else if( fabs(pv_value)< 1e-6 && eneryValue < 0  &&  exchangeValue> 0)//3
    {
         ui->label_ceLue->setText("3.光伏待机、储能放电、市电补充");
    }
    else if( fabs(pv_value)< 1e-6 && eneryValue < 0  &&  fabs(exchangeValue) < 1e-6)//4
    {
         ui->label_ceLue->setText("4.储能全供电：光伏待机、储能放电、市电不供电");
    }

    //光伏出力时
    //光伏出力、储能待机、有三种情况，一为光伏不够时，市电补充；二为光伏出力刚好够负荷使用，三为光伏出力较大，需要反送电
    else if( pv_value > 0 && fabs(eneryValue) < 1e-6  && exchangeValue>0) //5
    {
         ui->label_ceLue->setText("5.光伏供电、储能待机、市电补充");
    }
    else if( pv_value > 0 && fabs(eneryValue) < 1e-6   && fabs(exchangeValue) < 1e-6) //6
    {
         ui->label_ceLue->setText("6.全光伏供电、储能待机、市电不供电");
    }
    else if( pv_value > 0 && fabs(eneryValue) < 1e-6   && exchangeValue <0) //7
    {
         ui->label_ceLue->setText("7.光伏供电、储能待机、反送电网");
    }

    //光伏出力、储能放电，储能放电一般都在峰价，优先确保不用电网的电，有三种情况，一为不用市电、二为市电补充、三为反送电网，第三种情况不经济，可以控制储能放电的功率，确保不反送电网

    else if(pv_value > 0 &&eneryValue < 0  &&  fabs(exchangeValue)< 1e-6) //8
    {
         ui->label_ceLue->setText("8.全绿电供应、光伏出力消纳、储能放电");
    }
    else if(pv_value > 0 &&eneryValue < 0  &&  exchangeValue>0) //9
    {
         ui->label_ceLue->setText("9.光伏供电、储能放电、市电补充");
    }
    else if(pv_value > 0 &&eneryValue < 0  &&  exchangeValue < 0 ) //10 不经济，不设计该种情况
    {
         ui->label_ceLue->setText("10.光伏供电、储能放电、反送电网");
    }

    //光伏出力、储能充电，电网分为三种情况，一为反送电网、二为电网不供电、三为电网补充
    else if(pv_value > 0 && eneryValue > 0 &&  exchangeValue  < 0 ) //11
    {
         ui->label_ceLue->setText("11.光伏供电、余电充储、余电反送上网");
    }
    else if(pv_value > 0 && eneryValue > 0 &&  fabs(exchangeValue)< 1e-6 ) //12
    {
         ui->label_ceLue->setText("12.光伏供电、余电充储、电网不供电");
    }
    else if(pv_value > 0 && eneryValue > 0 &&  exchangeValue>0 ) //13
    {
         ui->label_ceLue->setText("13.光伏供电、储能充电、市电补充");
    }
    //更新当前电池电量
    batteryWidget->setBatteryLevel(m_curBatteryVal);

    //设置箭头方向
    if(exchangeValue < 0)
    {
        ui->label_arrow->updateArrow(-2); //label_arrow
    }
    else if( fabs(exchangeValue)< 1e-6)
    {
        ui->label_arrow->updateArrow(0); //label_arrow
    }
    else
    {
        ui->label_arrow->updateArrow(2); //label_arrow
    }



}
