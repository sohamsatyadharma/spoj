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
map<int,lld>dp;
lld f(int n)
{
    lld ans;
    if(!n)
        return 0;
    ans=dp[n];
    if(!ans)
    {
        ans=f(n/2)+f(n/3)+f(n/4);
        dp[n]=(ans>n)?ans:n;
    }
    return dp[n];
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
        printf("%lld\n",f(n));
    return 0;
}
