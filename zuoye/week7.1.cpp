#include <iostream>
#include <cstring>
using namespace std;

class String
{
public:
    String(const char *str = "")
    {
        len = strlen(str);
        p = new char[len + 1];
        strcpy(p, str);
    }
    String(const String &s)
    {
        len = s.len;
        p = new char[len + 1];
        strcpy(p, s.p);
    }
    ~String()
    {
        delete[] p;
    }
    String operator+(const String &s) const
    {
        char *temp = new char[len + s.len + 1];
        strcpy(temp, p);
        strcat(temp, s.p);
        String result(temp);
        delete[] temp;
        return result;
    }

    String operator-(const String &s) const
    {
        int i = len - 1;
        while (i >= 0 && p[i] == ' ')
            i--;
        int j = 0;
        while (j < s.len && s.p[j] == ' ')
            j++;
        char *temp = new char[i + s.len - j + 2];
        strncpy(temp, p, i + 1);
        temp[i + 1] = '\0';
        strcat(temp, s.p + j);
        String result(temp);
        delete[] temp;
        return result;
    }
    friend ostream &operator<<(ostream &os, const String &s)
    {
        os << s.p;
        return os;
    }

private:
    char *p;
    int len;
};

int main()
{
    String s1("Hello ");
    String s2(" C++");
    cout << s1 + s2 << endl;
    cout << s1 - s2 << endl;
    return 0;
}