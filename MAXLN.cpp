#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        double r,ans;
        scanf("%lf",&r);
        ans=4*r*r+0.25;
        printf("Case %d: %.2lf\n",i,ans);
    }
    return 0;
}
