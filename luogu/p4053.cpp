/*
抢修建筑，策略：修掉尽可能多的建筑。
T>150000故无法dp。
贪心，堆维护？
先排序。按照ddl长短修好每一个应该搞掉的东西。
如果超ddl了，找一个用时最长的就让已经修好的建筑爆破它，给新建筑续命;)。
如果那个自爆可以续上这个的话，就是 t-q.top()+a[i].cost<a[i].limit;
就续命啊，这样可以省点时间续下一个。
这样可以保证修的都是时间最短的。
*/
#include <iostream>
using namespace std;
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
}