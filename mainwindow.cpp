#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QGridLayout>
#include <QGraphicsProxyWidget>
#include <QGraphicsAnchorLayout>
#include <QGraphicsScene>
#include <QGraphicsAnchorLayout>
#include <QGraphicsView>
#include <QBrush>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //默认最大化
    this->setWindowState(Qt::WindowMaximized);
    //按钮组
    MainMenu* _ButtonGroup = new MainMenu(this->centralWidget());
//    QGraphicsProxyWidget* _ButtonGroup = new QGraphicsProxyWidget;
//    _ButtonGroup->setWidget(new MainMenu);
    _ButtonGroup->setGeometry(QRect(0, 60, 101, 361));
    //主界面
    MainView *_mainView = new MainView(this->centralWidget());
//    QGraphicsProxyWidget* _mainView = new QGraphicsProxyWidget;
//    _mainView->setWidget(new MainView);
    _mainView->setGeometry(QRect(100,60,700,600));
//    QGraphicsScene* scene = new QGraphicsScene;
//    scene->setSceneRect(-100,-100,800,400);
//    QGraphicsAnchorLayout* anchorLayout = new QGraphicsAnchorLayout;
//    QGraphicsWidget* w  = new QGraphicsWidget;
//    anchorLayout->addAnchor(_ButtonGroup,Qt::AnchorLeft,anchorLayout,Qt::AnchorLeft);
//    anchorLayout->addAnchor(_mainView,Qt::AnchorRight,anchorLayout,Qt::AnchorRight);
//    anchorLayout->addAnchor(_ButtonGroup,Qt::AnchorTop,_mainView,Qt::AnchorBottom);
//    anchorLayout->addAnchors(_ButtonGroup,_mainView,Qt::Vertical);
//    w->setLayout(anchorLayout);
//    scene->addItem(w);
//    scene->setBackgroundBrush(QBrush(QImage(":/BKG.bmp")));
//    QGraphicsView* view = new QGraphicsView(scene);
//    view->setParent(this->centralWidget());
//    view->show();
//    不要在主窗口创建布局
//    QGridLayout *_mainLayOut = new QGridLayout(this);
//    _mainLayOut->addWidget(_ButtonGroup,1,0);
//    _mainLayOut->addWidget(_mainView,1,1);
//    this->centralWidget()->setLayout(_mainLayOut);
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
