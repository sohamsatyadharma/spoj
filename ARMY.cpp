#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FOR0(i,n) FOR(i,0,n)
#define PB push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
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
int main()
{
    int t;
    t=read();
    while(t--)
    {
        lld g,m;
        g=read();
        m=read();
        lld a[g],b[m];
        FOR0(i,g)
            a[i]=read();
        FOR0(i,m)
            b[i]=read();
        sort(a,a+g,greater<int>());
        sort(b,b+m,greater<int>());
        if(a[0]>=b[0])
            printf("Godzilla\n");
        else
            printf("MechaGodzilla\n");
    }
    return 0;
}
