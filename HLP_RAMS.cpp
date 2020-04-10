#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() 
{
    int t;
	scanf("%d", &t);
	while(t--)
	{
	    ll n; 
	    scanf("%lld", &n);
	    ll odd=1;
	    if(!n)
	        printf("0 1\n");
	   else 
	   {
	       ll temp=n;
	       while(temp)
           {
                odd*=((temp & 1)+1);
                temp=temp>>1;
           }
	       printf("%lld %lld\n", n-odd+1, odd);
	   }
	}
	return 0;
}
