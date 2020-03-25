#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
int phi[MAX];
void sieve()
{
    int i,j;
    for(i=0;i<=MAX;i++)
        phi[i]=i;
    for(i=2;i<=MAX;i++)
        if(phi[i]==i)
            for(j=i;j<=MAX;j+=i)
                phi[j]-=phi[j]/i;
}
int main() 
{
	sieve();
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    printf("%d\n",phi[n]);
	}
	return 0;
}
