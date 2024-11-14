#pragma once
#include "curve3D.h"

class spiral : public curve3D
{
    point  startPoint;
    double radius;
    double step;
public:
    spiral() : startPoint(0.0, 0.0, 0.0), radius(0.0), step(0.0)
    {
        typeCyrve = SPIRAL;
    }
    spiral(const point& _center, const double& _radius, const double& _step) : startPoint(_center)
    {
        typeCyrve = SPIRAL;
        if (check_radius(_radius))
        {
            set_radius(_radius);
            set_step(_step);
        }
        else
        {
            set_radius(_radius * (-1.0));
            set_step(_step);
        }
    }
    spiral(const double& _x, const double& _y, const double& _z, const double& _radius, const double& _step) : startPoint(_x, _y, _z)
    {
        typeCyrve = SPIRAL;
        if (check_radius(_radius))
        {
            set_radius(_radius);
            set_step(_step);
        }
        else
        {
            set_radius(_radius * (-1.0));
            set_step(_step);
        }
    }
    ~spiral() {}

    double get_radius()
    {
        return radius;
    }

    void set_radius(const double& _radius)
    {
        radius = _radius;
        return;
    }
    double get_step()
    {
        return step;
    }

    void set_step(const double& _step)
    {
        step = _step;
        return;
    }

    point get_start_point()
    {
        return startPoint;
    }

    void print_curve()
    {
        cout << "spiral  " << " :  radius = " << radius << ",  " << "  step = " << step << ",  ";
        startPoint.print();
    }

    point get_coords(const double& t) override;
    point get_vector(const double& t) override;

};

