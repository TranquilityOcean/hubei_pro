#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "batterywidget.h"
#include "datashow.h"
#include "type.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_btn_start_clicked();

    void on_btn_stop_clicked();
    void updateValue(QString time,double fuheValue, double pv_value, double exchangeValue, double eneryValue, ShowMode mode,double chuNengPercent);

    void on_btn_dataSel_clicked();
    void updateArrowValue();
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::MainWindow *ui;
    BatteryWidget *batteryWidget; // 电池控件指针
    DataShow * m_dataShow;
    bool m_isForward = true;                 //是否电量增长
    double  m_curBatteryVal = 20;//百分比
    double  m_batteryMaxVal = 90;//百分比
    double  m_batteryMinVal = 20;//百分比
    bool m_btn_goOn = true;
    QTimer *m_timer;
    QTimer *m_timer_updateArrow;
    double m_offset = 0;
};
#endif // MAINWINDOW_H
