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
    while(5)
    {
        double t,sum=0.00;
        int i=2;
        scanf("%lf",&t);
        if(t==0.00)
            break;
        while(sum<=t)
        {
            sum+=1.00/(0.00+i);
            i++;
        }
        printf("%d card(s)\n",i-2);
    }
    return 0;
}
