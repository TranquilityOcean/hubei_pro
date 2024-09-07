/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "arrowlabel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label_21;
    QFrame *line_2;
    QFrame *line_guangFu;
    QLabel *label_14;
    QLabel *label_4;
    QLabel *label_QF04;
    QFrame *line_5;
    QFrame *line_4;
    QLabel *label_12;
    QLabel *label_QF03;
    QLabel *label_11;
    QLabel *label_15;
    QLabel *label_QF01;
    QLabel *label_10;
    QFrame *line_dianWang;
    QLabel *label_3;
    QWidget *widget_battery;
    QLabel *label_2;
    QFrame *line_chuNeng;
    QLabel *label_QF05;
    QLabel *label_QF02;
    QLabel *label_9;
    QLabel *label_5;
    QLabel *label_13;
    QFrame *line_fuZai;
    QLabel *label_18;
    QLabel *label_chuNeng;
    QLabel *label_exchange;
    QLabel *label_fuHe;
    QLabel *label_pv;
    QLabel *label;
    QLabel *label_pv_status;
    QLabel *label_GridStatus;
    ArrowLabel *label_arrow;
    QWidget *widget_dataShow;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *btn_dataSel;
    QPushButton *btn_start;
    QPushButton *btn_stop;
    QComboBox *comboBox;
    QLabel *label_timeShow_left;
    QLabel *label_timeShow;
    QLabel *label_7;
    QLabel *label_ceLue;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1100, 651);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/images/micro.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 90, 341, 561));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_21 = new QLabel(frame);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(160, 20, 71, 31));
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        line_2 = new QFrame(frame);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 171, 301, 16));
        line_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(4);
        line_2->setFrameShape(QFrame::HLine);
        line_guangFu = new QFrame(frame);
        line_guangFu->setObjectName(QString::fromUtf8("line_guangFu"));
        line_guangFu->setGeometry(QRect(130, 293, 20, 91));
        line_guangFu->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"background-image: url(:/icon/images/redColor.png);"));
        line_guangFu->setFrameShadow(QFrame::Plain);
        line_guangFu->setLineWidth(4);
        line_guangFu->setMidLineWidth(0);
        line_guangFu->setFrameShape(QFrame::VLine);
        label_14 = new QLabel(frame);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(110, 430, 71, 31));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(114, 390, 51, 41));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/icon/images/guangFu.png")));
        label_4->setScaledContents(true);
        label_QF04 = new QLabel(frame);
        label_QF04->setObjectName(QString::fromUtf8("label_QF04"));
        label_QF04->setGeometry(QRect(132, 320, 16, 31));
        label_QF04->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"background-image: url(:/icon/images/redColor.png);"));
        line_5 = new QFrame(frame);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(108, 282, 211, 20));
        line_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        line_5->setFrameShadow(QFrame::Plain);
        line_5->setLineWidth(4);
        line_5->setFrameShape(QFrame::HLine);
        line_4 = new QFrame(frame);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(210, 180, 20, 110));
        line_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        line_4->setFrameShadow(QFrame::Plain);
        line_4->setLineWidth(4);
        line_4->setMidLineWidth(0);
        line_4->setFrameShape(QFrame::VLine);
        label_12 = new QLabel(frame);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(150, 320, 71, 31));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_QF03 = new QLabel(frame);
        label_QF03->setObjectName(QString::fromUtf8("label_QF03"));
        label_QF03->setGeometry(QRect(212, 220, 16, 31));
        label_QF03->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"background-image: url(:/icon/images/redColor.png);"));
        label_11 = new QLabel(frame);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(230, 220, 71, 31));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_15 = new QLabel(frame);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(240, 420, 101, 61));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_15->setWordWrap(true);
        label_QF01 = new QLabel(frame);
        label_QF01->setObjectName(QString::fromUtf8("label_QF01"));
        label_QF01->setGeometry(QRect(121, 110, 16, 31));
        label_QF01->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"background-image: url(:/icon/images/redColor.png);"));
        label_10 = new QLabel(frame);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(50, 240, 71, 31));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        line_dianWang = new QFrame(frame);
        line_dianWang->setObjectName(QString::fromUtf8("line_dianWang"));
        line_dianWang->setGeometry(QRect(120, 70, 20, 111));
        line_dianWang->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"background-image: url(:/icon/images/redColor.png);"));
        line_dianWang->setFrameShadow(QFrame::Plain);
        line_dianWang->setLineWidth(4);
        line_dianWang->setMidLineWidth(0);
        line_dianWang->setFrameShape(QFrame::VLine);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 320, 61, 51));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/icon/images/yuanQu.png")));
        label_3->setScaledContents(true);
        widget_battery = new QWidget(frame);
        widget_battery->setObjectName(QString::fromUtf8("widget_battery"));
        widget_battery->setGeometry(QRect(180, 370, 71, 81));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 10, 71, 61));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/icon/images/dianWang.png")));
        label_2->setScaledContents(true);
        line_chuNeng = new QFrame(frame);
        line_chuNeng->setObjectName(QString::fromUtf8("line_chuNeng"));
        line_chuNeng->setGeometry(QRect(267, 294, 20, 91));
        line_chuNeng->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        line_chuNeng->setFrameShadow(QFrame::Plain);
        line_chuNeng->setLineWidth(4);
        line_chuNeng->setMidLineWidth(0);
        line_chuNeng->setFrameShape(QFrame::VLine);
        label_QF05 = new QLabel(frame);
        label_QF05->setObjectName(QString::fromUtf8("label_QF05"));
        label_QF05->setGeometry(QRect(268, 320, 16, 31));
        label_QF05->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"background-image: url(:/icon/images/redColor.png);"));
        label_QF02 = new QLabel(frame);
        label_QF02->setObjectName(QString::fromUtf8("label_QF02"));
        label_QF02->setGeometry(QRect(31, 240, 16, 31));
        label_QF02->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"background-image: url(:/icon/images/redColor.png);\n"
