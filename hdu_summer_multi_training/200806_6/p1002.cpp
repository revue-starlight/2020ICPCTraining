#include <bits/stdc++.h>
using namespace std;
#define ll long long
map <char,ll> mp;
map <ll,char> mpp;
string add(string s,string t,ll x){
    ll len1=s.length();
    ll len2=t.length();
    ll a[100],b[100],c[100];
    ll len=max(len1,len2);
    for (ll i=0;i<=len;i++) a[i]=b[i]=c[i]=0;
    for (ll i=0;i<len1;i++) a[i]=mp[s[len1-i-1]];
    for (ll i=0;i<len2;i++) b[i]=mp[t[len2-i-1]];
    for (ll i=0;i<len;i++) {
        c[i]=a[i]+b[i]+c[i];
        if (c[i]/x>0) c[i+1]++;
        c[i]=c[i]%x;
    }
    string ans="";
    if (c[len]>0) len++;
    for (ll i=len-1;i>=0;i--) ans=ans+mpp[c[i]];
    return ans;
}

string mul(string s,string t,ll x){
    ll len1=s.length();
    ll len2=t.length();
    ll a[100],b[100],c[100];
    if (s=="0" || t=="0") return "0";
    for (ll i=0;i<100;i++) a[i]=b[i]=c[i]=0;
    for (ll i=0;i<len1;i++) a[i]=mp[s[len1-1-i]];
    for (ll i=0;i<len2;i++) b[i]=mp[t[len2-1-i]];
    for (ll i=0;i<len1;i++)
        for (ll j=0;j<len2;j++){
            c[i+j]+=a[i]*b[j];
        }
    for (ll i=0;i<=len1+len2;i++)
    {
        c[i+1]+=(c[i]/x);
        c[i]%=x;
    }
    string ans="";
    ll tmp=len1+len2-2;
    if (c[tmp+1]!=0) tmp++;
    for (ll i=tmp;i>=0;i--) ans+=mpp[c[i]];
    return ans;
}


int main(){
    mp['0']=0; mpp[0]='0';
    mp['1']=1; mpp[1]='1';
    mp['2']=2; mpp[2]='2';
    mp['3']=3;mpp[3]='3';
    mp['4']=4;mpp[4]='4';
    mp['5']=5;mpp[5]='5';
    mp['6']=6;mpp[6]='6';
    mp['7']=7;mpp[7]='7';
    mp['8']=8;mpp[8]='8';
    mp['9']=9;mpp[9]='9';
    mp['A']=10;mpp[10]='A';
    mp['B']=11;mpp[11]='B';
    mp['C']=12;mpp[12]='C';
    mp['D']=13;mpp[13]='D';
    mp['E']=14;mpp[14]='E';
    mp['F']=15;mpp[15]='F';
    string equ;
    while (cin>>equ){
        ll len=equ.length();
        string a,b,c;
        ll zuixiaojinzhi=2;
        ll i=0;
        while (equ[i]=='0') i++;
        while (equ[i]!='+' && equ[i]!='-' && equ[i]!='*' && equ[i]!='/') {a+=equ[i]; if (zuixiaojinzhi<=mp[equ[i]]) zuixiaojinzhi=mp[equ[i]]+1; i++;}
        char ysf=equ[i]; i++;
        while (equ[i]=='0') i++;
        while (equ[i]!='=') {b+=equ[i]; if (zuixiaojinzhi<=mp[equ[i]]) zuixiaojinzhi=mp[equ[i]]+1; i++;}
        i++;
        while (equ[i]=='0') i++;
        while (i<len){
            c+=equ[i]; i++;
        }
        if (a=="") a="0";
        if (b=="") b="0";
        if (c=="") c="0";
        //cout<<a<<endl<<b<<endl<<c<<endl<<ysf<<endl;
        bool bo=true;
        if (ysf=='+'){
            for (ll jz=zuixiaojinzhi;jz<=16;jz++)
            if (add(a,b,jz)==c){
                cout<<jz<<endl;
                bo=false;
                break;
            } 
        }
        else if (ysf=='-'){
            for (ll jz=zuixiaojinzhi;jz<=16;jz++)
            if (add(b,c,jz)==a){
                cout<<jz<<endl;
                bo=false;
                break;
            } 
        }
        else if (ysf=='*'){
            for (ll jz=zuixiaojinzhi;jz<=16;jz++)
            if (mul(a,b,jz)==c){
                cout<<jz<<endl;
                bo=false;
                break;
            } 
        }
        else if (ysf=='/'){
            for (ll jz=zuixiaojinzhi;jz<=16;jz++)
            if (mul(c,b,jz)==a){
                cout<<jz<<endl;
                bo=false;
                break;
            } 
        }
        if (bo) cout<<-1<<endl;
    }
}