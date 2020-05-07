#include<bits/stdc++.h>
#define gc getchar
#define MAX 32000
#define FOR(i,a,b) for(int i=a;i<b;i++)
typedef long long int lld;
using namespace std;
vector<bool>p(MAX,true);
vector<int>primes;
inline int scan()
{
    int x=0;
    int neg=0;
    register int c=gc();
    for(;((c<48 || c>57) && c!='-');c=gc());
    if(c=='-')
    {
        neg=1;
        c=gc();
    }
    for(;c>=48 && c<=57;c=gc())
        x=(x<<1)+(x<<3)+c-48;
    if(neg==1)
        return -x;
    return x;
}
inline void primegenerator()
{
    unsigned int i,j;
    for(i=2;i*i<=MAX;i++)
        if(p[i])
            for(j=i;j*i<=MAX;j++)
                p[j*i]=false;
    primes.push_back(2);
    for(i=3;i<MAX;i+=2)
        if(p[i])
            primes.push_back(i);
}
inline lld func(int a, int b, int n)
{
    lld i,j,temp,power,factors,c=0;
    for(i=a;i<b+1;i++)
    {
        temp=i;
        factors=1;
        for(j=0;primes[j]*primes[j]<=temp;j++)
        {
            power=0;
            while(temp%primes[j]==0)
            {
                temp/=primes[j];
                power++;
            }
            factors*=power+1;
        }
        if(temp>1)
            factors<<=1;
        if(factors==n)
            c++;
    }
    return c;
}
int main()
{
    lld a,b,c,n;
    primegenerator();
    a=scan();b=scan();n=scan();
    c=func(a,b,n);
    printf("%lld",c);
    return 0;
}
