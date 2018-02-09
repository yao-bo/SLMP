#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QButtonGroup>
#include <QPushButton>
#include <QVBoxLayout>
class MainMenu : public QWidget
{
    Q_OBJECT
public:
    explicit MainMenu(QWidget *parent = 0);

signals:
    void checkedId(int id);
public slots:
    void getId(int id);
};

#endif // MAINMENU_H
