#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define TR(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define pc putchar
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
int main()
{
    int t,towers,n,danger,i;
    t=read();
    while(t--)
    {
        n=read();
        towers=read();
        danger=read();
        int health[n],tower_count=0;
        REP(i,n)
            health[i]=read();
        REP(i,n)
        {
            while(health[i]>0)
            {
                health[i]-=danger;
                tower_count++;
            }
            tower_count--;
        }
        if(tower_count<towers)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
