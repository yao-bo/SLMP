#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainMenu* _ButtonGroup = new MainMenu(ui->widget_mainMenu);
    MainView *_mainWindow = new MainView(ui->widget_MainView);
    connect(_ButtonGroup,SIGNAL(checkedId(int)),this,SLOT(id(int)));
    connect(_ButtonGroup,SIGNAL(checkedId(int)),_mainWindow,SLOT(viewSelect(int)));
}

MainWindow::~MainWindow()
{   
    delete ui;
}

void MainWindow::id(int id)
{
    ui->_buttonId->setText(QString::number(id));
}

