//12. 下列关于静态数据成员的描述中正确的是（） 
//A. 静态数据成员是类的所有对象所共有的 
//B. 静态数据成员要在构造函数内初始化 
//C. 类的每个对象有自己的静态数据成员 
//D. 静态数据成员不能通过类的对象调用 
#include<iostream>
using namespace std;
class Base1{
    private:
    int st1,st2;
    static int st;
    public:
    Base1(int i=4,int j=4){st1=i; st2=j;}
    ~Base1();
    static void work(Base1 a);
};
int Base1::st=0;
void Base1::work(Base1 a){
    a.st1++;
    st++;
    cout<<"st="<<st<<endl;
}

int main(){
    Base1 a(3,4);
    Base1::work(a);
}