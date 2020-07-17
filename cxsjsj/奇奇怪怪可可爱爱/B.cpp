//构造函数和析构函数
#include <iostream>
using namespace std;
class Base{
    public:
    Base(){cout<<"Base"<<endl;}
    ~Base(){cout<<"DesBase"<<endl;}
};
class Base1:public Base{
    public:
    Base1(){cout<<"Base1"<<endl;}
    ~Base1(){cout<<"DesBase1"<<endl;}
};
class Base2:public Base{
    public:
    Base2():b(),b1(){cout<<"Base2"<<endl;}
    ~Base2(){cout<<"DesBase2"<<endl;}
    private:
    Base1 b1;
    Base b;
};

int main(){
    Base2 k;
    return 0;
}