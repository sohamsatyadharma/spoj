#include<bits/stdc++.h>
#define gc getchar
#define FOR(i,a,b) for(int i=a;i<b;i++)
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
int main()
{
    while(1)
    {
        int b,g,ans;
        g=scan();
        b=scan();
        if(b==-1&&g==-1)
            break;
        if(g>=b)
            if(g%(b+1))
                ans=g/(b+1)+1;
            else
                ans=g/(b+1);
        else
            if(b%(g+1))
                ans=b/(g+1)+1;
            else
                ans=b/(g+1);
        printf("%d\n",ans);
    }    
        
    return 0;
}
