#ifndef ARROWLABEL_H
#define ARROWLABEL_H
#include <QLabel>
#include <QWidget>
#include <QPropertyAnimation>
class ArrowLabel : public QLabel
{
    Q_OBJECT
public:
    ArrowLabel(QWidget * parent = nullptr);
    void updateArrow(int value);
private:
    QPropertyAnimation * animation;
};

#endif // ARROWLABEL_H
