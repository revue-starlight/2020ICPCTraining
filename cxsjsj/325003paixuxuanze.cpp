#include <bits/stdc++.h>
using namespace std;
int main(){
    srand(time(NULL));
    int a[11];
    for (int i=0;i<10;i++) a[i]=rand()%100+1;
    for (int i=1;i<10;i++) cout<<a[i]<<" ";
    cout<<endl;
    //sort(a,a+10);
    for(int i = 0; i<9 ;++i){		//每次循环将第i小的元素放好 
		int tmpMin = i;  //用来记录从第i个到第n-1个元素中,最小的那个元素的下标 
		for(int j=i; j<10;++j){
			if(a[j]<a[tmpMin])
				tmpMin = j;
		}
	//下面将第i小的元素放在第i个位置上,并将原来占着第i个位置的那个元素挪到后面
		int tmp = a[i];
		a[i] = a[tmpMin];
		a[tmpMin] = tmp; 
	}
    for (int i=1;i<10;i++) cout<<a[i]<<" ";
    cout<<endl;
}