#include "datashow.h"
#include <QPen>
using namespace QXlsx;
const int ElectricalLoadCol = 3;
const int EnergyCol = 4;
const int Pv_PowerCol = 5;
const int ExchangeCol = 6;
const int PriceCol = 7;
const int ChuNengPercentCol = 8;
const int StartRow = 3;
const int EndRow = 98;
const int AXIS_X_RANGE = 24*60*60;//一天的秒数
DataShow::DataShow(QWidget *parent) : QWidget(parent)
{
    m_customPlot = new QCustomPlot(this);
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(m_customPlot);
    setLayout(layout);
    QPen pen;
    pen.setWidth(2);
//    m_chuNengGraph = new QCPBars(m_customPlot->xAxis, m_customPlot->yAxis);
//    m_chuNengGraph->setWidth(0.5);
    m_chuNengGraph = m_customPlot->addGraph();
    pen.setColor(QColor(89, 150, 255)); //储能颜色,亮蓝色
    m_chuNengGraph->setPen(pen); //设置柱状图的边框颜色
//    m_chuNengGraph->setBrush(QBrush(QColor(89, 150, 255))); //设置柱状图的填充颜色

    m_fuHeGraph =m_customPlot->addGraph();
    pen.setColor(QColor(217, 97, 107)); //负荷颜色,粉红色
    m_fuHeGraph->setPen(pen);

    m_guangFuGraph =m_customPlot->addGraph();
    pen.setColor(QColor(233, 206, 92)); //光伏发电曲线颜色,亮黄色
    m_guangFuGraph->setPen(pen);

    m_exchangeGraph =m_customPlot->addGraph();
    pen.setColor(QColor(130, 227, 164)); //交换功率曲线颜色,亮绿色
    m_exchangeGraph->setPen(pen);
    //电价曲线
    m_rightAxis_dianjia = m_customPlot->axisRect()->axis(QCPAxis::atRight, 0);
    m_graph_dianjia = m_customPlot->addGraph(m_customPlot->xAxis, m_rightAxis_dianjia);
    m_graph_dianjia->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red, Qt::red, 3)); // 有散点
    m_graph_dianjia->setPen(QPen(Qt::red)); // 设置颜色以区分不同的图形
    m_rightAxis_dianjia->setTickLabelColor(Qt::red);
    m_rightAxis_dianjia->setRange(0, 7);
    //设置竖线
    m_verticalLine = new QCPItemLine(m_customPlot);
    pen.setColor(Qt::red);                    // 设置颜色为红色
    pen.setStyle(Qt::DashLine);               // 设置线型为虚线
    pen.setWidth(1);                          // 设置线宽为2像素
    m_verticalLine->setPen(pen);                // 应用到竖线

    // 设置轴标签
    m_customPlot->xAxis->setLabel("时间");
    m_customPlot->yAxis->setLabel("功率MW");
    // 设置轴范围
    m_customPlot->yAxis->setRange(-4, 6);
    m_customPlot->xAxis->setRange(0, AXIS_X_RANGE-1);
    //设置曲线名字
    m_chuNengGraph->setName("储能充放电功率");
    m_fuHeGraph->setName("负荷功率");
    m_guangFuGraph->setName("光伏发电功率");
    m_exchangeGraph->setName("交换功率");
    m_graph_dianjia->setName("峰谷电价曲线");
    m_rightAxis_dianjia->setLabel("电价：元");
    m_rightAxis_dianjia->setVisible(true);
    // 图例显示设置
    m_customPlot->legend->setVisible(true);
    m_customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft); // 放置到顶部居中
    m_customPlot->legend->setRowSpacing(-3); // 设置图例项之间的行间距
    m_customPlot->legend->setBrush(Qt::NoBrush);  // 取消背景刷
    // 设置图例字体颜色
    m_customPlot->legend->setTextColor(QColor(85, 170, 255));  // 将图例字体颜色设置为红色
    // 设置 X 轴标签
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    QVector<QString> timeShowVec{
        "00:00",
        "02:00",
        "04:00",
        "06:00",
        "08:00",
        "10:00",
        "12:00",
        "14:00",
        "16:00",
        "18:00",
        "20:00",
        "22:00",
        "24:00"
    };
    for (int i =0 ; i < 13; i++)
    {
        textTicker->addTick(i*2*60*60, timeShowVec[i]);

    }
    m_customPlot->xAxis->setTicker(textTicker);
    // 创建 QCPItemText 对象
    m_textLabel = new QCPItemText(m_customPlot);
    m_textLabel->setColor(QColor(85, 170, 255));  // 文本颜色为浅蓝色
    // 设置 QCustomPlot 的背景为透明
     m_customPlot->setBackground(Qt::transparent);
     // 也可以隐藏网格线
     m_customPlot->xAxis->grid()->setVisible(false);
     m_customPlot->yAxis->grid()->setVisible(false);
     //设置X轴线和Y轴线
     pen.setColor(QColor(85, 170, 255));                    // 设置颜色为红色               // 设置线型为虚线
     m_customPlot->xAxis->setBasePen(pen);  // 隐藏 X 轴线
     m_customPlot->yAxis->setBasePen(pen);  // 隐藏 Y 轴线
     pen.setColor(Qt::red);
     m_customPlot->yAxis2->setBasePen(pen);
     // 也可以设置坐标轴的整体颜色（轴线、刻度线等）
     m_customPlot->xAxis->setTickLabelColor(QColor(85, 170, 255));   // 设置 X 轴刻度标签的颜色
     m_customPlot->yAxis->setTickLabelColor(QColor(85, 170, 255)); // 设置 Y 轴刻度标签的颜色
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
        m_dataTime.setDate(QDate(2024,8,28));
    }
    else if (chooseDataDate == Data_2)
    {
        xlsx.selectSheet("20240827");
        m_dataTime.setDate(QDate(2024,8,27));
    }
    else if(chooseDataDate == Data_3)
    {
        xlsx.selectSheet("20240826");
        m_dataTime.setDate(QDate(2024,8,26));
    }
    m_vec_loadPower_raw.clear();
    m_vec_enery_raw.clear();
    m_vec_pv_raw.clear();
    m_vec_exchange_raw.clear();
    m_vec_price_raw.clear();
    m_vec_chuNengPercent_raw.clear();
    read_xlsx_colValue(StartRow,ElectricalLoadCol,xlsx,m_vec_loadPower_raw);
    read_xlsx_colValue(StartRow,EnergyCol,xlsx,m_vec_enery_raw);
    read_xlsx_colValue(StartRow,Pv_PowerCol,xlsx,m_vec_pv_raw);
    read_xlsx_colValue(StartRow,ExchangeCol,xlsx,m_vec_exchange_raw);
    read_xlsx_colValue(StartRow,PriceCol,xlsx,m_vec_price_raw);
    read_xlsx_colValue(StartRow,ChuNengPercentCol,xlsx,m_vec_chuNengPercent_raw);
    m_vec_loadPower_insert.clear();
    m_vec_enery_insert.clear();
    m_vec_pv_raw_insert.clear();
    m_vec_exchange_insert.clear();
    m_vec_price_insert.clear();
    m_vec_chuNengPercent_insert.clear();

    QVector<double> temp;
    //目前插值到23.45分
    for(int i = 0; i < m_vec_loadPower_raw.size()-1;i++)
    {

        temp = interpolate(m_vec_loadPower_raw[i], m_vec_loadPower_raw[i+1],900);
        m_vec_loadPower_insert.append(temp);
        temp = interpolate(m_vec_enery_raw[i], m_vec_enery_raw[i+1],900);
        m_vec_enery_insert.append(temp);
        temp = interpolate(m_vec_pv_raw[i], m_vec_pv_raw[i+1],900);
        m_vec_pv_raw_insert.append(temp);
        temp = interpolate(m_vec_exchange_raw[i], m_vec_exchange_raw[i+1],900);
        m_vec_exchange_insert.append(temp);
        temp = interpolate(m_vec_chuNengPercent_raw[i], m_vec_chuNengPercent_raw[i+1],900);
        m_vec_chuNengPercent_insert.append(temp);
        temp = interpolate(m_vec_price_raw[i],900);
        m_vec_price_insert.append(temp);
    }
    return true;
}

