#include<bits/stdc++.h>
using namespace std;
typedef long long int lld;
lld reverse_num(lld n)
{
    lld rev=0;
    int d;
    while(n)
    {
        d=n%10;
        rev=rev*10+d;
        n/=10;
    }
    return rev;
}
int main()
{
    lld t;
    scanf("%lld",&t);
    while(t--)
    {
        lld m,n,sum=0;
        scanf("%lld%lld",&m,&n);
        sum=reverse_num(m)+reverse_num(n);
        printf("%lld\n",reverse_num(sum));
    }
    return 0;
}
