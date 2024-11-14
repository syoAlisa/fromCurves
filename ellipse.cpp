#include "ellipse.h"

point ellipse::get_coords(const double& t)
{
    point pointOnT;
    pointOnT = get_center();

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

    double x = pointOnT.get_x() + get_major_semi_axis() * cosT;//cos(t);
    double y = pointOnT.get_y() + get_minor_semi_axis() * sinT;//sin(t);
 
    pointOnT.set_x(x);
    pointOnT.set_y(y);

    return pointOnT;
}

point ellipse::get_vector(const double& t)
{
    point pointOnT;

    pointOnT = get_coords(t);
    double x = pointOnT.get_x();
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
        y = (get_minor_semi_axis() / get_major_semi_axis())*(cosT / sinT);
    }
    pointOnT.set_x(x);
    pointOnT.set_y(y);

    return pointOnT;
}