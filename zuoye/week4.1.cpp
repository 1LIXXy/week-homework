#include<iostream>
using namespace std;
class Cbuilding{
    public:
    int floors;
    int rooms;
    int area;
    Cbuilding(int floors,int rooms,int area){
        this->floors=floors;
        this->rooms=rooms;
        this->area=area;
        //��һ�β���
    }

};
class CHousing:public Cbuilding{
    public:
    int bedrooms;
    int bathrooms;
    CHousing(int floors,int rooms,int area,int bedrooms,int bathrooms):Cbuilding(floors,rooms,area){
        this->bedrooms=bedrooms;
        this->bathrooms=bathrooms;
    }
};
class Cofficbuilding:public  Cbuilding{
    public:
    int fireworks;
    int phones;
    Cofficbuilding(int floors,int rooms,int area,int fireworks,int phones):Cbuilding(floors,rooms,area){
        this->fireworks=fireworks;
        this->phones=phones;
    }
};


int main(){
    CHousing CH1(3, 10, 2000, 4, 3);
    cout << "¥��������" << CH1.floors << endl;
    cout << "��������" << CH1.rooms << endl;
    cout << "�������" << CH1.area << endl;
    cout << "��������" << CH1.bedrooms << endl;
    cout << "ԡ������" << CH1.bathrooms << endl;
    Cofficbuilding CH2(5, 20, 5000, 10, 15);
    cout << "CH2" << endl;
    cout << "¥��������" << CH2.floors << endl;
    cout << "��������" << CH2.rooms << endl;
    cout << "�������" << CH2.area << endl;
    cout << "�洢���������" << CH2.fireworks << endl;
    cout << "�绰����" << CH2.phones << endl;
    return 0;
}