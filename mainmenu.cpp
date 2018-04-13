#include "mainmenu.h"
#include <QPixmap>
#include <QIcon>
MainMenu::MainMenu(QWidget *parent) : QWidget(parent)
{
    QPixmap *_buttonBKG = new QPixmap(":/Button.jpg");
    QIcon *_buttonIcon = new QIcon(*_buttonBKG);
    QButtonGroup *_buttonMenu =  new QButtonGroup(this);
    QPushButton *_overViewButton = new QPushButton(*_buttonIcon,tr("设备一览"),this);
    _overViewButton->setFixedSize(80,40);
    QPushButton *_alarmButton = new QPushButton(tr("报警"),this);
    _alarmButton->setFixedSize(80,40);
    QPushButton *_manual = new QPushButton(tr("手动"),this);
    _manual->setFixedSize(80,40);
    QPushButton *_logIn = new QPushButton(tr("登录"),this);
    _logIn->setFixedSize(80,40);
    QVBoxLayout *_vbox = new QVBoxLayout;
    _vbox->addWidget(_overViewButton);
    _vbox->addWidget(_alarmButton);
    _vbox->addWidget(_manual);
    _vbox->addWidget(_logIn);
    _vbox->addStretch(1);
    this->setLayout(_vbox);
    _buttonMenu->addButton(_overViewButton,0);
    _buttonMenu->addButton(_alarmButton,1);
    _buttonMenu->addButton(_manual,2);
    _buttonMenu->addButton(_logIn,3);
    connect(_buttonMenu,SIGNAL(buttonClicked(int)),this,SLOT(getId(int)));
}
void MainMenu::getId(int id)
{
    emit this->checkedId(id);
}
