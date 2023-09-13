//
// Created by dirichlet on 23-9-12.
//
#include "handleserver/HandleFunctionFactory.hpp"
#include "functionimpl/ImageShow.cpp"

HandleFunctionInterface* HandleFunctionFactory::getHandleFunction(QString& topic) {
    delete func;
    func= nullptr;
    if(topic=="img")
        func=new RosImageShow();


    return func;
}

HandleFunctionFactory::~HandleFunctionFactory() {
    delete func;
}

