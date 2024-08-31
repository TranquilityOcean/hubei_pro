#ifndef BATTERYWIDGET_H
#define BATTERYWIDGET_H

#include <QWidget>

class BatteryWidget:public QWidget
{
    Q_OBJECT
public:
    explicit BatteryWidget(QWidget *parent = nullptr);
    BatteryWidget();
    // 设置电池电量的接口，范围为 0 到 100
    void setBatteryLevel(int level);
protected:
    // 重写绘制事件，以便自定义绘制电池形状和电量
    void paintEvent(QPaintEvent *event) override;

private:
    int batteryLevel; // 当前电量，0 到 100 之间
};

#endif // BATTERYWIDGET_H
