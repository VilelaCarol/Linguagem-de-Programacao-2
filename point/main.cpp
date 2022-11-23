#include "point.hpp"

using namespace std;

int main()
{
    Point p1;
    Point p2;
    Point p3;

    p1.SetX(10);
    p1.SetY(10);
    p2.SetXY(20,20);
    p3.SetXY(30,30);

    //p1.ShowInfo();
    //p2.ShowInfo();
    //p3.ShowInfo();

    cout << "P1 -> x: " << p1.GetX() << " y: " << p1.GetY() << endl;
    cout << "P2 -> x: " << p2.GetX() << " y: " << p2.GetY() << endl;
    cout << "P3 -> x: " << p3.GetX() << " y: " << p3.GetY() << endl;

    int x, y;
    p1.GetXY(&x, &y);

    return 0;
}
