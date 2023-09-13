//
// Created by dirichlet on 23-9-12.
//

#ifndef RVIZPLUGIN_HANDLEFUNCTIONFACTORY_HPP
#define RVIZPLUGIN_HANDLEFUNCTIONFACTORY_HPP
#include "handleserver/HandleFunctionInterface.hpp"
class HandleFunctionFactory{
    private:
        HandleFunctionInterface* func= nullptr;
    public:
        HandleFunctionInterface* getHandleFunction(QString& topic);
        ~HandleFunctionFactory();
};


#endif //RVIZPLUGIN_HANDLEFUNCTIONFACTORY_HPP
