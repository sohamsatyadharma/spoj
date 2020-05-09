#include<bits/stdc++.h>
typedef long long int lld;
int main()
{
    lld n;
    while(scanf("%lld",&n)==1)
        n%10?printf("1\n%d\n",n%10):printf("2\n");
    return 0;
}
