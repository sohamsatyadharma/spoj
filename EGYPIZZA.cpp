#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define TR(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define pc putchar
#define gc getchar
using namespace std;
typedef long long int lld;
int ceil(int m)
{
    return (m&1)?(m/2+1):m/2;
}
int main()
{
    int n,a,b,m,x=0,y=0,z=0,ans=0,k;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d/%d",&a,&b);
        if(a==1&&b==4)
            x++;
        else if(a==1&&b==2)
            y++;
        else
            z++;
    }
    if(z-x>=0)
        ans=ceil(y)+z+1;
    else
    {
        k=x-z;
        m=y-ceil(k);
        if(m>=0)
            ans=ceil(m)+ceil(k)+1+z;
        else
        {
            k=x-(z+2*y);
            ans=((k%4)?(k/4+1):k/4)+z+y+1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
