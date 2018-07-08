#ifndef TESTVIEW_H
#define TESTVIEW_H

#include <QWidget>
#include <QLineEdit>
#include <QGraphicsItem>
class TestView : public QWidget
{
    Q_OBJECT
public:
    explicit TestView(QWidget *parent = 0);
    ~TestView();
private:
    QLineEdit *timeDisplay;
    int a;
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void animate();
signals:

public slots:
};

class Item :public QGraphicsItem
{
public:
    Item();
    virtual ~Item();
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;
private:
//   void dragEnterEvent(QGraphicsSceneDragDropEvent *event) Q_DECL_OVERRIDE;
//   void dragMoveEvent(GraphicsSceneDragDropEvent *event) Q_DECL_OVERRIDE;
//   void dragLeaveEvent(GraphicsSceneDragDropEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QGraphicsSceneMouseEvent * event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event) Q_DECL_OVERRIDE;

};

#endif // TESTVIEW_H
