#include "point.h"

using namespace std;

void point::set_x(const double& _x)
{
    x = _x;
    return;
}
void point::set_y(const double& _y)
{
    y = _y;
    return;
}
void point::set_z(const double& _z)
{
    z = _z;
    return;
}

double point::get_x()
{
    return x;
}
double point::get_y()
{
    return y;
}
double point::get_z()
{
    return z;
}

void point::print()
{
    cout << "x = " << x << ",  y = " << y << ",  z = " << z << ";" << endl;
    return;
}
