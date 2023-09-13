#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include"udpserver/MyUpdServer.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class myWidget; }
QT_END_NAMESPACE

class myWidget : public QWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = nullptr);
    ~myWidget();

private:
    Ui::myWidget *ui;
    MyUpdServer *myUpdServer;


public slots:
    void hanleMessage();


};
#endif // MYWIDGET_H
