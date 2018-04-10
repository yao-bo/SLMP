#include "background.h"
#include "ui_background.h"
#include <QPainter>
#include <QPixmap>
#include <QPicture>
#include <QDebug>
Background::Background(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Background)
{
    ui->setupUi(this);
}

Background::~Background()
{
    delete ui;
}

void Background::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pixmap("BKG.bmp");
    painter.drawPixmap(0,0,300,300,pixmap);

}
