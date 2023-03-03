#include "point.h"
#include <iostream>
#include <cmath>
using namespace std;



point::point()
{
    X = 0;
    Y = 0;
}
point::point(float x, float y)
{
    X = x;
    Y = y;
}
void point::set_x(float x)
{
    X = x;
}
void point::set_y(float y)
{
    Y = y;
}
float point::get_x() const
{
    return X;
}
float point::get_y() const
{
    return y;
}
void point::display() const
{
    cout << "(" << X << ", " << Y << ")\n";
}
float point::distanceTo(const point &p) const
{
    float dx = X - p.X;
    float dy = Y - p.Y;
    float D = sqrt(pow(dx, 2) + pow(dy, 2));

    return D;
}