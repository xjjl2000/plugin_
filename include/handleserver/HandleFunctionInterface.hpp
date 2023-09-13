//
// Created by dirichlet on 23-9-12.
//
#ifndef RVIZPLUGIN_HANDLEFUNCTIONINTERFACE_H
#define RVIZPLUGIN_HANDLEFUNCTIONINTERFACE_H
#include<QObject>
#include "UI_rqt_push_button.h"

class HandleFunctionInterface:public QObject{
public:
    virtual void run(Ui::myWidget *ui,QByteArray* data){};


};

template<typename T>
class HandleFunctionInterfaceTemplate:public HandleFunctionInterface{
public:
    void run(Ui::myWidget *ui,QByteArray* data) override;
    virtual void show(Ui::myWidget *ui, T& data)=0;

};

template<typename T>
void HandleFunctionInterfaceTemplate<T>::run(Ui::myWidget *ui, QByteArray *data) {
    T t;
    QDataStream dataStream(data, QIODevice::ReadOnly);
    dataStream >> t;
    this->show(ui, t);
}


#endif //RVIZPLUGIN_HANDLEFUNCTIONINTERFACE_H
