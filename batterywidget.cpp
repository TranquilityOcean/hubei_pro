#include "batterywidget.h"
#include <QPainter>
BatteryWidget::BatteryWidget(QWidget *parent)
: QWidget(parent), batteryLevel(20) // 初始化电量为100%
{

}

void BatteryWidget::setBatteryLevel(double level)
{
    batteryLevel = level;
    update(); // 重新绘制控件
}

void BatteryWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    // 绘制电池外壳
    QRectF batteryRect(0, 0, width(), height()); // 纵向电池外壳
    QPen pen(QColor(85, 170, 255));  // 设置边框颜色
    pen.setWidth(3);     // 设置边框宽度
    painter.setPen(pen);
    painter.drawRect(batteryRect);
    // 根据电量绘制电量条
    double levelHeight = height()-((height() / 100.0)*batteryLevel) ;
    QColor levelColor;
    if(batteryLevel > 25 && batteryLevel < 90)
    {
        levelColor = Qt::green;
    }
    else
    {
        levelColor = Qt::red;
    }
    int diff = 2;
    //确定左上角位置
    QPointF topLeft(batteryRect.topLeft().x()+diff, levelHeight);
    //确定变化的右下角
    QPointF bottomRight(batteryRect.bottomRight().x()-diff,batteryRect.bottomRight().y()-diff);
    QRectF rect(topLeft, bottomRight);
    painter.fillRect(rect, levelColor);
    // 绘制电量百分比文本
    QString percentageText = QString::number(batteryLevel,'f',2) + "%";
    QFont font = painter.font();
    font.setBold(true);
    painter.setFont(font);
    // 将文本绘制在电池图标下方，并水平居中
    painter.setPen(QColor(85, 170, 255));
    painter.drawText(batteryRect,Qt::AlignCenter,percentageText);
}
