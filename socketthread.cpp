#include "socketthread.h"

SocketThread::SocketThread(QWidget* parent):QThread(parent)
{
    m_qstrIP="";
    m_iPort=0;
}
void SocketThread::setIP(QString IPAddress)
{
    m_qstrIP=IPAddress;
}

void SocketThread::setPort(int port)
{
    m_iPort=port;
}

void SocketThread::disconnectSocket()
{

}

void SocketThread::run()
{
    QTcpSocket* TCPclient=  new QTcpSocket(); //socket对象放在这里建立，不然会报不在一个线程的错误
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

        TCPclient->write("nihao");
        TCPclient->waitForBytesWritten(1000);
       if (TCPclient->waitForReadyRead(1000))
       {
           qDebug()<<"Ready to Read";           
           QByteArray arr = TCPclient->readAll();
 //          m_strReceiveDate.prepend(arr);
           m_strReceiveDate = QString(arr);
           qDebug()<<m_strReceiveDate;
           emit receiveDateDisplay(m_strReceiveDate);
       }
        this->sleep(1);
    }
}
