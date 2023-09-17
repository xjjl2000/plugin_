//
// Created by dirichlet on 23-9-16.
//

#ifndef RVIZPLUGIN_MYPOINT_HPP
#define RVIZPLUGIN_MYPOINT_HPP
#include "QObject"
#include "QVector"

#include <QObject>
#include <QVector>
#include <QDataStream>

class MyPoint{
public:
    MyPoint(const MyPoint  &point) {
        x=point.x;
        y=point.y;
        z=point.z;

    }
    MyPoint& operator=(const MyPoint& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    float x = 0,y=0,z=0;

    MyPoint() = default;
    MyPoint(MyPoint&&) = default;
    MyPoint& operator=(MyPoint&&) = default;

    friend QDataStream &operator<<(QDataStream &out, const MyPoint &point)
    {
        out << point.x << point.y << point.z;
        return out;
    }

    friend QDataStream &operator>>(QDataStream &in, MyPoint &point)
    {
        in >> point.x >> point.y >> point.z;
        return in;
    }
};





#endif //RVIZPLUGIN_MYPOINT_HPP
