#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    this->socket = new QTcpSocket(this);
    Socket =  new SocketThread(this);
    QList<QHostAddress> addressList = QNetworkInterface::allAddresses();
    foreach(QHostAddress i,addressList)
    {
        if (i.protocol() == QAbstractSocket::IPv4Protocol)
        ui->comboBox->addItem(i.toString());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Connect_clicked()
{

    QString IP;
    int port;
    IP = ui->lineEdit_IP->text();
    port = ui->lineEdit_Port->text().toInt();
    Socket->setIP(IP);
    Socket->setPort(port);
    Socket->start();
//    socket->abort();
//    this->socket->connectToHost(IP,port);
//    if (socket->waitForConnected(1000))
//    {
//        QMessageBox::about(this,"提示","连接成功");
//        connect(this->socket,SIGNAL(readyRead()),this,SLOT(readyread()));
//    }
//    else
//    {
//     QMessageBox::about(this,"提示","连接失败");
//     return;
//    }
}

void MainWindow::on_Disconnect_clicked()
{
//    this->socket->close();
    QMessageBox::about(this,"提示","断开连接");
}

void MainWindow::readyread()
{
    qDebug()<<"nihao";
    QMessageBox::about(this,"提示","准备读取");
//    QByteArray arr = this->socket->readAll();
//    QDataStream* dst = new QDataStream(&arr,QIODevice::ReadOnly);
//    QString str1,str2;
//    (*dst)>>str1>>str2;
//    this->ui->textBrowser->setText(str1+str2);
}




