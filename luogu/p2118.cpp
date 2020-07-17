include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
    double fs;
}a[5000];

int aa,bb,x,tot;

bool cmp(const node &x,const node &y) {return x.fs<y.fs;}
int gcd(int a,int b)
{
    if (b==0) return a; else return gcd(b,a%b);
}
int main()
{
    cin>>aa>>bb>>x;
    a[++tot].x=1; a[tot].y=1; a[tot].fs=1;
    for (int i=2;i<=x;i++)
    {
        for (int j=1;j<i;j++)
            if (gcd(i,j)==1){
                a[++tot].fs=(double)j/i; a[tot].x=j; a[tot].y=i;
            }
    }
    sort(a+1,a+1+tot,cmp);
    bool bo=false;
    if (aa>bb) {swap(aa,bb); bo=true;}
    double check=(double)aa/bb;
    a[0].fs=0;
    int l=0,r=tot;
    while (l+1<r)
    {
        int mid=(l+r)/2;
        if (a[mid].fs<check) l=mid; else r=mid; 
    }
    if (l==0) {
        if (bo) cout<<a[1].y<<" "<<a[1].x;
        else cout<<a[1].x<<" "<<a[1].y;
    }
    else {
        if (check-a[l].fs>a[r].fs-check) l=r;
        if (bo) cout<<a[l].y<<" "<<a[l].x;
        else cout<<a[l].x<<" "<<a[l].y;
    }

    return 0;
}