//
// Created by dirichlet on 23-9-12.
//
#include "handleserver/HandleFunctionFactory.hpp"
#include "functionimpl/ImageShow.cpp"
#include "functionimpl/PointCloudShow.cpp"

HandleFunctionInterface* HandleFunctionFactory::getHandleFunction(QString& topic) {
    delete func;
    func= nullptr;
    if(topic=="rosimg")
        func=new RosImageShow();
    else if(topic=="point")
        func=new PointCloudPCLShow(view);




    return func;
}

HandleFunctionFactory::~HandleFunctionFactory() {
    delete func;
}



