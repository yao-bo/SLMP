#ifndef SOCKETWIDGET_H
#define SOCKETWIDGET_H

#include <QWidget>
#include <QNetworkInterface>
#include "socketthread.h"

class SocketThread;

namespace Ui {
class SocketWidget;
}

namespace SiasunLib {

}

class SocketWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SocketWidget(QWidget *parent = 0);
    ~SocketWidget();

private:
    Ui::SocketWidget *ui;
    SocketThread* Socket;
private slots:
    void on_Disconnect_clicked();
    void on_Connect_clicked();
};

#endif // SOCKETWIDGET_H
