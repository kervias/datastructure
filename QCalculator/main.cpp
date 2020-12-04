#include "mainwindow.h"
#include <QApplication>
#include <string.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString path = QApplication::applicationDirPath();
    path += "/test.png";
    a.setWindowIcon(QIcon(path));
    MainWindow w;
    w.setWindowTitle("计算器");
    w.show();

    return a.exec();
}
