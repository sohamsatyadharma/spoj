#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define TR(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
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
int main()
{
    int t,sum=0,temp,n;
    set<int> s;
    t=read();
    int f[t];
    REP(i,t)
    {
        f[i]=read();
        n=read();
        REP(j,n)
        {
            temp=read();
            s.insert(temp);
        }
    }
    REP(i,t)
        s.erase(f[i]);
    TR(it,s)
        sum++;
    write(sum);
    return 0;
}
