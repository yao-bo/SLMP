#include "mainmenu.h"

MainMenu::MainMenu(QWidget *parent) : QWidget(parent)
{
    QButtonGroup* _buttonMenu =  new QButtonGroup(this);
    QPushButton* _overViewButton = new QPushButton(this);
    _overViewButton->setText(tr("设备一览"));
    _buttonMenu->addButton(_overViewButton);

}
