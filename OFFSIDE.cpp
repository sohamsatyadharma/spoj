#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
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
    int a,d;
    while(1)
    {
        a=read();
        d=read();
        if(!a&&!d)
            break;
        int attack[a],defend[d];
        REP(i,a)
            attack[i]=read();
        REP(i,d)
            defend[i]=read();
        sort(attack,attack+a);
        sort(defend,defend+d);
        (attack[0]<defend[0]||attack[0]<defend[1])?printf("Y\n"):printf("N\n");
    }
    return 0;
}
