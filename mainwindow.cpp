#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QTimer>
#include <QDebug>
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
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this]() {
        if(m_isForward)
        {
            m_curBatteryVal += 1;
        }
        else
        {
            m_curBatteryVal -=1;
        }
        if(m_curBatteryVal >= m_batteryMaxVal)  {
            m_curBatteryVal = m_batteryMaxVal;
            m_isForward = false;
        }
        if(m_curBatteryVal <= m_batteryMinVal) {
            m_curBatteryVal = m_batteryMinVal;
            m_isForward = true;
        }

        batteryWidget->setBatteryLevel(m_curBatteryVal);
    });
    timer->start(100); // 每100ms更新一次电量
    m_dataShow = new DataShow(this);
    ui->widget_dataShow->setLayout(m_dataShow->layout());
    ui->dateTimeEdit->setTime(QTime::currentTime());
    ui->btn_stop->setStyleSheet("background-color: green; color: white;");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    // 创建一个模态对话框来显示日期时间编辑控件
    QDialog dateTimeDialog(this);
    dateTimeDialog.setWindowTitle("选择日期时间");
    QDateTimeEdit *dateTimeWidget = new QDateTimeEdit(&dateTimeDialog);
    dateTimeWidget->setCalendarPopup(true);
    dateTimeWidget->setDateTime(ui->dateTimeEdit->dateTime());  // 设置初始日期时间为 QDateTimeEdit 的日期时间

    QVBoxLayout *dialogLayout = new QVBoxLayout(&dateTimeDialog);
    dialogLayout->addWidget(dateTimeWidget);

    // 添加确定按钮
    QPushButton *okButton = new QPushButton("OK", &dateTimeDialog);
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

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index == 0)
    {
        m_mode = NORMAL;
    }
    else
    {
        m_mode = Accelerate;
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
    ui->btn_stop->setStyleSheet("background-color: green; color: white;");
    m_btn_goOn = true;
    ui->comboBox->setCurrentIndex(0);
}
//暂停按钮
void MainWindow::on_btn_stop_clicked()
{
    m_btn_goOn =  !m_btn_goOn;
    if(m_btn_goOn)
    {
        ui->btn_stop->setText("暂停");
        ui->btn_stop->setStyleSheet("background-color: green; color: white;");
        m_dataShow->timerStart();
    }
    else
    {
        ui->btn_stop->setText("继续");
        ui->btn_stop->setStyleSheet("background-color: red; color: white;");
        m_dataShow->timerStop();
    }
}
