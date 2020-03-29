#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
typedef long long int lld;
using namespace std;
int main() 
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    scanf("%d\n",&n);
	    int m[n],w[n];
	    lld sum=0;
	    FOR(i,0,n)
	        scanf("%d",&m[i]);
	    FOR(i,0,n)
	        scanf("%d",&w[i]);
	    sort(m,m+n);
	    sort(w,w+n);
	    FOR(i,0,n)
	        sum+=m[i]*w[i];
	    printf("%lld\n",sum);
	}
	return 0;
}
