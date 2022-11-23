#include <iostream>

using namespace std;

class Point
{
//atributos - estado
private:
    int x, y;

//metodos
public:
    //construtores
    Point();

    //metodos acessores ou metodos de acesso
    //Get and Set
    void SetX(int value);
    void SetY(int value);
    void SetXY(int v1, int v2);
    void ShowInfo();

    int GetX();
    int GetY();
    //void GetXY(int &v1, int &v2);
    void GetXY(int *v1, int *v2);
};

