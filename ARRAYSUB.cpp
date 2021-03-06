#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define TR(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
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
    pc(' ');
}
int main()
{
    int n,k;
    n=read();
    int a[n];
    REP(i,n) a[i]=read();
    k=read();
    int b[n-k+1];
    deque<int> dq;
    REP(i,k)
    {
        while(!dq.empty() and a[i]>=a[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    FOR(i,k,n)
    {
        b[i-k]=a[dq.front()];
        while(!dq.empty() and a[i]>=a[dq.back()])
            dq.pop_back();
        while(!dq.empty() and dq.front()<=i-k)
            dq.pop_front();
        dq.push_back(i);
    }
    b[n-k]=a[dq.front()];
    REP(i,n-k+1)
        write(b[i]);
    return 0;
}
