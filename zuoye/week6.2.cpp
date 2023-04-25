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
        os << "Բ��: " << static_cast<Point>(c) << ", �뾶: " << c.radius << endl;
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
    Circle c1(3, 2, 4), c2(4, 5, 5);     // c2 Ӧ�ô��� c1
    Point p1(1, 1), p2(3, -2), p3(7, 3); // �ֱ�λ�� c1 �ڡ��ϡ���
    cout << "Բ c1: " << c1;
    cout << "�� p1: " << p1;
    cout << "�� p1 ��Բ c1 ֮" << ((locate(p1, c1) > 0) ? "��" : ((locate(p1, c1) < 0) ? " ��" : "��")) << endl;
    cout << "�� p2: " << p2;
    cout << "�� p2 ��Բ c1 ֮" << ((locate(p2, c1) > 0) ? "��" : ((locate(p2, c1) < 0) ? " ��" : "��")) << endl;
    cout << "�� p3: " << p3;
    cout << "�� p3 ��Բ c1 ֮" << ((locate(p3, c1) > 0) ? "��" : ((locate(p3, c1) < 0) ? " ��" : "��")) << endl;
    cout << endl;
    cout << "Բ c1: " << c1;
    if (c1 > c2)
        cout << "����" << endl;
    if (c1 < c2)
        cout << "С��" << endl;
    if (c1 >= c2)
        cout << "���ڵ���" << endl;
    if (c1 <= c2)
        cout << "С�ڵ���" << endl;
    if (c1 == c2)
        cout << "����" << endl;
    if (c1 != c2)
        cout << "������" << endl;
    cout << "Բ c2: " << c2;
    cout << endl;
    system("pause");
    return 0;
}