"color: rgb(255, 0, 0);\n"
"border-color: rgb(255, 0, 0);"));
        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(140, 110, 71, 31));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(257, 390, 41, 41));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/icon/images/chuNeng.png")));
        label_5->setScaledContents(true);
        label_13 = new QLabel(frame);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(287, 320, 41, 31));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        line_fuZai = new QFrame(frame);
        line_fuZai->setObjectName(QString::fromUtf8("line_fuZai"));
        line_fuZai->setGeometry(QRect(30, 180, 20, 141));
        line_fuZai->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        line_fuZai->setFrameShadow(QFrame::Plain);
        line_fuZai->setLineWidth(4);
        line_fuZai->setMidLineWidth(0);
        line_fuZai->setFrameShape(QFrame::VLine);
        label_18 = new QLabel(frame);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 140, 71, 31));
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_chuNeng = new QLabel(frame);
        label_chuNeng->setObjectName(QString::fromUtf8("label_chuNeng"));
        label_chuNeng->setGeometry(QRect(220, 470, 121, 20));
        label_chuNeng->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_chuNeng->setAlignment(Qt::AlignCenter);
        label_exchange = new QLabel(frame);
        label_exchange->setObjectName(QString::fromUtf8("label_exchange"));
        label_exchange->setGeometry(QRect(10, 80, 101, 20));
        label_exchange->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        label_exchange->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_fuHe = new QLabel(frame);
        label_fuHe->setObjectName(QString::fromUtf8("label_fuHe"));
        label_fuHe->setGeometry(QRect(0, 380, 101, 20));
        label_fuHe->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_fuHe->setAlignment(Qt::AlignCenter);
        label_pv = new QLabel(frame);
        label_pv->setObjectName(QString::fromUtf8("label_pv"));
        label_pv->setGeometry(QRect(80, 460, 131, 20));
        label_pv->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_pv->setAlignment(Qt::AlignCenter);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 350, 54, 21));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 127);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label->setAlignment(Qt::AlignCenter);
        label_pv_status = new QLabel(frame);
        label_pv_status->setObjectName(QString::fromUtf8("label_pv_status"));
        label_pv_status->setGeometry(QRect(63, 480, 151, 21));
        label_pv_status->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 127);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_pv_status->setAlignment(Qt::AlignCenter);
        label_GridStatus = new QLabel(frame);
        label_GridStatus->setObjectName(QString::fromUtf8("label_GridStatus"));
        label_GridStatus->setGeometry(QRect(10, 110, 101, 21));
        label_GridStatus->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 127);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_GridStatus->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_arrow = new ArrowLabel(frame);
        label_arrow->setObjectName(QString::fromUtf8("label_arrow"));
        label_arrow->setGeometry(QRect(117, 80, 21, 21));
        label_21->raise();
        line_2->raise();
        label_14->raise();
        label_4->raise();
        label_QF04->raise();
        line_5->raise();
        line_4->raise();
        label_12->raise();
        label_QF03->raise();
        label_11->raise();
        label_15->raise();
        label_QF01->raise();
        label_10->raise();
        line_dianWang->raise();
        label_3->raise();
        widget_battery->raise();
        label_2->raise();
        line_chuNeng->raise();
        label_QF05->raise();
        label_9->raise();
        label_5->raise();
        label_13->raise();
        line_fuZai->raise();
        label_18->raise();
        label_chuNeng->raise();
        label_exchange->raise();
        label_fuHe->raise();
        label_pv->raise();
        label->raise();
        label_pv_status->raise();
        label_GridStatus->raise();
        label_QF02->raise();
        line_guangFu->raise();
        label_arrow->raise();
        widget_dataShow = new QWidget(centralwidget);
        widget_dataShow->setObjectName(QString::fromUtf8("widget_dataShow"));
        widget_dataShow->setGeometry(QRect(350, 90, 731, 561));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 1081, 42));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        dateTimeEdit = new QDateTimeEdit(layoutWidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setFocusPolicy(Qt::NoFocus);
        dateTimeEdit->setStyleSheet(QString::fromUtf8("QDateTimeEdit {\n"
"    background-color: #1e2a38;  /* \346\267\261\350\223\235\347\201\260\350\211\262\350\203\214\346\231\257 */\n"
"    color: #ffffff;             /* \347\231\275\350\211\262\346\226\207\346\234\254 */\n"
"    border: 2px solid #4a90e2;  /* \344\272\256\350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"    border-radius: 10px;         /* \345\234\206\350\247\222\350\276\271\346\241\206 */\n"
"    padding: 5px 10px;          /* \345\206\205\350\276\271\350\267\235\357\274\214\345\242\236\345\212\240\345\217\257\350\247\206\350\210\222\351\200\202\345\272\246 */\n"
"    font-size: 16px;            /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    font-family: Arial, sans-serif; /* \345\255\227\344\275\223\351\200\211\346\213\251 */\n"
"    font-weight: bold;          /* \345\212\240\347\262\227\345\255\227\344\275\223 */\n"
"}\n"
"\n"
"QDateTimeEdit::up-button {\n"
"    subcontrol-origin: border;  /* \346\214\211\351\222\256\344\275\215\347\275\256\347\233\270\345\257\271\344"
                        "\272\216\350\276\271\346\241\206 */\n"
"    subcontrol-position: top right; /* \345\217\263\344\270\212\350\247\222 */\n"
"    width: 16px;                /* \346\214\211\351\222\256\345\256\275\345\272\246 */\n"
"    border-left:1px solid #4a90e2; /* \344\270\216\344\270\273\346\241\206\347\232\204\345\210\206\351\232\224\347\272\277 */\n"
"}\n"
"\n"
"QDateTimeEdit::down-button {\n"
"    subcontrol-origin: border;  /* \346\214\211\351\222\256\344\275\215\347\275\256\347\233\270\345\257\271\344\272\216\350\276\271\346\241\206 */\n"
"    subcontrol-position: bottom right; /* \345\217\263\344\270\213\350\247\222 */\n"
"    width: 16px;                /* \346\214\211\351\222\256\345\256\275\345\272\246 */\n"
"    border-left:1px solid #4a90e2; /* \344\270\216\344\270\273\346\241\206\347\232\204\345\210\206\351\232\224\347\272\277 */\n"
"}\n"
"\n"
"QDateTimeEdit::up-arrow {\n"
"    image: url(:/icon/images/upArrow.png);\n"
"    width: 10px;                /* \345\233\276\346\240\207\345\244\247\345\260\217 */\n"
""
                        "    height: 10px;\n"
"}\n"
"\n"
"QDateTimeEdit::down-arrow {\n"
"	image: url(:/icon/images/downArrow.png);\n"
"    width: 10px;                /* \345\233\276\346\240\207\345\244\247\345\260\217 */\n"
"    height: 10px;\n"
"}"));
        dateTimeEdit->setDateTime(QDateTime(QDate(2024, 8, 28), QTime(9, 0, 0)));

        horizontalLayout->addWidget(dateTimeEdit);

        btn_dataSel = new QPushButton(layoutWidget);
        btn_dataSel->setObjectName(QString::fromUtf8("btn_dataSel"));
        btn_dataSel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #1e2a38;  /* \346\267\261\350\223\235\347\201\260\350\211\262\350\203\214\346\231\257 */\n"
"    color: #ffffff;             /* \347\231\275\350\211\262\346\226\207\346\234\254 */\n"
"    border: 2px solid #4a90e2;  /* \344\272\256\350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"    border-radius: 10px;        /* \345\234\206\350\247\222\346\214\211\351\222\256 */\n"
"    padding: 10px 20px;         /* \345\242\236\345\212\240\345\206\205\350\276\271\350\267\235 */\n"
"    font-size: 16px;            /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    font-weight: bold;          /* \345\212\240\347\262\227\345\255\227\344\275\223 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a90e2;  /* \346\202\254\345\201\234\346\227\266\347\232\204\344\272\256\350\223\235\350\211\262\350\203\214\346\231\257 */\n"
"    border: 2px solid #ffffff;  /* \346\202\254\345\201\234\346\227\266\347\232\204\347\231\275\350\211\262\350\276\271\346\241\206 */\n"
""
                        "}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #0f1a24;  /* \346\214\211\344\270\213\346\227\266\347\232\204\346\267\261\350\211\262\350\203\214\346\231\257 */\n"
"    border: 2px solid #4a90e2;  /* \346\214\211\344\270\213\346\227\266\347\232\204\344\272\256\350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"}\n"
""));

        horizontalLayout->addWidget(btn_dataSel);

        btn_start = new QPushButton(layoutWidget);
        btn_start->setObjectName(QString::fromUtf8("btn_start"));
        btn_start->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #1e2a38;  /* \346\267\261\350\223\235\347\201\260\350\211\262\350\203\214\346\231\257 */\n"
