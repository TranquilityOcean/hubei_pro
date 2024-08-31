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
    bool m_isTimerStart = false;
signals:

private:
    QVector<double> m_vec_loadPower_raw;
    QVector<double> m_vec_enery_raw;
    QVector<double> m_vec_pv_raw;
    QVector<double> m_vec_exchange_raw;
    QCustomPlot *m_customPlot;
    QCPBars  *m_chuNengGraph;
    QCPGraph *m_fuHeGraph;
    QCPGraph *m_guangFuGraph;
    QCPGraph *m_exchangeGraph;
    QTimer *  m_timer;
    ChooseDataDate m_chooseDataDate;
    ShowMode m_showMode = NORMAL;
    int m_hour;
    int m_minute;
    int m_x_index = 0;

public slots:
    void updatePlot();

};

#endif // DATASHOW_H
