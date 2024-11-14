#pragma once
#include "curve3D.h"

class circle : public curve3D
{
    point  center;
    double radius;

public:
    circle() : center(0.0, 0.0, 0.0), radius(0.0)
    {
        typeCyrve = CIRCLE;
    }
    circle(const point& _center, const double& _radius) : center(_center)
    {
        typeCyrve = CIRCLE;
        if (check_radius(_radius))
        {
            set_radius(_radius);
        }
        else
        {
            set_radius(_radius*(-1.0));
        }
    }
    circle(const double& _x, const double& _y, const double& _z, const double& _radius) : center(_x, _y, _z)
    {
        typeCyrve = CIRCLE;
        if (check_radius(_radius))
        {
            set_radius(_radius);
        }
        else
        {
            set_radius(_radius * (-1.0));
        }
    }
    ~circle() {}

    double get_radius()
    {
        return radius;
    }

    void set_radius(const double& _radius)
    {
        radius = _radius;
        return ;
    }

    point get_center()
    {
        return center;
    }
    
    void print_curve()
    {
        cout << "circle  " << " :  radius = " << radius << ",  ";
        center.print();
    }

    point get_coords(const double& t) override;
    point get_vector(const double& t) override;
};

