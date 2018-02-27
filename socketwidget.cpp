#include "socketwidget.h"
#include "ui_socketwidget.h"

SocketWidget::SocketWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SocketWidget)
{
    ui->setupUi(this);

    Socket =  new SocketThread(this);
    QList<QHostAddress> addressList = QNetworkInterface::allAddresses();
    foreach(QHostAddress i,addressList)
    {
        if (i.protocol() == QAbstractSocket::IPv4Protocol)
        ui->comboBox->addItem(i.toString());
    }
    connect(this->ui->Disconnect,SIGNAL(pressed()),Socket,SLOT(disconnectSocket()));
    connect(this->Socket,SIGNAL(receiveDateDisplay(QString)),ui->textBrowser_ReceiveText,SLOT(append(QString)));
}

SocketWidget::~SocketWidget()
{
    Socket->quit();
    Socket->wait();
    delete ui;
}


void SocketWidget::on_Connect_clicked()
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

void SocketWidget::on_Disconnect_clicked()
{
    QMessageBox::about(this,"提示","断开连接");
}
