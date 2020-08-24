#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while (T--){
        int a[3][3];
        int tot=0;
        int ans=0;
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++) {cin>>a[i][j]; if (a[i][j]%2==1) tot++;}
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                bool bo=false;
                for (int i1=0;i1<3;i1++){
                    if (bo) break;
                    for (int j1=0;j1<3;j1++){
                        if (i1!=i && j1!=j){
                            int i2=3-i1-i;
                            int j2=3-j1-j;
                            int k=0;
                            for (int i3=0;i3<3;i3++)
                                for (int j3=0;j3<3;j3++){
                                    if ((i3!=i || j3!=j) && (i3!=i1 || j3!=j1) && (i3!=i2 || j3!=j2))
                                    k=k^(a[i3][j3]-1);
                                }
                            k^=a[i2][j2];
                            if (k==0) {
                                ans++;
                                bo=true;
                                break;
                            }
                        }
                    }
                }


            }
        }
        cout<<9-ans<<endl;
    }
}