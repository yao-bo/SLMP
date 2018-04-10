#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QWidget>

namespace Ui {
class Background;
}

class Background : public QWidget
{
    Q_OBJECT

public:
    explicit Background(QWidget *parent = 0);
    ~Background();

private:
    Ui::Background *ui;
    void paintEvent(QPaintEvent *);
};

#endif // BACKGROUND_H
