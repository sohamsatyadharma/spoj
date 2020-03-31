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
inline void write(lld n)
{
    lld s=n,rev,c=0;
    rev=s;
    if(!s)
    {
        pc('0');
        pc('\n');
        return;
    }
    while(!(rev%10))
    {
        c++;
        rev/=10;
    }
    rev=0;
    while(s)
    {
        rev=(rev<<3)+(rev<<1)+s%10;
        s/=10;
    }
    while(rev)
    {
        pc(rev%10+'0');
        rev/=10;
    }
    while(c--)
        pc('0');
}
int main()
{
    int t;
    t=scan();
    while(t--)
    {
        int a[200],n,x,carry=0,m=1;
        a[0]=1;
        n=scan();
        FOR(i,1,n+1)
        {
            FOR0(j,m)
            {
                x=a[j]*i+carry;
                a[j]=x%10;
                carry=x/10;
            }
            while(carry)
            {
                a[m]=carry%10;
                carry/=10;
                m++;
            }
        }
        FORD(i,m-1,0)
            printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}