"    color: #ffffff;             /* \347\231\275\350\211\262\346\226\207\346\234\254 */\n"
"    border: 2px solid #4a90e2;  /* \344\272\256\350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"    border-radius: 10px;        /* \345\234\206\350\247\222\346\214\211\351\222\256 */\n"
"    padding: 10px 20px;         /* \345\242\236\345\212\240\345\206\205\350\276\271\350\267\235 */\n"
"    font-size: 16px;            /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    font-weight: bold;          /* \345\212\240\347\262\227\345\255\227\344\275\223 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a90e2;  /* \346\202\254\345\201\234\346\227\266\347\232\204\344\272\256\350\223\235\350\211\262\350\203\214\346\231\257 */\n"
"    border: 2px solid #ffffff;  /* \346\202\254\345\201\234\346\227\266\347\232\204\347\231\275\350\211\262\350\276\271\346\241\206 */\n"
""
                        "}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #0f1a24;  /* \346\214\211\344\270\213\346\227\266\347\232\204\346\267\261\350\211\262\350\203\214\346\231\257 */\n"
"    border: 2px solid #4a90e2;  /* \346\214\211\344\270\213\346\227\266\347\232\204\344\272\256\350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"}\n"
""));

        horizontalLayout->addWidget(btn_start);

        btn_stop = new QPushButton(layoutWidget);
        btn_stop->setObjectName(QString::fromUtf8("btn_stop"));
        btn_stop->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #1e2a38;  /* \346\267\261\350\223\235\347\201\260\350\211\262\350\203\214\346\231\257 */\n"
