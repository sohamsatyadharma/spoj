#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int x,y;
	    scanf("%d%d",&x,&y);
	    if(x==y&&x%2)
	        printf("%d\n",2*x-1);
	   else if(x==y&&!(x%2))
	        printf("%d\n",2*x);
	   else if(x-y==2&&!(x%2))
	        printf("%d\n",2*x-2);
	   else if(x-y==2&&x%2)
	        printf("%d\n",2*x-3);
	   else 
	        printf("No Number\n");
	}
	return 0;
}
