#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication a(argc, argv);


    MainWindow w;
    w.setStyleSheet("background-image: url(:/icon/images/background.png);background-repeat: no-repeat; background-position: center;");
    w.setWindowFlags(w.windowFlags()& ~Qt::WindowMaximizeButtonHint);//禁止方法按钮
    w.setFixedSize(w.width(),w.height());//固定大小
    w.show();
    return a.exec();
}
