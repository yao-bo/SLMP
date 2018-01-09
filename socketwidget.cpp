#include "socketwidget.h"
#include "ui_socketwidget.h"

SocketWidget::SocketWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SocketWidget)
{
    ui->setupUi(this);
}

SocketWidget::~SocketWidget()
{
    delete ui;
}
