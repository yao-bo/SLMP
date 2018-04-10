#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //默认最大化
    this->setWindowState(Qt::WindowMaximized);
    //主按钮栏
    QWidget *widget_mainMenu = new QWidget(this->centralWidget());
    //主窗口
    QWidget *widget_MainView = new QWidget(this->centralWidget());
    widget_mainMenu->setObjectName(QStringLiteral("widget_mainMenu"));
    widget_mainMenu->setGeometry(QRect(0, 60, 101, 361));
    widget_MainView->setObjectName(QStringLiteral("widget_MainView"));
    widget_MainView->setGeometry(QRect(100, 60, 561, 391));
    //按钮组
    MainMenu* _ButtonGroup = new MainMenu(widget_mainMenu);
    //主界面
    MainView *_mainWindow = new MainView(widget_MainView);
    //按钮ID显示
    connect(_ButtonGroup,SIGNAL(checkedId(int)),this,SLOT(id(int)));
    //选择窗口
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

void MainWindow::paintEvent(QPaintEvent *)
{
    //绘制背景画面
    QPainter painter(this);
    QPixmap pixmap("BKG.bmp");
    painter.drawPixmap(0,0,this->size().width(),this->size().height(),pixmap);

}
