#include<bits/stdc++.h>
#define pc putchar_unlocked
#define gc getchar_unlocked
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
lld split_inv(lld a[],lld res[],int left,int right, int mid)
{
    int l=left,r=mid,i=left;
    lld s=0;
    while(l<mid&&r<right)
    {
        if(a[l]<a[r])
            res[i++]=a[l++];
        else
        {
            res[i++]=a[r++];
            s+=mid-l;
        }
    }
    while(l<mid)
        res[i++]=a[l++];
    while(r<right)
        res[i++]=a[r++];
    for(i=left;i<right;i++)
        a[i]=res[i];
    return s;
}
lld inv_count(lld a[],lld res[],int left,int right)
{
    lld c=0;
    if(right>left+1)
    {
        int mid=(left+right)/2;
        c+=inv_count(a,res,left,mid);
        c+=inv_count(a,res,mid,right);
        c+=split_inv(a,res,left,right,mid);
    }
    return c;
}
int main()
{
    int t;
    t=read();
    while(t--)
    {
        int n,i;
        lld x,c;
        n=read();
        lld a[n],res[n];
        for(i=0;i<n;a[i++]=read());
        c=inv_count(a,res,0,n);
        write(c);
    }
    return 0;
}
