#include <iostream>
#include <algorithm>
using namespace std;
int a[200001];


inline int query(int l,int r,int x)
{// 5 6 7 8 9 10 11 //x=5
    int mid=(l+r)/2;
    if (a[mid]>x && a[mid-1]==x) return mid-1;
    if (a[mid]==x) return query(mid+1,r,x);
    return query(l,mid,x);
}

int main()
{
 ios::sync_with_stdio(false);
 cin.tie(0);  
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);

    int mid=(1+n)/2;
    while (k>0)
    {// 1 0 0 2 0 0 0 2
        int pos=mid;
        
       /* while (a[pos]==a[pos+1] && pos<n)
        { //找第一个比a[mid]大的数字
            pos++;
        }*/

        if (a[n]==a[mid]) pos=n;
            else pos=query(mid+1,n,a[mid]);
        
        if (pos==n)
        {
            int tmp=k/(pos-mid+1);
            cout<<a[mid]+tmp;
            return 0;
        }


        int tmp=min(k/(pos-mid+1),a[pos+1]-a[mid]);
        if (tmp==0) {cout<<a[mid]<<endl; return 0;}
        else {
            k=k-tmp*(pos-mid+1);
            for (int i=mid;i<=pos;i++)
            a[i]+=tmp;
        }
    }

    cout<<a[mid]<<endl;
    return 0;
}