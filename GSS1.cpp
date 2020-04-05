#include<bits/stdc++.h>
#define pc putchar_unlocked
#define gc getchar_unlocked
#define MAX 50005
#define INF 1000000
using namespace std;
inline int read()
{
	int x=0,neg=0;
	register int c=gc();
	for(;((c<48 || c>57) && c!='-');c=gc());
	if(c=='-') { neg=1; c=gc();}
	for(;c>=48 && c<=57;c=gc()) x=(x<<1)+(x<<3)+c-48;
	if(neg==1) return -x;
	return x;
}
inline void write(int n)
{
    int s=n,rev,c=0;
    if(s<0) { pc('-'); s=-s; }
    rev=s;
    if(!s){ pc('0'); pc('\n'); return;}
    while(!(rev%10)){ c++; rev/=10;}
    rev=0;
    while(s) { rev=(rev<<3)+(rev<<1)+s%10; s/=10; }
    while(rev){ pc(rev%10+'0'); rev/=10;}
    while(c--) pc('0');
    pc('\n');
}
struct node
{
    int left,right,sum,maxsum;
    node()
    {
        left=right=sum=maxsum=-INF;
    }
    node(int temp)
    {
        left=right=sum=maxsum=temp;
    }
    void calc(node a,node b)
    {
        sum=a.sum+b.sum;
        left=max(a.left,(a.sum+b.left));
        right=max(b.right,(b.sum+a.right));
        maxsum=max(a.right+b.left,max(a.maxsum,b.maxsum));
    }
}tree[MAX<<1];
inline void build(int l,int r,int n)
{
    for(l+=n,r+=n-1;l>1;)
    {
        l>>=1;
        r>>=1;
        for(int i=r;i>=l;i--)
            tree[i].calc(tree[i<<1],tree[i<<1|1]);
    }
}
inline int query(int l, int r, int n)
{
    node l_node,r_node,temp;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1) l_node.calc(l_node,tree[l++]);
        if(r&1) r_node.calc(tree[--r],r_node);
    }
    temp.calc(l_node,r_node);
    return temp.maxsum;
}
int main()
{
    int n,i,x,y,q,temp;
    n=read();
    for(i=n;i<n<<1;i++)
    {
        temp=read();
        tree[i]=node(temp);
    }
    build(0,n,n);
    q=read();
    while(q--)
    {
        x=read();
        y=read();
        if(x<1) x=1;
        if(y>n) y=n;
        write(query(x-1,y,n));
    }
    return 0;
}

