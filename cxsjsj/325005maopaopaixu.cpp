#include <bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
	int n;
	cin >> n;
	for (int i = 0;i < n;i ++)
	{
		cin >> a[i];//输入数组a  
	}
	for (int i = 0;i < n - 1;i ++)//如果有n个数，就要连续排序n - 1 次
	{
		for (int j = 0;j < n - 1 - i;j ++)//执行每一次比较的次数
		{
			if (a[j] > a[j + 1])//如果这个数比前面的大
			{
				swap(a[j],a[j + 1]);//把a[j] 和 a[j + 1] 进行交换
			}
		}
	}
	for (int i = 0;i < n;i ++)//数组输出
	{
		cout << a[i] << "\t";
	}
	cout << endl;
	return 0;
}