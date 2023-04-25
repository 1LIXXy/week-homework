#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979323846;

class CSolid
{
public:
    virtual double GetSurfaceArea() = 0;
    virtual double GetVolume() = 0;
};

class CCube : public CSolid
{
public:
    CCube(double side) : side(side) {}
    double GetSurfaceArea() { return 6 * side * side; }
    double GetVolume() { return side * side * side; }

private:
    double side;
};

class CBall : public CSolid
{
public:
    CBall(double radius) : radius(radius) {}
    double GetSurfaceArea() {
        return 4 * PI * radius * radius;
    }
    double GetVolume() { 
        return (4.0 / 3.0) * PI * pow(radius, 3);
    }

private:
    double radius;
};

class CCylinder : public CSolid
{
public:
    CCylinder(double radius, double height) : radius(radius), height(height) {}
    double GetSurfaceArea() { 
        return 2 * PI * radius * (radius + height);
    }
    double GetVolume() {
        return PI * pow(radius, 2) * height;
    }

private:
    double radius;
    double height;
};

int main(){
    CCylinder  a(2,2);
    CBall b(2);
    CCube c(2);
    CSolid *p;
    p = &c;
    cout << "正方体表面积：" << p->GetSurfaceArea() << "，体积：" << p->GetVolume() << endl;

    p = &b;
    cout << "球体表面积：" << p->GetSurfaceArea() << "，体积：" << p->GetVolume() << endl;

    p = &a;
    cout << "圆柱体表面积：" << p->GetSurfaceArea() << "，体积：" << p->GetVolume() << endl;

    return 0;
}
