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
int main()
{
    lld t;
    scanf("%lld",&t);
    while(t--)
    {
        lld n,temp,sum=0;
        scanf("%lld",&n);
        FOR0(i,n)
        {
            scanf("%lld",&temp);
            sum=(sum+temp)%n;
        }
        if(sum)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
