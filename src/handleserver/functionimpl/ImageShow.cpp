//
// Created by dirichlet on 23-9-12.
//
#include "handleserver/HandleFunctionInterface.hpp"

class RosImageShow:public HandleFunctionInterfaceTemplate<QPixmap>{
    void show(Ui::myWidget *ui, QPixmap& data) override {
         ui->label_image->setPixmap(data);
    }

};