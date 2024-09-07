#include "arrowlabel.h"
ArrowLabel::ArrowLabel(QWidget *parent ):QLabel(parent)
{
    setAttribute(Qt::WA_TranslucentBackground);
    setAlignment(Qt::AlignCenter);

    // 初始化动画
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(500);
    animation->setEasingCurve(QEasingCurve::Linear);

    // 设置箭头的初始大小
    setFixedSize(25, 25);
}

void ArrowLabel::updateArrow(int value)
{
    // 如果值为 0，则隐藏箭头并停止动画
    if (value == 0) {
        clear();
        animation->stop();
        return;
    }

//    // 设置箭头方向
    if (value > 0) {
        setPixmap(QPixmap(":/icon/images/downArrow-3.png").scaled(25,25));  // 设置向下箭头
    } else {
        setPixmap(QPixmap(":/icon/images/upArrow-3.png").scaled(25,25));    // 设置向上箭头
    }


    // 设置动画范围
    QRect startPos = geometry();
    QRect endPos = geometry();

    if (value > 0) {
        startPos.moveTop(60);   // 向下移动
        endPos.moveTop(140);
    } else {
        startPos.moveTop(140); // 向上移动
        endPos.moveTop(60);
    }

    // 配置动画
    animation->setStartValue(startPos);
    animation->setEndValue(endPos);

    // 启动动画
    animation->start();
}
