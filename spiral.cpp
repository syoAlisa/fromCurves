#include "spiral.h"

point spiral::get_coords(const double& t)
{
    point pointOnT;
    pointOnT = get_start_point();

    double sinT = sin(t);
    double cosT = cos(t);
    if ((cosT > deltaM) && (cosT < deltaP))
    {
        cosT = 0.0;
        sinT = 1.0;
    }
    else if ((sinT > deltaM) && (sinT < deltaP))
    {
        sinT = 0.0;
        cosT = 1.0;
    }

    double x = pointOnT.get_x() + get_radius() * cosT;// cos(t);
    double y = pointOnT.get_y() + get_radius() * sinT;// sin(t);
    double z = pointOnT.get_z() + get_step() *  (t / (2 * pi));
    pointOnT.set_x(x);
    pointOnT.set_y(y);
    pointOnT.set_z(z);

    return pointOnT;
}

point spiral::get_vector(const double& t)
{
    point pointOnT;
    pointOnT = get_start_point();

    double x = pointOnT.get_x();
    double z = pointOnT.get_z() + get_step() *  (t / (2 * pi));
    double y;
    double sinT = sin(t);
    double cosT = cos(t);
    if ((cosT > deltaM) && (cosT < deltaP))
    {
        y = 0;
    }
    else if ((sinT > deltaM) && (sinT < deltaP))
    {
        y = infinity;
    }
    else
    {
        y = cosT / sinT;
    }
    pointOnT.set_x(x);
    pointOnT.set_y(y);
    pointOnT.set_z(z);

    return pointOnT;
}