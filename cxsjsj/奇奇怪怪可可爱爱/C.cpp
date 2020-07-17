//虚函数与多态
#include <iostream>
using namespace std;
class Base{
    public:
    //你把virtual删掉试试看
    virtual void display() {cout<<"Base"<<endl;}
};

class Base1:public Base{
    public:
    void display(){cout<<"Base1"<<endl;}
};

class Base2:public Base1{
    public:
    void display(){cout<<"Base2"<<endl;}
};

void work(Base *ptr){
    ptr->display();
}
int main(){
    Base b;
    Base1 b1;
    Base2 b2;
    work(&b);
    work(&b1);
    work(&b2);
    return 0;
}
