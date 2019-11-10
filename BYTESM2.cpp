#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
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
    pc('\n');
}
int main()
{
    int t;
    t=read();
    while(t--)
    {
        int r,c,ans=0;
        r=read();
        c=read();
        int cost[r][c];
        REP(i,r)
            REP(j,c)
                cost[i][j]=read();
        FOR(i,1,r)
            REP(j,c)
            {
                if(!j)
                    cost[i][j]+=max(cost[i-1][j],cost[i-1][j+1]);
                else if(j==c-1)
                    cost[i][j]+=max(cost[i-1][j-1],cost[i-1][j]);
                else
                    cost[i][j]+=max(cost[i-1][j-1],max(cost[i-1][j],cost[i-1][j+1]));
            }
        REP(j,c)
            ans=max(ans,cost[r-1][j]);
        write(ans);
    }
    return 0;
}