void DataShow::updatePlot()
{
//    m_customPlot->removeItem(m_verticalLine);
    //刷新绘图
    // 添加数据到曲线
    int hours = m_x_index / 3600;           // 每小时3600秒
    int minutes = (m_x_index % 3600) / 60;  // 剩余秒数转换为分钟
    int seconds = m_x_index % 60;           // 剩余秒数
    m_dataTime.setTime(QTime(hours,minutes,seconds));
    static int points_num = m_vec_loadPower_insert.size();
    if(points_num == 0)
    {
        return;
    }
    m_fuHeGraph->addData(m_x_index, m_vec_loadPower_insert[m_x_index]);
    m_guangFuGraph->addData(m_x_index, m_vec_pv_raw_insert[m_x_index]);
    m_exchangeGraph->addData(m_x_index, m_vec_exchange_insert[m_x_index]);
//    if(m_vec_enery_insert[m_x_index] < -0.00001 || m_vec_enery_insert[m_x_index] > 0.00001)
    {
        m_chuNengGraph->addData(m_x_index, m_vec_enery_insert[m_x_index]);
    }
    emit valueUpdated(m_dataTime.toString("yyyy-MM-dd HH:mm:ss"),m_vec_loadPower_insert[m_x_index],m_vec_pv_raw_insert[m_x_index],m_vec_exchange_insert[m_x_index],
                      m_vec_enery_insert[m_x_index],m_showMode,m_vec_chuNengPercent_insert[m_x_index]);
    m_verticalLine->start->setCoords(m_x_index, -4);
    m_verticalLine->end->setCoords(m_x_index, 6);


    // 设置文本内容
    m_textLabel->setText(m_dataTime.toString("yyyy-MM-dd HH:mm:ss"));

    // 设置文本字体和颜色
    m_textLabel->setFont(QFont("Helvetica", 12));  // 设置字体
    m_textLabel->setRotation(90);
    m_textLabel->position->setCoords(m_x_index+900, 0);  // 设置位置，x坐标与竖线对齐，y坐标在竖线之上
    if(m_showMode == NORMAL)
    {
       m_x_index += 1;
    }
    else if (m_showMode == Accelerate)
    {
       m_x_index += 900;//每次加15分钟的点
    }
    if(m_x_index  >=  points_num )
    {
        m_fuHeGraph->data()->clear();
        m_guangFuGraph->data()->clear();
        m_exchangeGraph->data()->clear();
        m_chuNengGraph->data()->clear();
        m_x_index = 0;
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
     readInputData(dataDate); //读离线数据
     timerStop();
     m_fuHeGraph->data()->clear();
     m_guangFuGraph->data()->clear();
     m_exchangeGraph->data()->clear();
     m_chuNengGraph->data()->clear();
     m_x_index = hour * 60 *60 + minute * 60;
     //把选定时间点之前的曲线画出来
     QVector<double> valuesVector_xData;
     QVector<double> valuesVector_yData;
     for (int i = 0; i < m_x_index; ++i) {
         valuesVector_xData.append(i);
     }
     valuesVector_yData = m_vec_loadPower_insert.mid(0, m_x_index);
     m_fuHeGraph->setData(valuesVector_xData, valuesVector_yData);

     valuesVector_yData = m_vec_enery_insert.mid(0, m_x_index);
     m_chuNengGraph->setData(valuesVector_xData, valuesVector_yData);

     valuesVector_yData = m_vec_pv_raw_insert.mid(0, m_x_index);
     m_guangFuGraph->setData(valuesVector_xData, valuesVector_yData);

     valuesVector_yData = m_vec_exchange_insert.mid(0, m_x_index);
     m_exchangeGraph->setData(valuesVector_xData, valuesVector_yData);

     //电价曲线绘制
     valuesVector_xData.clear();
     //m_vec_price_insert 只插值到晚上11.45，所以valuesVector_xData的size1为95
     for (int i = 0; i < m_vec_price_insert.size(); i+=900) {
         valuesVector_xData.append(i); // 电价的横轴坐标补充完整
     }
     //将valuesVector_xData的最后一个元素追加进来,使其和m_vec_price_raw的size相同
     valuesVector_xData.append(valuesVector_xData.last());
     m_graph_dianjia->setData(valuesVector_xData, m_vec_price_raw);
     m_graph_dianjia->setLineStyle(QCPGraph::lsStepRight);
     m_customPlot->replot();
}

void DataShow::setRunMode(ShowMode mode)
{
    m_showMode = mode;
}
// 插值函数
QVector<double> DataShow::interpolate(double startValue, double endValue, int count) {
    QVector<double> result;

    if (count < 2) {
        // 如果count小于2，无法进行插值
        qWarning() << "插值个数必须大于等于2";
        return result;
    }

    double step = (endValue - startValue) / (count - 1);

    for (int i = 0; i < count; ++i) {
        result.append(startValue + i * step);
    }

    return result;
}
// 插值函数
QVector<double> DataShow::interpolate(double value, int count) {
    //针对电价的扩充
    QVector<double> result;
    for (int i = 0; i < count; ++i) {
        result.append(value);
    }
    return result;
}
