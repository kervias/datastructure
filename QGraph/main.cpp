#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString path = QApplication::applicationDirPath();
    path += "/icon.png";
    a.setWindowIcon(QIcon(path));
    MainWindow w;


    w.showMaximized();   //最大化显示

    return a.exec();
}
