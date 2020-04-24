#include<stdio.h>
#define MAX 1000010
using namespace std;
typedef long long lld;
lld phi[MAX];
lld sum[MAX]={0};
void totient()
{
    lld i,j;
    for(i=0;i<=MAX;i++)
        phi[i]=i;
    for(i=2;i<=MAX;i++)
        if(phi[i]==i)
            for(j=i;j<=MAX;j+=i)
                phi[j]-=phi[j]/i;
    for(i=1;i<=MAX;i++)
        for(j=i;j<=MAX;j+=i)
            sum[j]+=phi[i]*i;
}
int main()
{
    totient();
    int t,n;
    lld s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        s=(1+sum[n])*n/2;
        printf("%lld\n",s);
    }
    return 0;
}
