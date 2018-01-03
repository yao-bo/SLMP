#include "socketthread.h"

SocketThread::SocketThread(QWidget* parent):QThread(parent)
{
    TCPclient =  new QTcpSocket(parent);
}
void SocketThread::setIP(QString IPAddress)
{
    m_qstrIP=IPAddress;
}

void SocketThread::setPort(int port)
{
    m_iPort=port;
}

void SocketThread::run()
{

    TCPclient->abort();
    TCPclient->connectToHost(m_qstrIP,m_iPort);
    if (TCPclient->waitForConnected(1000))
    {
        qDebug()<<"连接成功";
    }
    else
    {
        qDebug()<<"连接失败";
        return;
    }

    while (true) {

        ;
        this->sleep(1);
    }
}
