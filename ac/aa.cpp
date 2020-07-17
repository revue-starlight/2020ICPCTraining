#include<iostream>

using namespace std;

int main( )

{      int a[4][4]={ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}, sum=0;

        int (*p)[4]=a;                           //A

        p=p+2;

        for( int i=0; i<2; i++)

                for(int j=0; j<2; j++)

                         sum+=p[i][j];          //B

        cout<<sum<<endl;

}