"    color: #ffffff;             /* \347\231\275\350\211\262\346\226\207\346\234\254 */\n"
"    border: 2px solid #4a90e2;  /* \344\272\256\350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"    border-radius: 10px;        /* \345\234\206\350\247\222\346\214\211\351\222\256 */\n"
"    padding: 10px 20px;         /* \345\242\236\345\212\240\345\206\205\350\276\271\350\267\235 */\n"
"    font-size: 16px;            /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    font-weight: bold;          /* \345\212\240\347\262\227\345\255\227\344\275\223 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4a90e2;  /* \346\202\254\345\201\234\346\227\266\347\232\204\344\272\256\350\223\235\350\211\262\350\203\214\346\231\257 */\n"
"    border: 2px solid #ffffff;  /* \346\202\254\345\201\234\346\227\266\347\232\204\347\231\275\350\211\262\350\276\271\346\241\206 */\n"
""
                        "}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #0f1a24;  /* \346\214\211\344\270\213\346\227\266\347\232\204\346\267\261\350\211\262\350\203\214\346\231\257 */\n"
"    border: 2px solid #4a90e2;  /* \346\214\211\344\270\213\346\227\266\347\232\204\344\272\256\350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"}\n"
""));

        horizontalLayout->addWidget(btn_stop);

        comboBox = new QComboBox(layoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #1e2a38;  /* \346\267\261\350\223\235\347\201\260\350\211\262\350\203\214\346\231\257 */\n"
"    color: #ffffff;             /* \347\231\275\350\211\262\346\226\207\346\234\254 */\n"
"    border: 2px solid #4a90e2;  /* \344\272\256\350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"    border-radius: 10px;         /* \345\234\206\350\247\222\350\276\271\346\241\206 */\n"
"    padding: 5px 10px;          /* \345\206\205\350\276\271\350\267\235\357\274\214\345\242\236\345\212\240\345\217\257\350\247\206\350\210\222\351\200\202\345\272\246 */\n"
"    font-size: 16px;            /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    font-family: Arial, sans-serif; /* \345\255\227\344\275\223\351\200\211\346\213\251 */\n"
"    font-weight: bold;          /* \345\212\240\347\262\227\345\255\227\344\275\223 */\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #1e2a38;   /* \344\270\213\346\213\211\345\210\227\350\241\250\350\203\214\346\231\257\350"
                        "\211\262 */\n"
"    border: 1px solid #4a90e2;   /* \344\270\213\346\213\211\345\210\227\350\241\250\347\232\204\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    selection-background-color: #4a90e2; /* \351\200\211\344\270\255\347\232\204\351\241\271\347\233\256\350\203\214\346\231\257\350\211\262 */\n"
"    color: #ffffff;              /* \345\210\227\350\241\250\351\241\271\347\232\204\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;                 /* \344\270\213\346\213\211\346\214\211\351\222\256\345\256\275\345\272\246 */\n"
"    border-left: 1px solid #4a90e2;  /* \344\270\213\346\213\211\346\214\211\351\222\256\344\270\216\346\226\207\346\234\254\347\232\204\345\210\206\351\232\224\347\272\277 */\n"
"	\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/icon/images/downArrow.png);  /* \350\207\252\345\256\232\344\271\211\344\270\213\346\213\211\347\256"
                        "\255\345\244\264\345\233\276\346\240\207 */\n"
"    width: 12px;                 /* \345\233\276\346\240\207\345\256\275\345\272\246 */\n"
"    height: 12px;                /* \345\233\276\346\240\207\351\253\230\345\272\246 */\n"
"}\n"
""));

        horizontalLayout->addWidget(comboBox);

        label_timeShow_left = new QLabel(layoutWidget);
        label_timeShow_left->setObjectName(QString::fromUtf8("label_timeShow_left"));
        label_timeShow_left->setMaximumSize(QSize(138, 16777215));
        label_timeShow_left->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #1e2a38;  /* \346\267\261\350\223\235\347\201\260\350\211\262\350\203\214\346\231\257 */\n"
