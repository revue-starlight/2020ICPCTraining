    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    const ll  N= 1e5+10;

    struct node{
        ll num_2,num_1,father;
    }f[N];
    ll F(ll x){return f[x].father==x?x:f[x].father=F(f[x].father);}
    ll a[N];

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll T,n;
        ll a1,a2;
        while(cin>>T){
        while (T--){
            cin>>n;
            a1=a2=0;
            for (ll i=1;i<=n;i++) f[i].father=i;
            for (ll i=1;i<=n;i++) {cin>>a[i]; if (a[i]==1) a1++,f[i].num_1=1,f[i].num_2=0; else a2++,f[i].num_2=1,f[i].num_1=0;}
            //cal sum
            ll sum=(a2*(a2-1)*(a2-2)/3/2)+((a2)*(a2-1)/2*a1);
            cout<<sum<<endl;
            for (ll i=1;i<n;i++){
                ll xx,yy;
                cin>>xx>>yy;
                xx=F(xx);
                yy=F(yy);
                if (xx!=yy){
                    f[xx].father=yy;
                    /*sum=sum-f[xx].num_2*f[yy].num_2*(a2-f[xx].num_2-f[yy].num_2);
                    sum=sum-f[xx].num_2*f[yy].num_1*(a2-f[xx].num_2-f[yy].num_2);
                    sum=sum-f[xx].num_1*f[yy].num_2*(a2-f[xx].num_2-f[yy].num_2);
                    sum=sum-f[xx].num_2*f[yy].num_2*(a1-f[xx].num_1-f[yy].num_1);*/
                    f[yy].num_1+=f[xx].num_1;
                    f[yy].num_2+=f[xx].num_2;
                //  if (sum<0) sum=0;
                sum=0;
                if (f[yy].num_2>0 && a2-f[yy].num_2>0 && a1-f[yy].num_1>0)
                    sum+=f[yy].num_2*(a2-f[yy].num_2)*(a1-f[yy].num_1);
                if ((f[yy].num_2 || f[yy].num_1) && (a2-f[yy].num_2>=2))
                    sum+=(f[yy].num_2+f[yy].num_1)*(a2-f[yy].num_2)*(a2-f[yy].num_2-1)/2;
                if (a2-f[yy].num_2>=2 && a1-f[yy].num_1>=1)
                    sum+=(a2-f[yy].num_2)*(a2-f[yy].num_2-1)/2*(a1-f[yy].num_1);
                if (a2-f[yy].num_2>=3)
                    sum+=(a2-f[yy].num_2)*(a2-f[yy].num_2-1)*(a2-f[yy].num_2-2)/3/2;
                }
                cout<<sum<<endl;
            }
        }
        }
    }