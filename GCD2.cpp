#include<iostream>
#include<stdio.h>
#include<string>
#define TR(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define pc putchar
#define gc getchar
using namespace std;
typedef long long int lld;
inline int mod(string s,int n)
{
    int temp=0;
    TR(i,s)
        temp=(temp*10+(*i-48))%n;
    return temp;
}
int gcd(int a, int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main()
{
    int t,n;
    string s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>s;
        if(!n)
        {
            TR(i,s)
                pc(*i);
            pc('\n');
            continue;
        }
        printf("%d\n",gcd(n,mod(s,n)));
    }
    return 0;
}
