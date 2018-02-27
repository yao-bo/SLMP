#include "mainview.h"
#include <QStackedLayout>
#include <QVBoxLayout>
MainView::MainView(QWidget *parent) : QWidget(parent)
{    

    QPushButton *_Start = new QPushButton(tr("开始"),this);
    QPushButton *_Stop = new QPushButton(tr("停止"),this);
    QPushButton *_Pause = new QPushButton(tr("暂停"),this);
    QWidget *firstPage = new QWidget(this);
    firstPage->setStyleSheet("background-color:yellow;");
    firstPage->setGeometry(QRect(50,100,100,100));
    QPushButton *one = new QPushButton(tr("第一页"),firstPage);
    QVBoxLayout *mainLayout = new QVBoxLayout;
//    mainLayout->addLayout(stackedLayout);
//    mainLayout->addWidget(firstPage);
    mainLayout->addWidget(one);
    mainLayout->addWidget(_Start);
    mainLayout->addWidget(_Stop);
    mainLayout->addWidget(_Pause);
    firstPage->setLayout(mainLayout);

    QWidget *secondPage = new QWidget(this);
    QPushButton *two = new QPushButton(tr("第二页"),secondPage);
    secondPage->setStyleSheet("background-color:red;");
    secondPage->setGeometry(QRect(50,100,100,100));

    QWidget *thirdPage = new QWidget(this);
    QPushButton *three = new QPushButton(tr("第三页"),thirdPage);
    thirdPage->setStyleSheet("background-color:green;");
    thirdPage->setGeometry(QRect(50,100,100,100));

    QWidget *forthPage = new QWidget(this);
    QPushButton *four = new QPushButton(tr("第四页"),forthPage);
    forthPage->setStyleSheet("background-color:gray;");
    forthPage->setGeometry(QRect(50,100,100,100));

    SocketWidget *socketWidget =  new SocketWidget(this);


    stackedLayout = new QStackedLayout(this);
    stackedLayout->addWidget(socketWidget);
    stackedLayout->addWidget(firstPage);
    stackedLayout->addWidget(secondPage);
    stackedLayout->addWidget(thirdPage);
    stackedLayout->addWidget(forthPage);


}
void MainView::viewSelect(int id)
{

    stackedLayout->setCurrentIndex(id);
// //   _viewSelect->setText(QString::number(id));
//    _viewSelect->setText(QString::number(stackedLayout->currentIndex()));
}
