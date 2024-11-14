#pragma once

#include <iostream>
#include < math.h >
#include <limits>
#include <string>

#include "point.h"

using namespace std;

const int CIRCLE  = 1;
const int ELLIPSE = 2;
const int SPIRAL  = 3;

const double pi       = 3.14159265358979;
const double deltaP   = 0.00000000000001;
const double deltaM   = -0.00000000000001;
const double infinity = numeric_limits<double>::infinity();

class curve3D
{
public:

    int typeCyrve;

    curve3D()  : typeCyrve(0) {}
    ~curve3D() {}


    virtual void print_curve()
    {
        cout << "curve3D" << endl;
        return;
    }

    virtual point get_coords(const double& t)
    {
        return point();
    }

    virtual point get_vector(const double& t)
    {
        return point();
    }

    virtual  bool check_radius(const double& _radius)
    {
        return (_radius < 0) ? false : true;
    }

    virtual  int get_type_curve()
    {
        return typeCyrve;
    }

    virtual  void print_type_curve()
    {
        switch (typeCyrve)
        {
            case CIRCLE:
            {
                cout << "typeCyrve : circle" << endl;
                break;
            }
            case ELLIPSE:
            {
                cout << "typeCyrve : ellipse" << endl;
                break;
            }
            case SPIRAL:
            {
                cout << "typeCyrve : spiral" << endl;
                break;
            }
            default:
            {
                cout << "this type does not exist" << endl;
                break;
            }
        }
        return ;
    }

};


