
#include<iostream>
#include<cstdlib>
 
using namespace std;
 
//交换数组元素位置位置
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
 
 
/*
插入排序。注意，若后面一个元素比其前面一个元素小，则将这两个元素交换位置，然后再来比较这个插入元素与前面一个元素的大小，若小，则还需要交换这两个元素位置，一直到这个插入元素在正确的位置为止
*/
void insertSort(int a[],  int length)
{
	for (int i = 1; i < length; i++)
	{
		for (int j = i - 1; j >= 0 && a[j + 1] < a[j]; j--)
		{
			swap(a[j], a[j + 1]);
		}
	}
 
}
 
int main()
{
	int a[] = { 2,1,4,5,3,8,7,9,0,6 };
 
	insertSort(a, 10);
 
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
 
	}
	cout << endl;
	return 0;
 
}