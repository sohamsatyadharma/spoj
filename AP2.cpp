#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FOR0(i,n) FOR(i,0,n)
#define PB push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define pc putchar_unlocked
#define gc getchar
using namespace std;
typedef long long int lld;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        lld x,y,a,d,n,s,term;
        scanf("%lld%lld%lld",&x,&y,&s);
        n=2*s/(x+y);
        d=(y-x)/(n-5);
        a=x-2*d;
        printf("%lld\n",n);
        term=a;
        FOR0(i,n)
        {
            printf("%lld",term);
            if(i+1 != n)
				pc(' ');
            term+=d;
        }
        pc('\n');
    }
    return 0;
}
