#include "datashow.h"
#include <QPen>
using namespace QXlsx;
const int ElectricalLoadCol = 3;
const int EnergyCol = 4;
const int Pv_PowerCol = 5;
const int ExchangeCol = 6;
const int StartRow = 3;
const int EndRow = 98;
const int ALL_POINTS_NUM  = 96;
DataShow::DataShow(QWidget *parent) : QWidget(parent)
{
    m_customPlot = new QCustomPlot(this);
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(m_customPlot);
    setLayout(layout);
    QPen pen;
    pen.setWidth(0);
    m_chuNengGraph = new QCPBars(m_customPlot->xAxis, m_customPlot->yAxis);
    m_chuNengGraph->setWidth(0.5);
    pen.setColor(QColor(89, 150, 255)); //储能颜色,亮蓝色
    m_chuNengGraph->setPen(pen); //设置柱状图的边框颜色
    m_chuNengGraph->setBrush(QBrush(QColor(89, 150, 255))); //设置柱状图的填充颜色
    pen.setWidth(2);
    m_fuHeGraph =m_customPlot->addGraph();
    pen.setColor(QColor(217, 97, 107)); //负荷颜色,粉红色
    m_fuHeGraph->setPen(pen);
    m_guangFuGraph =m_customPlot->addGraph();
    pen.setColor(QColor(233, 206, 92)); //光伏发电曲线颜色,亮黄色
    m_guangFuGraph->setPen(pen);
    m_exchangeGraph =m_customPlot->addGraph();
    pen.setColor(QColor(130, 227, 164)); //交换功率曲线颜色,亮绿色
    m_exchangeGraph->setPen(pen);
    // 设置轴标签
    m_customPlot->xAxis->setLabel("时间");
    m_customPlot->yAxis->setLabel("功率MW");
    // 设置轴范围
    m_customPlot->yAxis->setRange(-4, 6);
    m_customPlot->xAxis->setRange(0, 95);
    //设置曲线名字
    m_chuNengGraph->setName("储能充放电功率");
    m_fuHeGraph->setName("负荷功率");
    m_guangFuGraph->setName("光伏发电功率");
    m_exchangeGraph->setName("交换功率");
    // 图例显示设置
    m_customPlot->legend->setVisible(true);
    m_customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft); // 放置到顶部居中
    m_customPlot->legend->setRowSpacing(-3); // 设置图例项之间的行间距
    // 启动定时器，每秒更新一次数据
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &DataShow::updatePlot);
}

void DataShow::read_xlsx_colValue(int startRow, int col, QXlsx::Document &xlsx, QVector<double> &vec)
{
    // 获取某一列的所有值，例如第 1 列（列 A）
    while (true) {
        QXlsx::Cell *cell = xlsx.cellAt(startRow, col);
        if (cell) {
            QVariant value = cell->value();
            vec.push_back(value.toDouble());
        } else {
            // 如果单元格为空，停止读取
            break;
        }
        ++startRow;
        if(startRow > EndRow)
        {
            break;
        }
    }
}

bool DataShow::readInputData(ChooseDataDate& chooseDataDate)
{
    QString filePath = "./数据导入模板-湖北电能.xlsx";
    // 创建一个 QXlsx::Document 对象，打开指定的 Excel 文件
    QXlsx::Document xlsx(filePath);
    if (!xlsx.load())
    {
        // 创建一个错误消息弹窗
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical); // 设置图标为错误类型
        msgBox.setWindowTitle("错误"); // 设置弹窗标题
        msgBox.setText("打开文件错误"); // 设置弹窗内容
        msgBox.setInformativeText("请确认文件格式"); // 设置附加信息
        msgBox.setStandardButtons(QMessageBox::Ok); // 设置标准按钮
        msgBox.setDefaultButton(QMessageBox::Ok); // 设置默认按钮
        msgBox.exec();
        return false;
    }
    if(chooseDataDate == Data_1)
    {
        xlsx.selectSheet("20240828");
    }
    else if (chooseDataDate == Data_2)
    {
        xlsx.selectSheet("20240827");
    }
    else if(chooseDataDate == Data_3)
    {
        xlsx.selectSheet("20240826");
    }
    m_vec_loadPower_raw.clear();
    m_vec_enery_raw.clear();
    m_vec_pv_raw.clear();
    m_vec_exchange_raw.clear();
    read_xlsx_colValue(StartRow,ElectricalLoadCol,xlsx,m_vec_loadPower_raw);
    read_xlsx_colValue(StartRow,EnergyCol,xlsx,m_vec_enery_raw);
    read_xlsx_colValue(StartRow,Pv_PowerCol,xlsx,m_vec_pv_raw);
    read_xlsx_colValue(StartRow,ExchangeCol,xlsx,m_vec_exchange_raw);

    return true;
}

void DataShow::updatePlot()
{
    //刷新绘图
    // 添加数据到曲线
    if(m_vec_loadPower_raw.size() == 0)
    {
        return;
    }
    if(m_x_index >= ALL_POINTS_NUM-1)
    {
        m_x_index = 0;
    }
    m_fuHeGraph->addData(m_x_index, m_vec_loadPower_raw[m_x_index]);
    m_guangFuGraph->addData(m_x_index, m_vec_pv_raw[m_x_index]);
    m_exchangeGraph->addData(m_x_index, m_vec_exchange_raw[m_x_index]);
    if(m_vec_enery_raw[m_x_index] < -0.00001 || m_vec_enery_raw[m_x_index] > 0.00001)
    {
        m_chuNengGraph->addData(m_x_index, m_vec_enery_raw[m_x_index]);
    }
    m_x_index += 1;
    if(m_x_index  ==  ALL_POINTS_NUM -1 )
    {
        m_fuHeGraph->data()->clear();
        m_guangFuGraph->data()->clear();
        m_exchangeGraph->data()->clear();
        m_chuNengGraph->data()->clear();
    }
    m_customPlot->replot();
}

void DataShow::timerStart()
{
    m_isTimerStart = true;
    m_timer->start(1000);
}

void DataShow::timerStop()
{
    m_isTimerStart = false;
    m_timer->stop();
}

void DataShow::setDataDateTime(ChooseDataDate &dataDate, int hour, int minute)
{
     m_chooseDataDate= dataDate;
     m_hour = hour;
     m_minute = minute;
     readInputData(dataDate);
     timerStop();
     m_fuHeGraph->data()->clear();
     m_guangFuGraph->data()->clear();
     m_exchangeGraph->data()->clear();
     m_chuNengGraph->data()->clear();
     m_x_index = 0;
     m_customPlot->replot();
}

void DataShow::setRunMode(ShowMode mode)
{
    m_showMode = mode;
}
