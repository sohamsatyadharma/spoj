#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define TR(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define pc putchar
#define gc getchar
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
#define LIMIT 100050
#define MAX 1000009
using namespace std;
typedef long long ll; typedef long double ld; typedef unsigned long long ull;
typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pii; typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vpii; typedef vector<pair<ll, ll> > vpll;
typedef vector< vector< pair<int, int> > > vvpii; typedef vector< vector< pair<ll, ll> > > vvpll;
typedef vector< vector < int > > vvi; typedef vector< vector < ll > > vvl;
typedef vector< bool > vb;
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
int main()
{
    while(1)
    {
        int m=read(), a[m];
        if(!m)
            break;
        REP(i, m)
            a[i]=read();
        int n=read(), b[n], i=0, j=0, sum=0, sum1=0, sum2=0;
        REP(i, n)
            b[i]=read();
        for(; i<m and j<n;)
            if(a[i]<b[j])
                sum1+=a[i++];
            else if(a[i]>b[j])
                sum2+=b[j++];
            else
            {
                sum+=max(sum1, sum2);
                sum+=a[i];
                sum1=sum2=0;
                i++;
                j++;
            }
        while(i<m)
            sum1+=a[i++];
        while(j<n)
            sum2+=b[j++];
        sum+=max(sum1, sum2);
        write(sum);
    }
    return 0;
}

