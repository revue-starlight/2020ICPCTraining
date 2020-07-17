#include <iostream>
using namespace std;
int main()
{
    int a,n;
    while(scanf("%d",&n)!=EOF)
    {
        while (n--){
            scanf("%d",&a);
            printf("%o\n",a);
        }
    }
    return 0;
}