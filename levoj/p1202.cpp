#include <bits/stdc++.h>
using namespace std;
int main(){
    string str,substr;
    while (cin>>str>>substr){
        int xb=0,id;
        for (int i=0;i<str.length();i++)
            if (xb<str[i]) xb=str[i],id=i;
        str.insert(id+1,substr,0,substr.length());
        cout<<str<<endl;
    }
}