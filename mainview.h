#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>
#include <QVector>

class MainView : public QWidget
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = 0);
private:
    QVector<QWidget> _view;

signals:

public slots:
    void eviewSelect(int id);
};
#endif // MAINVIEW_
