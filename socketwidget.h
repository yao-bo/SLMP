#ifndef SOCKETWIDGET_H
#define SOCKETWIDGET_H

#include <QWidget>

namespace Ui {
class SocketWidget;
}

namespace SiasunLib {

}

class SocketWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SocketWidget(QWidget *parent = 0);
    ~SocketWidget();

private:
    Ui::SocketWidget *ui;
};

#endif // SOCKETWIDGET_H
