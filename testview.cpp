#include "testview.h"
#include <QPushButton>
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
TestView::TestView(QWidget *parent) : QWidget(parent)
{
    Item *Item1 = new Item;
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addItem(Item1);
    QGraphicsView *view = new QGraphicsView(scene,this);
    view->setGeometry(50,50,300,300);
    view->setRenderHint(QPainter::Antialiasing);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setBackgroundBrush(QColor(230, 200, 167));
    view->setWindowTitle("Drag and Drop Robot");
    view->show();
    QPushButton *three = new QPushButton(tr("第三页"),this);
    setStyleSheet("background-color:green;");
    setGeometry(QRect(50,100,100,100));
    //    QTimer *time = new QTimer(this); //通过QTimer对象启动定时器
     //   connect(time,SIGNAL(timeout()),this,SLOT(animate()));
    //    time->start(100)
    QObject::startTimer(100);//通过全局函数，调用TImerEvent
    timeDisplay = new QLineEdit(this);
    timeDisplay->setGeometry(0,50,50,50);

}

TestView::~TestView()
{

}

void TestView::animate()
{
    a=a+1;
    if (a>100) a=0;
    timeDisplay->setText(QString::number(a));
//    qDebug()<<"animate";
    update();
}

void TestView::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    update();
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.save();
    QLinearGradient linearGradient(500,0,600, 600);
    linearGradient.setColorAt(0.0, Qt::white);
    linearGradient.setColorAt(0.2, Qt::green);
    linearGradient.setColorAt(1.0, Qt::black);
    painter.setBrush(linearGradient);
    painter.setPen(QPen(Qt::red,5));
    painter.drawEllipse(QRectF(500+a, a,100, 100));
    painter.restore();
    painter.end();
}

void TestView::timerEvent(QTimerEvent *t)
{
    animate();
}

Item::Item()
{
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}

Item::~Item()
{

}

QRectF Item::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawImage(QRectF(0,0,50,100),QImage(":/Conveyor.BMP"));//:/滚筒线.Bmp:/BKG.bmp

}

void Item::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

}
void Item::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(Qt::ClosedHandCursor);
}
void Item::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(Qt::OpenHandCursor);
}
