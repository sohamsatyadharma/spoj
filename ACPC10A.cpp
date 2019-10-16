#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FOR0(i,n) FOR(i,0,n)
#define PB push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define pc putchar_unlocked
#define gc getchar_unlocked
using namespace std;
typedef long long int lld;
inline int scan()
{
	int x=0,neg=0;
	register int c=gc();
	for(;((c<48 || c>57) && c!='-');c=gc());
	if(c=='-') { neg=1; c=gc();}
	for(;c>=48 && c<=57;c=gc()) x=(x<<1)+(x<<3)+c-48;
	if(neg==1) return -x;
	return x;
}
int main()
{
    int a,b,c;
    while(1)
    {
        a=scan();b=scan();c=scan();
        if(!a&&!b&&!c)
            break;
        else if(2*b==a+c)
            printf("AP %d\n",c+b-a);
        else
            printf("GP %d\n",c*b/a);
    }
    return 0;
}
