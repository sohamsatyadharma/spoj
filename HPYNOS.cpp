#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int llu;
int main()
{
    llu n,c=0,s=0;
    scanf("%llu",&n);
    do
    {
        s=0;
        while(n>0)
        {
            s+=(n%10)*(n%10);
            n/=10;
        }
        n=s;
        c++;
    }while(s>9);
    if(n==1)
        printf("%llu\n",c);
    else
        printf("-1\n");
    return 0;
}
