#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
    double x;
    double y;
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
    friend ostream &operator<<(ostream &os, const Point &p)
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};
class Circle : public Point
{
public:
    double radius;

    Circle(double x = 0.0, double y = 0.0, double r = 0.0) : Point(x, y), radius(r) {}

    friend ostream &operator<<(ostream &os, const Circle &c)
    {
        os << "圆心: " << static_cast<Point>(c) << ", 半径: " << c.radius << endl;
        return os;
    }
    bool operator>(const Circle &c) const
    {
        return radius > c.radius;
    }

    bool operator<(const Circle &c) const
    {
        return radius < c.radius;
    }

    bool operator>=(const Circle &c) const
    {
        return radius >= c.radius;
    }

    bool operator<=(const Circle &c) const
    {
        return radius <= c.radius;
    }

    bool operator==(const Circle &c) const
    {
        return radius == c.radius;
    }

    bool operator!=(const Circle &c) const
    {
        return radius != c.radius;
    }
};
int locate(const Point &p, const Circle &c)
{
    double dx = p.x - c.x;
    double dy = p.y - c.y;
    double d = sqrt(dx * dx + dy * dy);
    if (d < c.radius)
        return -1;
    if (d == c.radius)
        return 0;
    return 1;
}
int main()
{
    Circle c1(3, 2, 4), c2(4, 5, 5);     // c2 应该大于 c1
    Point p1(1, 1), p2(3, -2), p3(7, 3); // 分别位于 c1 内、上、外
    cout << "圆 c1: " << c1;
    cout << "点 p1: " << p1;
    cout << "点 p1 在圆 c1 之" << ((locate(p1, c1) > 0) ? "外" : ((locate(p1, c1) < 0) ? " 内" : "上")) << endl;
    cout << "点 p2: " << p2;
    cout << "点 p2 在圆 c1 之" << ((locate(p2, c1) > 0) ? "外" : ((locate(p2, c1) < 0) ? " 内" : "上")) << endl;
    cout << "点 p3: " << p3;
    cout << "点 p3 在圆 c1 之" << ((locate(p3, c1) > 0) ? "外" : ((locate(p3, c1) < 0) ? " 内" : "上")) << endl;
    cout << endl;
    cout << "圆 c1: " << c1;
    if (c1 > c2)
        cout << "大于" << endl;
    if (c1 < c2)
        cout << "小于" << endl;
    if (c1 >= c2)
        cout << "大于等于" << endl;
    if (c1 <= c2)
        cout << "小于等于" << endl;
    if (c1 == c2)
        cout << "等于" << endl;
    if (c1 != c2)
        cout << "不等于" << endl;
    cout << "圆 c2: " << c2;
    cout << endl;
    system("pause");
    return 0;
}