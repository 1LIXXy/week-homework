#include <iostream>
using namespace std;
class person
{
    int id;
    string name;

public:
    person(string name, int id)
    {
        this->id = id;
        this->name = name;
    };
    ~person(){};
    void display()
    {
        cout << name << endl;
        cout << id << endl;
    };
};

class college : public person
{
    double score;
    string major;

public:
    college(string name, int id, double a, string c) : person(name, id)
    {
        score = a;
        major = c;
    };

    ~college(){};
    void display()
    {
        person::display();
        cout << score << endl;
        cout << major << endl;
    }
};

int main()
{
    college cstu1("ÕÅÈý", 20221414, 97, "cs");
    cstu1.display();
    return 0;
}