#include "mainmenu.h"

MainMenu::MainMenu(QWidget *parent) : QWidget(parent)
{
    QButtonGroup *_buttonMenu =  new QButtonGroup(this);
    QPushButton *_overViewButton = new QPushButton(tr("设备一览"),this);
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
    _buttonMenu->addButton(_overViewButton,1);
    _buttonMenu->addButton(_alarmButton,2);
    _buttonMenu->addButton(_manual,3);
    _buttonMenu->addButton(_logIn,4);
    connect(_buttonMenu,SIGNAL(buttonClicked(int)),this,SLOT(getId(int)));
}
void MainMenu::getId(int id)
{
    emit this->checkedId(id);
}
