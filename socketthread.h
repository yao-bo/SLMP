#ifndef SOCKETTHREAD_H
#define SOCKETTHREAD_H
#include <QThread>
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>

class SocketThread : public QThread
{
    Q_OBJECT
public:
    explicit SocketThread(QWidget* parent = 0);
    void setIP(QString IPAddress);
    void setPort(int port);
protected:
    void run();
private:
    QString m_qstrIP;
    int m_iPort;
    QTcpSocket* TCPclient;
};

#endif // SOCKETTHREAD_H
