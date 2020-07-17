#include <bits/stdc++.h>
using namespace std;
const string zm[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
const string sz[]={".----","..---","...--","....-",".....","-....","--...","---..","----.","-----"};
int main()
{
    string s;
    while (cin>>s){
        int len=s.length();
        for (int i=0;i<len-1;i++){
            if (isdigit(s[i])) cout<<sz[s[i]-'0']<<"===";
            else{
                if (s[i]<'a') cout<<zm[s[i]-'A']<<"===";
                else cout<<zm[s[i]-'a']<<"===";
            }
        }


        if (isdigit(s[len-1])) cout<<sz[s[len-1]-'0']<<endl;
            else{
                if (s[len-1]<'a') cout<<zm[s[len-1]-'A']<<endl;
                else cout<<zm[s[len-1]-'a']<<endl;
            }
    }
}