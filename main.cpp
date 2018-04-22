#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QStringList keyList = QStyleFactory::keys();
    foreach (QString i, keyList) {
       qDebug(i.toUtf8());
    }
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
