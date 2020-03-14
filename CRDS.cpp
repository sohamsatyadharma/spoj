#include<bits/stdc++.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define MOD 1000007
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
inline lld mul(lld a, lld b)
{
    lld x=0,y=a%MOD;
    while(b)
    {
        if(b&1)
            x=(x+y)%MOD;
        y=(y<<1)%MOD;
        b>>=1;
    }
    return x%MOD;
}
int main()
{
    int t;
    t=read();
    while(t--)
    {
        lld n,a,b,k;
        n=read();
        a=n-1;
        b=3*n+4;
        k=(n&1)?(mul(a/2,b)+2)%MOD:(mul(a,b/2)+2)%MOD;
        write(k);
    }
    return 0;
}
