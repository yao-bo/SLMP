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
#include "socketthread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTextBrowser* ReceiveText;
private:
    Ui::MainWindow *ui;
    SocketThread* Socket;

private slots:
    void on_Disconnect_clicked();
    void on_Connect_clicked();
};

#endif // MAINWINDOW_H
