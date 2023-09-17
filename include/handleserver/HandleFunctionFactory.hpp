//
// Created by dirichlet on 23-9-12.
//

#ifndef RVIZPLUGIN_HANDLEFUNCTIONFACTORY_HPP
#define RVIZPLUGIN_HANDLEFUNCTIONFACTORY_HPP
#include "handleserver/HandleFunctionInterface.hpp"
#include "pcl/visualization/pcl_visualizer.h"
class HandleFunctionFactory{
    private:
        HandleFunctionInterface* func= nullptr;
        pcl::visualization::PCLVisualizer::Ptr view= nullptr;

public:
        HandleFunctionInterface* getHandleFunction(QString& topic);
        HandleFunctionFactory(pcl::visualization::PCLVisualizer::Ptr view):view(view){};
        ~HandleFunctionFactory();
};


#endif //RVIZPLUGIN_HANDLEFUNCTIONFACTORY_HPP
