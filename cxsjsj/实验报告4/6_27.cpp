#include <bits/stdc++.h>
using namespace std;
class empcyqe{
    private:
    string name,address,city,num;
    public:
    empcyqe(string a,string b,string c,string d){name=a; address=b; city=c; num=d;}
    void setname(){
        cout<<"NAME NEW NAMe:";
        cin>>name;
    }
    void display(){
        cout<<"name:"<<name<<endl<<"address:"<<address<<endl<<"city:"<<city<<endl<<"num:"<<num<<endl;
    }
    
};
int main(){
    empcyqe a("cyq","nuist","nanjing","123444");
    a.display();
    a.setname();
    a.display();
}