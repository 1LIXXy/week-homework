#include <iostream>
#include <string>
using namespace std;

class Complex
{
public:
    double real;
    double imag;

    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    Complex operator+(const Complex &c) const{
        return Complex(real + c.real, imag + c.imag);
    }
    Complex operator-(const Complex &c) const{
        return Complex(real - c.real, imag - c.imag);
    }
    Complex operator*(const Complex &c) const{
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }
    Complex operator/(const Complex &c) const{
        double denominator = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / denominator,(imag * c.real - real * c.imag) / denominator);
    }
    friend istream &operator>>(istream &is, Complex &c){
        string s;
        is >> s;
        size_t pos = s.find("+");
        if (pos == string::npos)
            pos = s.find("-");
        if (pos == string::npos || pos == 0)
        {
            c.real = stod(s);
            c.imag = 0;
        }
        else
        {
            c.real = stod(s.substr(0, pos));
            if (s[pos + 1] == 'i')
            {
                c.imag = (s[pos] == '+' ? 1 : -1);
            }
            else
            {
                c.imag = stod(s.substr(pos));
            }
        }
        return is;
    }
    friend ostream &operator<<(ostream &os, const Complex &c)
    {
        os << c.real;
        if (c.imag >= 0)
            os << "+";
        os << c.imag << "i";
        return os;
    }
};
int main()
{
    Complex c1, c2, c3;
    cout << "c1: " << endl;
    cin >> c1;
    cout << "c2: " << endl;
    cin >> c2;
    cout << "c1=" << c1 << endl;
    cout << "c2=" << c2 << endl;
    c3 = c1 + c2;
    cout << "c1+c2=" << c3 << endl;
    c3 = c1 - c2;
    cout << "c1-c2=" << c3 << endl;
    c3 = c1 * c2;
    cout << "c1*c2=" << c3 << endl;
    c3 = c1 / c2;
    cout << "c1/c2=" << c3 << endl;
    return 0;
}