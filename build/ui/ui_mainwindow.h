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
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

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
    QLabel *label_19;
    QFrame *line_5;
    QFrame *line_4;
    QLabel *label_12;
    QLabel *label_8;
    QLabel *label_11;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_10;
    QFrame *line_dianWang;
    QLabel *label_3;
    QWidget *widget_battery;
    QLabel *label_2;
    QFrame *line_chuNeng;
    QLabel *label_20;
    QLabel *label_17;
    QLabel *label_9;
    QLabel *label_5;
    QLabel *label_13;
    QFrame *line_fuZai;
    QLabel *label_18;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QWidget *widget_dataShow;
    QPushButton *btn_start;
    QPushButton *btn_stop;
    QComboBox *comboBox;
    QPushButton *pushButton_3;
    QDateTimeEdit *dateTimeEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1106, 614);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 90, 341, 481));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
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
        line_guangFu->setGeometry(QRect(170, 280, 20, 111));
        line_guangFu->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        line_guangFu->setFrameShadow(QFrame::Plain);
        line_guangFu->setLineWidth(4);
        line_guangFu->setMidLineWidth(0);
        line_guangFu->setFrameShape(QFrame::VLine);
        label_14 = new QLabel(frame);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(150, 430, 71, 31));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(154, 390, 51, 41));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/icon/images/guangFu.png")));
        label_4->setScaledContents(true);
        label_19 = new QLabel(frame);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(171, 310, 16, 31));
        label_19->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        line_5 = new QFrame(frame);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(150, 271, 141, 16));
        line_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        line_5->setFrameShadow(QFrame::Plain);
        line_5->setLineWidth(4);
        line_5->setFrameShape(QFrame::HLine);
        line_4 = new QFrame(frame);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(210, 180, 20, 101));
        line_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        line_4->setFrameShadow(QFrame::Plain);
        line_4->setLineWidth(4);
        line_4->setMidLineWidth(0);
        line_4->setFrameShape(QFrame::VLine);
        label_12 = new QLabel(frame);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(190, 310, 71, 31));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(212, 220, 16, 31));
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        label_11 = new QLabel(frame);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(230, 220, 71, 31));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_15 = new QLabel(frame);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(223, 420, 101, 61));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_15->setWordWrap(true);
        label_16 = new QLabel(frame);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(121, 110, 16, 31));
        label_16->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        label_10 = new QLabel(frame);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(50, 240, 71, 31));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        line_dianWang = new QFrame(frame);
        line_dianWang->setObjectName(QString::fromUtf8("line_dianWang"));
        line_dianWang->setGeometry(QRect(120, 70, 20, 111));
        line_dianWang->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
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
        widget_battery->setGeometry(QRect(290, 390, 41, 61));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 10, 71, 61));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/icon/images/dianWang.png")));
        label_2->setScaledContents(true);
        line_chuNeng = new QFrame(frame);
        line_chuNeng->setObjectName(QString::fromUtf8("line_chuNeng"));
        line_chuNeng->setGeometry(QRect(250, 280, 20, 111));
        line_chuNeng->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        line_chuNeng->setFrameShadow(QFrame::Plain);
        line_chuNeng->setLineWidth(4);
        line_chuNeng->setMidLineWidth(0);
        line_chuNeng->setFrameShape(QFrame::VLine);
        label_20 = new QLabel(frame);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(251, 310, 16, 31));
        label_20->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        label_17 = new QLabel(frame);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(31, 240, 16, 31));
        label_17->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(140, 110, 71, 31));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(240, 390, 41, 41));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/icon/images/chuNeng.png")));
        label_5->setScaledContents(true);
        label_13 = new QLabel(frame);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(270, 310, 71, 31));
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
        label_18->setGeometry(QRect(0, 150, 71, 31));
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"color: rgb(255, 0, 0);\n"
"font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, 360, 54, 12));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(100, 390, 54, 12));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(100, 410, 54, 12));
        label_22 = new QLabel(frame);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(60, 100, 54, 12));
        label_23 = new QLabel(frame);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(60, 120, 54, 12));
        label_24 = new QLabel(frame);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(20, 380, 54, 12));
        label_25 = new QLabel(frame);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(20, 400, 54, 12));
        widget_dataShow = new QWidget(centralwidget);
        widget_dataShow->setObjectName(QString::fromUtf8("widget_dataShow"));
        widget_dataShow->setGeometry(QRect(350, 90, 731, 471));
        btn_start = new QPushButton(centralwidget);
        btn_start->setObjectName(QString::fromUtf8("btn_start"));
        btn_start->setGeometry(QRect(420, 30, 75, 23));
        btn_stop = new QPushButton(centralwidget);
        btn_stop->setObjectName(QString::fromUtf8("btn_stop"));
        btn_stop->setGeometry(QRect(530, 30, 75, 23));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(640, 30, 81, 22));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(280, 30, 101, 23));
        dateTimeEdit = new QDateTimeEdit(centralwidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(80, 30, 194, 22));
        dateTimeEdit->setDateTime(QDateTime(QDate(2024, 8, 28), QTime(9, 0, 0)));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1106, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "\351\205\215\347\224\265\347\275\221", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\345\205\211\344\274\2178MW", nullptr));
        label_4->setText(QString());
        label_19->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "QF04", nullptr));
        label_8->setText(QString());
        label_11->setText(QApplication::translate("MainWindow", "QF03", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "      \345\202\250\350\203\275            1MW/2MWh", nullptr));
        label_16->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "QF02", nullptr));
        label_3->setText(QString());
        label_2->setText(QString());
        label_20->setText(QString());
        label_17->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "QF01", nullptr));
        label_5->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "QF05", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "10kV", nullptr));
        label->setText(QApplication::translate("MainWindow", "\345\202\250\350\203\275\345\212\237\347\216\207", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\345\205\211\344\274\217\345\207\272\345\212\233", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\345\212\237\347\216\207\346\230\276\347\244\272", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "\347\224\265\347\275\221\345\212\237\347\216\207", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "\345\212\237\347\216\207\346\230\276\347\244\272", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "\350\264\237\350\215\267\345\212\237\347\216\207", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "\345\212\237\347\216\207\346\230\276\347\244\272", nullptr));
        btn_start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        btn_stop->setText(QApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "\346\255\243\345\270\270\346\250\241\345\274\217", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "\345\212\240\351\200\237\346\250\241\345\274\217", nullptr));

        pushButton_3->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\346\227\245\346\234\237\346\227\266\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