"    color: #ffffff;             /* \347\231\275\350\211\262\346\226\207\346\234\254 */\n"
"    border: 2px solid #4a90e2;  /* \344\272\256\350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"    border-radius: 10px;         /* \345\234\206\350\247\222\350\276\271\346\241\206 */\n"
"    padding: 5px 10px;          /* \345\206\205\350\276\271\350\267\235\357\274\214\345\242\236\345\212\240\345\217\257\350\247\206\350\210\222\351\200\202\345\272\246 */\n"
"    font-size: 16px;            /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    font-family: Arial, sans-serif; /* \345\255\227\344\275\223\351\200\211\346\213\251 */\n"
"    font-weight: bold;          /* \345\212\240\347\262\227\345\255\227\344\275\223 */\n"
"}\n"
""));

        horizontalLayout->addWidget(label_timeShow_left);

        label_timeShow = new QLabel(layoutWidget);
        label_timeShow->setObjectName(QString::fromUtf8("label_timeShow"));
        label_timeShow->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #1e2a38;  /* \346\267\261\350\223\235\347\201\260\350\211\262\350\203\214\346\231\257 */\n"
"    color: #ffffff;             /* \347\231\275\350\211\262\346\226\207\346\234\254 */\n"
"    border: 2px solid #4a90e2;  /* \344\272\256\350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"    border-radius: 10px;         /* \345\234\206\350\247\222\350\276\271\346\241\206 */\n"
"    padding: 5px 10px;          /* \345\206\205\350\276\271\350\267\235\357\274\214\345\242\236\345\212\240\345\217\257\350\247\206\350\210\222\351\200\202\345\272\246 */\n"
"    font-size: 16px;            /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    font-family: Arial, sans-serif; /* \345\255\227\344\275\223\351\200\211\346\213\251 */\n"
"    font-weight: bold;          /* \345\212\240\347\262\227\345\255\227\344\275\223 */\n"
"}\n"
""));

        horizontalLayout->addWidget(label_timeShow);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(400, 60, 81, 20));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 127);\n"
