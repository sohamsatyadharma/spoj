#include<bits/stdc++.h>
#define pc putchar
#define gc getchar
#define MAX 100001
typedef long long int lld;
int tree[MAX<<1][3],lazy[MAX];
inline lld read()
{
	lld x=0,neg=0;
	register lld c=gc();
	for(;((c<48 || c>57) && c!='-');c=gc());
	if(c=='-') { neg=1; c=gc();}
	for(;c>=48 && c<=57;c=gc()) x=(x<<1)+(x<<3)+c-48;
	if(neg==1) return -x;
	return x;
}
inline void write(lld n)
{
    lld s=n,rev,c=0;
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
int swap1(int &x, int &y, int &z)
{
    int t1=x,t2=y,t3=z;
    y=t1;
    z=t2;
    x=t3;
}
int swap2(int &x, int &y, int &z)
{
    int t1=x,t2=y,t3=z;
    y=t3;
    z=t1;
    x=t2;
}
inline void change(int i)
{
    tree[i][0]=tree[i<<1][0]+tree[i<<1|1][0];
    tree[i][1]=tree[i<<1][1]+tree[i<<1|1][1];
    tree[i][2]=tree[i<<1][2]+tree[i<<1|1][2];
}
inline void apply1(int i, int n, int val)
{
    swap1(tree[i][0],tree[i][1],tree[i][2]);
    if(i<n) lazy[i]=(val+lazy[i])%3;
}
inline void apply2(int i, int n, int val)
{
    swap2(tree[i][0],tree[i][1],tree[i][2]);
    if(i<n) lazy[i]=(val+lazy[i])%3;
}
inline void build(int l, int r, int n)
{
    for(l=(l+n)>>1,r=(r+n-1)>>1;l>=1;l>>=1,r>>=1)
        for(int i=r;i>=l;i--)
            change(i);
}
inline void push(int l, int r, int n)
{
    int k,s,h,i;
    h=sizeof(int)*8-__builtin_clz(n-1);
    s=h;k=1<<(h-1);
    for(l+=n,r+=n-1;s>0;s--,k>>=1)
        for(i=l>>s;i<=r>>s;i++)
            if(lazy[i]==1)
            {
                apply1(i<<1,n,lazy[i]);
                apply1(i<<1|1,n,lazy[i]);
                lazy[i]=0;
            }
            else if(lazy[i]==2)
            {
                apply2(i<<1,n,lazy[i]);
                apply2(i<<1|1,n,lazy[i]);
                lazy[i]=0;
            }
}
inline void update(int l, int r, int n)
{
    push(l,l+1,n);
    push(r-1,r,n);
    int k=1;
    bool lflag=false,rflag=false;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1,k<<=1)
    {
        if(lflag) change(l-1);
        if(rflag) change(r);
        if(l&1) { apply1(l++,n,1); lflag=true; }
        if(r&1) { apply1(--r,n,1); rflag=true; }
    }
    for(--l;r>0;l>>=1,r>>=1,k<<=1)
    {
        if(lflag) change(l);
        if(rflag&&(!lflag||l!=r)) change(r);
    }
}
inline int query(int l, int r, int n)
{
    push(l,l+1,n);
    push(r-1,r,n);
    int sum=0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1) sum+=tree[l++][0];
        if(r&1) sum+=tree[--r][0];
    }
    return sum;
}
int main()
{
    bool flag;
    int n,c,p,q,s;
    n=read();
    c=read();
    for(int j=n;j<n<<1;j++)
        for(int q=0;q<3;q++)
            (!q)?tree[j][q]=1:tree[j][q]=0;
    for(int j=1;j<n;lazy[j++]=0);
    build(0,n,n);
    while(c--)
    {
        flag=read();
        if(flag)
        {
            p=read();q=read();
            q++;
            s=query(p,q,n);
            write(s);
        }
        else
        {
            p=read();q=read();
            q++;
            update(p,q,n);
        }
    }
    return 0;
}
