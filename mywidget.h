#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include<QtNetwork/QUdpSocket>

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
    QUdpSocket *updServer;

};
#endif // MYWIDGET_H
