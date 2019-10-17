#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define gc getchar
#define pc putchar
typedef long long int ll;
using namespace std;
inline ll read()
{
	ll x=0,neg=0;
	register ll c=gc();
	for(;((c<48 || c>57) && c!='-');c=gc());
	if(c=='-') { neg=1; c=gc();}
	for(;c>=48 && c<=57;c=gc()) x=(x<<1)+(x<<3)+c-48;
	if(neg==1) return -x;
	return x;
}
inline void write(ll n, char ch='\n')
{
    ll s=n,rev,c=0;
    if(s<0) { pc('-'); s=-s; }
    rev=s;
    if(!s){ pc('0'); pc(ch); return;}
    while(!(rev%10)){ c++; rev/=10;}
    rev=0;
    while(s) { rev=(rev<<3)+(rev<<1)+s%10; s/=10; }
    while(rev){ pc(rev%10+'0'); rev/=10;}
    while(c--) pc('0');
    pc(ch);
}
int dp[6200][6200];
int lcs(string x, string y, int n)
{
    REP(i,n+1)
        REP(j,n+1)
        {
            if(!i or !j)
                dp[i][j]=0;
            else if(x[i-1]==y[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    return dp[n][n];
}
int main()
{
    int t=read();
    while(t--)
    {
        string s, t;
        cin>>s;
        t=s;
        reverse(t.begin(), t.end());
        int n=s.size();
        int ans=n-lcs(s, t, n);
        write(ans);
    }
    return 0;
}

