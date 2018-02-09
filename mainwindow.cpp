#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_Port->setText("8080");
    MainMenu* _ButtonGroup = new MainMenu(ui->widget_mainMenu);
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
//    connect(this->Socket,&Socket::finished,Socket,&QObject::deleteLater);
    connect(this->ui->Disconnect,SIGNAL(pressed()),Socket,SLOT(disconnectSocket()));
    connect(_ButtonGroup,SIGNAL(checkedId(int)),this,SLOT(id(int)));
}

MainWindow::~MainWindow()
{   
    Socket->quit();
    Socket->wait();
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
    QMessageBox::about(this,"提示","断开连接");
}

void MainWindow::id(int id)
{
    ui->_buttonId->setText(QString::number(id));
}



