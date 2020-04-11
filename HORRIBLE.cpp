#include<bits/stdc++.h>
#define pc putchar
#define gc getchar
using namespace std;
typedef long long int lld;
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
inline void change(lld *tree, lld *lazy, lld i, lld k)
{
    tree[i]=tree[i<<1]+tree[i<<1|1];
}
inline void apply(lld *tree, lld *lazy, lld i, lld val, lld k,lld n)
{
    tree[i]+=val*k;
    if(i<n) lazy[i]+=val;
}
inline void push(lld *tree, lld *lazy, lld l, lld r, lld n)
{
    lld k,s,h,i;
    h=sizeof(int)*8-__builtin_clz(n-1);
    s=h;k=1<<(h-1);
    for(l+=n,r+=n-1;s>0;s--,k>>=1)
        for(i=l>>s;i<=r>>s;i++)
            if(lazy[i])
            {
                apply(tree,lazy,i<<1,lazy[i],k,n);
                apply(tree,lazy,i<<1|1,lazy[i],k,n);
                lazy[i]=0;
            }
}
inline void update(lld *tree, lld *lazy, lld l, lld r, lld val, lld n)
{
    if(!val) return;
    push(tree,lazy,l,l+1,n);
    push(tree,lazy,r-1,r,n);
    lld k=1;
    bool lflag=false,rflag=false;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1,k<<=1)
    {
        if(lflag) change(tree,lazy,l-1,k);
        if(rflag) change(tree,lazy,r,k);
        if(l&1) { apply(tree,lazy,l++,val,k,n); lflag=true; }
        if(r&1) { apply(tree,lazy,--r,val,k,n); rflag=true; }
    }
    for(--l;r>0;l>>=1,r>>=1,k<<=1)
    {
        if(lflag) change(tree,lazy,l,k);
        if(rflag&&(!lflag||l!=r)) change(tree,lazy,r, k);
    }
}
inline lld query(lld *tree, lld *lazy, lld l, lld r, lld n)
{
    push(tree,lazy,l,l+1,n);
    push(tree,lazy,r-1,r,n);
    lld sum=0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1) sum+=tree[l++];
        if(r&1) sum+=tree[--r];
    }
    return sum;
}
int main()
{
    lld t,n,c,i,p,q,v,s,h;
    int flag;
    t=read();
    while(t--)
    {
        n=read();
        c=read();
        lld tree[2*n],lazy[n];
        for(i=0;i<2*n;tree[i++]=0);
        for(i=0;i<n;lazy[i++]=0);
        while(c--)
        {
            flag=read();
            if(flag)
            {
                p=read();q=read();
                p--;
                s=query(tree,lazy,p,q,n);
                write(s);
            }
            else
            {
                p=read();q=read();v=read();
                p--;
                update(tree,lazy,p,q,v,n);
            }
        }
    }
    return 0;
}
