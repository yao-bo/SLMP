#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QGridLayout>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //默认最大化
    this->setWindowState(Qt::WindowMaximized);
    //按钮组
    MainMenu* _ButtonGroup = new MainMenu(this->centralWidget());
    _ButtonGroup->setGeometry(QRect(0, 60, 101, 361));
    //主界面
    MainView *_mainView = new MainView(this->centralWidget());
    _mainView->setGeometry(100,60,700,600);
    //布局
    QGridLayout *_mainLayOut = new QGridLayout(this);
    _mainLayOut->addWidget(_ButtonGroup,1,0);
    _mainLayOut->addWidget(_mainView,1,1);
    this->centralWidget()->setLayout(_mainLayOut);
    //按钮ID显示
    connect(_ButtonGroup,SIGNAL(checkedId(int)),this,SLOT(id(int)));
    //选择窗口
    connect(_ButtonGroup,SIGNAL(checkedId(int)),_mainView,SLOT(viewSelect(int)));
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
    QPixmap pixmap(":/BKG.bmp");
    painter.drawPixmap(0,0,this->size().width(),this->size().height(),pixmap);

}
