#include <iostream>

using namespace std;

int count = 0;   
void perm(char A[], int start, int end)
{
    if (start == end)
    {
        for (int i = 0;i <= end; i++)
            cout << A[i];
        cout << endl;
        count++;
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            swap(A[i],A[start]);
            perm(A, start + 1, end);
            swap(A[i], A[start]);
        }
    }
}
int main()
{
    char A[10]={"123456789"};
    int n;
	while (cin>>n) 
    perm(A,0,n-1);  
    return 0;
}