#include <iostream>
using namespace std;
class person{
    public:
    virtual void print()=0;
};
class student:public person{
    public:
    void print(){cout<<"Person"<<endl;} 
};
class teacher:public person{
    public:
    void print(){cout<<"Teacher"<<endl;}
};

int main(){
    person *ptr[5];
    ptr[0]=new teacher;
    ptr[1]=new teacher;
    ptr[2]=new student;
    ptr[3]=new student;
    for (int i=0;i<4;i++){
        ptr[i]->print();
    }
}