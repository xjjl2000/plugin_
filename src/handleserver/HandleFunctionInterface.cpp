//
// Created by dirichlet on 23-9-12.
//
#include "handleserver/HandleFunctionInterface.hpp"

template<typename T>
void HandleFunctionInterfaceTemplate<T>::run(Ui::myWidget *ui, QByteArray *data) {
    T t;
    QDataStream dataStream(data, QIODevice::ReadOnly);
    dataStream >> t;
    this->show(ui, t);
}

template<>
class HandleFunctionInterfaceTemplate<QPixmap>;