#include "point.hpp"

Point::Point()
{
    cout << "Initializing point" << endl;
    x = 0;
    y = 0;
}

void Point::SetX(int value)
{
    x = value;
}

void Point::SetY(int value)
{
    y = value;
}

void Point::SetXY(int v1, int v2)
{
    x = v1;
    y = v2;

    ShowInfo();
}

void Point::ShowInfo()
{
    cout << "x: " << x << " - y: " << y << endl;
}

int Point::GetX()
{
    return x;
}

int Point::GetY()
{
    return y;
}

/*void Point::GetXY(int &v1, int &v2)
{
    v1 = x;
    v2 = y;
}*/

void Point::GetXY(int *v1, int *v2)
{
    *v1 = x;
    *v2 = y;
}


