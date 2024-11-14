#pragma once
#include <iostream>

using namespace std;

class point
{
    double x;
    double y;
    double z;
public:
    point() : x(0.0), y(0.0), z(0.0) {}
    point(const double& _x, const double& _y, const double& _z) : x(_x), y(_y), z(_z) {}
    point(const point& _point) : x(_point.x), y(_point.y), z(_point.z) {}
    ~point() {}

    void set_x(const double& _x);
    void set_y(const double& _y);
    void set_z(const double& _z);

    double get_x();
    double get_y();
    double get_z();

    void print();

};

