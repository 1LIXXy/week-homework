#include <iostream>
using namespace std;

class Sales
{
public:
    Sales(int num, int quantity, double price)
    {
        this->num = num;
        this->quantity = quantity;
        this->price = price;
        m = quantity * price * discount;
        if (quantity >= 10)
            m *= 0.98;
        sum+=m;

        n += quantity;
    }

    static void average()
    {
        cout << "Average price: " << sum / n << endl;
    }

    static void display()
    {
        cout << "Total sales: " << sum << endl;
    }
    static double discount;
    int num;
    int quantity;
    double m;
    double price;
    static double sum;
    static int n;
};
double Sales::discount=1.0;
double Sales::sum = 0.0;
int Sales::n = 0;

int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int num, quantity;
        double price;
        cin >> num >> quantity >> price;
        Sales s(num, quantity, price);
    }
    cin >> Sales::discount;
    Sales::sum *= Sales::discount;
    Sales::display();
    Sales::average();
    return 0;
}