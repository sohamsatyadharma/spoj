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
int convert(string s)
{
    int r=0;
    ITER(i,s)
        if(!isdigit(*i)) return -1;
        else
            r=(r<<3)+(r<<1)+(*i-48);
    return r;
}
int main()
{
    int t;
    scanf("%d",&t);
    string a,b,c,d,e;
    int x,y,z;
    while(t--)
    {
        cin>>a>>b>>c>>d>>e;
        x=convert(a);
        y=convert(c);
        z=convert(e);
        if(x<0) x=z-y;
        else if(y<0) y=z-x;
        else z=x+y;
        cout<<x<<" + "<<y<<" = "<<z<<endl;
    }
    return 0;
}
