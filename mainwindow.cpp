#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ReceiveText =  new QTextBrowser(this);
    ReceiveText->setGeometry(200,160,231,151);
    Socket =  new SocketThread(this);
    QList<QHostAddress> addressList = QNetworkInterface::allAddresses();
    foreach(QHostAddress i,addressList)
    {
        if (i.protocol() == QAbstractSocket::IPv4Protocol)
        ui->comboBox->addItem(i.toString());
    }
    connect(this->Socket,SIGNAL(receiveDateDisplay(QString)),this->ReceiveText,SLOT(append(QString)));
}

MainWindow::~MainWindow()
{
//    Socket->wait();
    Socket->quit();
    delete ui;
}

void MainWindow::on_Connect_clicked()
{

    QString IP;
    int port;
//    IP = ui->lineEdit_IP->text();
    IP = ui->comboBox->currentText();
    port = ui->lineEdit_Port->text().toInt();
    Socket->setIP(IP);
    Socket->setPort(port);
    Socket->start();
}

void MainWindow::on_Disconnect_clicked()
{
//    this->socket->close();
    QMessageBox::about(this,"提示","断开连接");
}





