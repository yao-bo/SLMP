#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QString>
#include <QDataStream>
#include <QByteArray>
#include <QHostAddress>
#include <QMessageBox>
#include <QComboBox>
#include <QTextEdit>
#include <QNetworkInterface>
#include <QDebug>
#include <QTextBrowser>
#include "mainmenu.h"
#include "mainview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
private slots:
    void id(int id);
};

#endif // MAINWINDOW_H
