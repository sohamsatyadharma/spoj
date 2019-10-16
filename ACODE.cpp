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
inline void write(lld n)
{
    lld s=n,rev,c=0;
    if(s<0) { pc('-'); s=-s; }
    rev=s;
    if(!s){ pc('0'); pc('\n'); return;}
    while(!(rev%10)){ c++; rev/=10;}
    rev=0;
    while(s) { rev=(rev<<3)+(rev<<1)+s%10; s/=10; }
    while(rev){ pc(rev%10+'0'); rev/=10;}
    while(c--) pc('0');
    pc('\n');
}
int main()
{
    string s;
    int c,n;
    while(cin>>s)
    {
        if(s=="0")
            break;
        n=s.size();
        s.insert(0,"0");
        int dp[n+1];
        dp[0]=1;
        FOR(i,1,n+1)
            dp[i]=0;
        FOR(i,1,n+1)
        {
            if(s[i]!='0')
                dp[i]=dp[i-1];
            c=(s[i-1]-48)*10+(s[i]-48);
            if(c>=10&&c<=26)
                dp[i]+=dp[i-2];
        }
        write(dp[n]);
    }
    return 0;
}
