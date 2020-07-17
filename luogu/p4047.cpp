#include <bits/stdc++.h>
using namespace std;
struct node{
    int i,w;
    node* nex;
};
int n;
node v[100010];

void build(int v1,int v2,int w)
{
    node *p,*ne;
    if (v[v1].i==0)
    {
        p=(node*)malloc(sizeof(node*));
        p->i=v2; p->nex=NULL; p->w=w;
        v[v1].i=v1;
        v[v1].w=0;
        v[v1].nex=p;
    }
    else{
        p=&v[v1];
        while (p->nex!=NULL && p->nex->w<w ) 
            p=p->nex;
        ne->i=v2; ne->w=w; ne->nex=p->nex;
        p->nex=ne;
    }
}

void write(int n)
{
    if (v[n].i==0) { cout<<n<<":NULL"<<endl; return;}
else {
    node *p;
    p=&v[n];
    int ans=0;
    while (p->nex!=NULL)
    {
        ans++;
        cout<<"num_"<<ans<<"(i:"<<p->i<<",w:"<<p->w<<") ";
        p=p->nex;
    }
    cout<<"num_"<<ans<<"(i:"<<p->i<<",w:"<<p->w<<") ";
    return;
}`

}


int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        build(x,y,w);
    }
    for (int i=1;i<=n;i++)
    write(i);
}