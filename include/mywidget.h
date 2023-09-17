#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include"udpserver/MyUpdServer.hpp"
#include "pcl/visualization/pcl_visualizer.h"

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
    pcl::visualization::PCLVisualizer::Ptr view;


public slots:
    void hanleMessage();


};
#endif // MYWIDGET_H
