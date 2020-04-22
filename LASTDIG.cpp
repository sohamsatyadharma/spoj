#include <bits/stdc++.h>
typedef long long int lld;
using namespace std;
int modulo(int a,int b)
{
    lld x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
            x=(x*y)%10;
        y = (y*y)%10; 
        b /= 2;
    }
    return x%10;
}

int main() 
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    lld base,power;
	    int ans;
	    scanf("%d%d",&base,&power);
	    ans=modulo(base,power);
	    printf("%d\n",ans);
	}
	return 0;
}
