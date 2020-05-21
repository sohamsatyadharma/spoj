#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FOR0(i,n) FOR(i,0,n)
#define PB push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define pc putchar
#define gc getchar_unlocked
using namespace std;
typedef long long int lld;
inline lld read()
{
	lld x=0,neg=0;
	register lld c=gc();
	for(;((c<48 || c>57) && c!='-');c=gc());
	if(c=='-') { neg=1; c=gc();}
	for(;c>=48 && c<=57;c=gc()) x=(x<<1)+(x<<3)+c-48;
	if(neg==1) return -x;
	return x;
}
int main()
{
    while(5)
    {
        int n;
        n=read();
        if(!n)
            break;
        int a[n],b[n];
        bool flag=true;
        FOR0(i,n)
        {
            a[i]=read();
            b[a[i]-1]=i+1;
        }
        FOR0(i,n)
            if(a[i]!=b[i])
            {
                flag=false;
                break;
            }
        if(flag)
            printf("ambiguous\n");
        else
            printf("not ambiguous\n");

    }
}
