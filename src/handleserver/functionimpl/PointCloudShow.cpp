//
// Created by dirichlet on 23-9-16.
//

#include <pcl/visualization/pcl_visualizer.h>
#include "handleserver/HandleFunctionInterface.hpp"
#include "handleserver/MyPoint.hpp"
#include "pcl/pcl_base.h"
#include "pcl/point_types.h"

class PointCloudPCLShow : public HandleFunctionInterfaceTemplate<QVector<MyPoint> > {
private:
    pcl::visualization::PCLVisualizer::Ptr view;
    void show(Ui::myWidget *ui, QVector<MyPoint> &data) override {
        //testpcl

        view->removeAllPointClouds();

        //auto start = std::chrono::high_resolution_clock::now();

        pcl::PointCloud<pcl::PointXYZRGB>::Ptr point_cloud_ptr(new pcl::PointCloud<pcl::PointXYZRGB>);
        uint8_t r(120), g(120), b(120);
        view->addCoordinateSystem(1.0);
        std::cout<<"data size:"<<data.size()<<'\n';
        for (int i = 0; i < data.size(); ++i) {
            pcl::PointXYZRGB point;
            MyPoint t=data.at(i);
            if(std::isinf(t.x) ||std::isinf(t.y) ||std::isinf(t.z))
            	continue;
            
            point.x = t.x;
            point.y = t.y;
            point.z = t.z;
            
            
            std::cout<<"point.x :"<<point.x<<"point.y :"<<point.y<<"point.z :"<<point.z <<'\n';
            uint32_t rgb = (static_cast<uint32_t>(r) << 16 |
                            static_cast<uint32_t>(g) << 8 | static_cast<uint32_t>(b));
            point.rgb = *reinterpret_cast<float *>(&rgb);
            point_cloud_ptr->points.push_back(point);
        }

        point_cloud_ptr->width = (int) point_cloud_ptr->points.size();
        point_cloud_ptr->height = 1;

        view->addPointCloud(point_cloud_ptr, "cloud");
        view->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE,3, "cloud");
        ui->qvtkWidget->update();
//        auto end = std::chrono::high_resolution_clock::now();
//        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);



    }
    QVector<MyPoint> parse(Ui::myWidget *ui,QByteArray* data) override{
        QByteArray tp= qUncompress(*data);
        QVector<MyPoint> t;
        QDataStream dataStream(&tp, QIODevice::ReadOnly);
        dataStream >> t;
        return t;
    }

public:
    PointCloudPCLShow(pcl::visualization::PCLVisualizer::Ptr view):view(view){};

};
