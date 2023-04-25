#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

class Person
{
public:
    string name;
    int age;
    string gender;
    string address;
    string phone;
};
class Teacher : public Person
{
public:
    string title;

    void display()
    {
        cout << "姓名:" << name << endl;
        cout << "年龄:" << age << endl;
        cout << "性别:" << gender << endl;
        cout << "职称:" << title << endl;
        cout << "地址:" << address << endl;
        cout << "电话:" << phone << endl;
    }
};

class Cadre : public Person
{
public:
    string post;
};

class Teacher_Cadre : public Teacher, public Cadre
{
public:
    double wages;

    void show()
    {
        Teacher::display();
        cout << "职务:" << Cadre::post << endl;
        cout << "工资:" << wages << endl;
    }
};
int main()
{
    Teacher_Cadre tc;
    getline(cin, tc.Teacher::name);
    cin >> tc.Teacher::age;

    while (tc.Teacher::age < 0)
    {
        cout << "年龄不能低于0,请重新输入" << endl;
        cin >> tc.Teacher::age;
    }

    cin >> tc.Teacher::gender;

    while (tc.Teacher::gender != "man" && tc.Teacher::gender != "woman")
    {
        cout << "性别输入错误，请重新输入" << endl;
        cin >> tc.Teacher::gender;
    }
    cin >> tc.Teacher::title;
    int i = 0;
    for (i = 0; i < (tc.Teacher::title).size(); i++)
    {
        if (tc.Teacher::title[i] == '.')
        {
            break;
        }
    }
    string m = (tc.Teacher::title);
    int k = (tc.Teacher::title.size());
    tc.Teacher::title = m.substr(0, i);
    tc.Cadre::post = m.substr(i + 1, k);

    getchar();
    getline(cin, tc.Teacher::address);
    getline(cin, tc.Teacher::phone);

    cin >> tc.wages;

    tc.show();

    return 0;
}