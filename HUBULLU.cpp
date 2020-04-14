#include<bits/stdc++.h>
using namespace std;
typedef long long int lld;
int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&i);
        if(!i)
            printf("Airborne wins.\n");
        else
            printf("Pagfloyd wins.\n");
    }
    return 0;
}
