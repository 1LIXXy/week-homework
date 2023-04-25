
#include <iostream>
using namespace std;

class SavingsAccount
{
private:
    int id;
    double balance;
    double rate;
    int lastDate;
    double accumulation;

    void record(int date, double amount)
    {
        accumulation = accumulate(date);
        lastDate = date;
        balance += amount;
    }

    double accumulate(int date) const
    {
        return accumulation + balance * (date - lastDate);
    }

public:
    SavingsAccount(int id, double rate) : id(id), balance(0), rate(rate), lastDate(0), accumulation(0) {}

    void show() const
    {
        cout << "ÕËºÅ: " << id << ", Óà¶î: " << balance << endl;
    }

    void deposit(int date, double amount)
    {
        record(date, amount);
    }

    bool withdraw(int date, double amount)
    {
        if (amount > balance)
        {
            cout << "Óà¶î²»×ã" << endl;
            return false;
        }
        else
        {
            record(date, -amount);
            return true;
        }
    }

    void settle(int date)
    {
        double interest = accumulate(date) * rate / 365;
        record(date, interest);
        accumulation = 0;
    }
};

int main()
{
    SavingsAccount s0(0, 0.015);
    SavingsAccount s1(1, 0.015);

    s0.deposit(5, 5000);
    s0.deposit(45, 5500);
    s1.deposit(25, 10000);
    s1.withdraw(60, 4000);

    s0.settle(90);
    s1.settle(90);

    s0.show();
    s1.show();

    return 0;
}