"font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_ceLue = new QLabel(centralwidget);
        label_ceLue->setObjectName(QString::fromUtf8("label_ceLue"));
        label_ceLue->setGeometry(QRect(510, 60, 571, 20));
        label_ceLue->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 127);\n"
"font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_ceLue->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\346\271\226\345\214\227\347\224\265\350\203\275\345\276\256\347\275\221\346\225\260\346\215\256\345\217\257\350\247\206\345\214\226\345\267\245\345\205\267", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "\351\205\215\347\224\265\347\275\221", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\345\205\211\344\274\2178MW", nullptr));
        label_4->setText(QString());
        label_QF04->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "QF04", nullptr));
        label_QF03->setText(QString());
        label_11->setText(QApplication::translate("MainWindow", "QF03", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "      \345\202\250\350\203\275            1MW/2MWh", nullptr));
        label_QF01->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "QF02", nullptr));
        label_3->setText(QString());
        label_2->setText(QString());
        label_QF05->setText(QString());
        label_QF02->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "QF01", nullptr));
        label_5->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "QF05", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "10kV", nullptr));
        label_chuNeng->setText(QApplication::translate("MainWindow", "0kW", nullptr));
        label_exchange->setText(QApplication::translate("MainWindow", "0kW", nullptr));
        label_fuHe->setText(QApplication::translate("MainWindow", "0kW", nullptr));
        label_pv->setText(QApplication::translate("MainWindow", "0kW", nullptr));
        label->setText(QApplication::translate("MainWindow", "\345\276\205\346\234\272", nullptr));
        label_pv_status->setText(QApplication::translate("MainWindow", "\345\276\205\346\234\272", nullptr));
        label_GridStatus->setText(QApplication::translate("MainWindow", "\345\276\205\346\234\272", nullptr));
        label_arrow->setText(QString());
        btn_dataSel->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\346\227\245\346\234\237\346\227\266\351\227\264", nullptr));
        btn_start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        btn_stop->setText(QApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "\346\255\243\345\270\270\346\250\241\345\274\217", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "\345\212\240\351\200\237\346\250\241\345\274\217", nullptr));

        label_timeShow_left->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\346\225\260\346\215\256\346\227\266\351\227\264\357\274\232", nullptr));
        label_timeShow->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\346\250\241\345\274\217\357\274\232", nullptr));
        label_ceLue->setText(QApplication::translate("MainWindow", "\346\227\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
