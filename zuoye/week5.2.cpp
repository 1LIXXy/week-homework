#include<iostream>
#include <string>
#include <cmath>
using namespace std;

class Comparison
{
public:
    int Compare(int a, int b)
    {
        return (a > b) ? a : b;
    }
    int Compare(char a, char b)
    {
        return abs(a - b);
    }
    string Compare(string a, string b)
    {
        return (a.length() > b.length()) ? a : b;
    }
};

int main()
{
    Comparison comp;

    cout << comp.Compare(20, 25) << endl;
    cout << comp.Compare('A', 'C') << endl;
    cout << comp.Compare("Hello", "World!") << endl;

    return 0;
}