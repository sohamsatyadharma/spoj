#include<bits/stdc++.h>
#define pc putchar
#define gc getchar
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
    lld n;
    while(1)
    {
        n=read();
        if(n==-1)
            break;
        n=(4*n-1)/3;
        (((lld)sqrt(n)*(lld)sqrt(n)==n)&&n>0)?printf("Y\n"):printf("N\n");
    }
    return 0;
}
