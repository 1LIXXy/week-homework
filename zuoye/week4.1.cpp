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
        //第一次测试
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
    cout << "楼房层数：" << CH1.floors << endl;
    cout << "房间数：" << CH1.rooms << endl;
    cout << "总面积：" << CH1.area << endl;
    cout << "卧室数：" << CH1.bedrooms << endl;
    cout << "浴室数：" << CH1.bathrooms << endl;
    Cofficbuilding CH2(5, 20, 5000, 10, 15);
    cout << "CH2" << endl;
    cout << "楼房层数：" << CH2.floors << endl;
    cout << "房间数：" << CH2.rooms << endl;
    cout << "总面积：" << CH2.area << endl;
    cout << "存储灭火器数：" << CH2.fireworks << endl;
    cout << "电话数：" << CH2.phones << endl;
    return 0;
}