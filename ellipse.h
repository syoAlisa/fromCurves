#pragma once
#include "curve3D.h"

class ellipse : public curve3D
{
    point  center;
    double majorSemiAxis;
    double minorSemiAxis;

public:
    ellipse() : center(0.0, 0.0, 0.0), majorSemiAxis(0.0), minorSemiAxis(0.0)
    {
        typeCyrve = ELLIPSE;
    }
    ellipse(const point& _center, const double& _majorSemiAxis, const double& _minorSemiAxis) : center(_center)
    {
        typeCyrve = ELLIPSE;
        if (check_radius(_majorSemiAxis))
        {
            set_major_semi_axis(_majorSemiAxis);
        }
        else
        {
            set_major_semi_axis(_majorSemiAxis * (-1.0));
        }

        if (check_radius(_minorSemiAxis))
        {
            set_minor_semi_axis( _minorSemiAxis);
        }
        else
        {
            set_minor_semi_axis(_minorSemiAxis * (-1.0));
        }
    }
    ellipse(const double& _x, const double& _y, const double& _z, const double& _majorSemiAxis, const double& _minorSemiAxis) : center(_x, _y, _z)
    {
        typeCyrve = ELLIPSE;
        if (check_radius(_majorSemiAxis))
        {
            set_major_semi_axis(_majorSemiAxis);
        }
        else
        {
            set_major_semi_axis(_majorSemiAxis * (-1.0));
        }

        if (check_radius(_minorSemiAxis))
        {
            set_minor_semi_axis(_minorSemiAxis);
        }
        else
        {
            set_minor_semi_axis(_minorSemiAxis * (-1.0));
        }
    }
    ~ellipse() {}

    double get_major_semi_axis()
    {
        return majorSemiAxis;
    }

    void set_major_semi_axis(const double& _majorSemiAxis)
    {
        majorSemiAxis = _majorSemiAxis;
        return;
    }
    double get_minor_semi_axis()
    {
        return minorSemiAxis;
    }

    void set_minor_semi_axis(const double& _minorSemiAxis)
    {
        minorSemiAxis = _minorSemiAxis;
        return;
    }

    point get_center()
    {
        return center;
    }

    void print_curve()
    {
        cout << "ellipse  " << " :  majorSemiAxis = " << majorSemiAxis << ",  " << "   minorSemiAxis = " << minorSemiAxis << ", ";
        center.print();
    }

    point get_coords(const double& t) override;
    point get_vector(const double& t) override;
};

