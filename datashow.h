#ifndef DATASHOW_H
#define DATASHOW_H

#include <QWidget>
#include <QVector>
#include "xlsxdocument.h"
#include "qcustomplot.h"
#include "type.h"
class DataShow : public QWidget
{
    Q_OBJECT
public:
    explicit DataShow(QWidget *parent = nullptr);
    void read_xlsx_colValue(int startRow, int col,QXlsx::Document & xlsx,QVector<double> &vec);
    bool readInputData(ChooseDataDate& chooseDataDate);
    void timerStart();
    void timerStop();
    void setDataDateTime(ChooseDataDate & dataDate, int hour, int minute);
    void setRunMode(ShowMode mode);
    QVector<double> interpolate(double startValue, double endValue, int count);
    QVector<double> interpolate(double value, int count);
    bool m_isTimerStart = false;
signals:
    void valueUpdated(const QString & timeString,double value1,double value2,double value3,double value4,ShowMode mode,double value5);
private:
    QVector<double> m_vec_loadPower_raw;
    QVector<double> m_vec_enery_raw;
    QVector<double> m_vec_pv_raw;
    QVector<double> m_vec_exchange_raw;
    QVector<double> m_vec_price_raw;
    QVector<double> m_vec_chuNengPercent_raw;
    QVector<double> m_vec_loadPower_insert;
    QVector<double> m_vec_enery_insert;
    QVector<double> m_vec_pv_raw_insert;
    QVector<double> m_vec_exchange_insert;
    QVector<double> m_vec_price_insert;
    QVector<double> m_vec_chuNengPercent_insert;
    QCustomPlot *m_customPlot;
//    QCPBars  *m_chuNengGraph;
    QCPGraph  *m_chuNengGraph;
    QCPGraph *m_fuHeGraph;
    QCPGraph *m_guangFuGraph;
    QCPGraph *m_exchangeGraph;
    QCPGraph *m_graph_dianjia;
    QCPAxis *m_rightAxis_dianjia;
    QTimer *  m_timer;
    ChooseDataDate m_chooseDataDate;
    ShowMode m_showMode = NORMAL; //运行模式
    int m_hour;
    int m_minute;
    int m_x_index = 0;
    QDateTime m_dataTime;
    QCPItemLine * m_verticalLine;
    QCPItemText * m_textLabel;
public slots:
    void updatePlot();

};

#endif // DATASHOW_H
