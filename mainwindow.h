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
    void on_pushButton_3_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_btn_start_clicked();

    void on_btn_stop_clicked();

private:
    Ui::MainWindow *ui;
    BatteryWidget *batteryWidget; // 电池控件指针
    DataShow * m_dataShow;
    bool m_isForward = true;                 //是否电量增长
    int  m_curBatteryVal = 16;
    int  m_batteryMaxVal = 95;
    int  m_batteryMinVal = 15;
    ShowMode m_mode = NORMAL;
    bool m_btn_goOn = true;
};
#endif // MAINWINDOW_H
