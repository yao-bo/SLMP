 #ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>
#include <QVector>
#include <QPushButton>
#include <QLineEdit>
#include <QStackedLayout>
#include "socketwidget.h"

class SocketWidget;


class MainView : public QWidget
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = 0);
private:
    QLineEdit *_viewSelect;
    QStackedLayout *stackedLayout;
signals:

public slots:
    void viewSelect(int id);
};
#endif // MAINVIEW_
