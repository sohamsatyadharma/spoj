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
typedef vector< string > vs;
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
    int t=read();
    while(t--)
    {
        int na=read(), nb=read(), nc=read(), a[na], b[nb], c[nc];
        REP(i, na)
            a[i]=read();
        REP(i, nb)
            b[i]=read();
        REP(i, nc)
            c[i]=read();
        int ans=INT_MAX, i=0, j=0, k=0;
        sort(a, a+na);
        sort(b, b+nb);
        sort(c, c+nc);
        while(i<na and j<nb and k<nc)
        {
            ans=min(abs(a[i]-b[j])+abs(b[j]-c[k])+abs(c[k]-a[i]), ans);
            int temp=min(a[i], min(b[j], c[k]));
            if(a[i]==temp)
                i++;
            else if(b[j]==temp)
                j++;
            else
                k++;
        }
        if(i==na)
        {
            while(j<nb and k<nc)
            {
                ans=min(abs(a[i-1]-b[j])+abs(b[j]-c[k])+abs(c[k]-a[i-1]), ans);
                int temp=min(b[j], c[k]);
                if(b[j]==temp)
                    j++;
                else
                    k++;
            }
            if(j==nb)
                while(k<nc)
                {
                    ans=min(abs(a[i-1]-b[j-1])+abs(b[j-1]-c[k])+abs(c[k]-a[i-1]), ans);
                    k++;
                }
            else
                while(j<nb)
                {
                    ans=min(abs(a[i-1]-b[j])+abs(b[j]-c[k-1])+abs(c[k-1]-a[i-1]), ans);
                    j++;
                }
        }
        else if(j==nb)
        {
            while(i<na and k<nc)
            {
                ans=min(abs(a[i]-b[j-1])+abs(b[j-1]-c[k])+abs(c[k]-a[i]), ans);
                int temp=min(a[i], c[k]);
                if(a[i]==temp)
                    i++;
                else
                    k++;
            }
            if(i==na)
                while(k<nc)
                {
                    ans=min(abs(a[i-1]-b[j-1])+abs(b[j-1]-c[k])+abs(c[k]-a[i-1]), ans);
                    k++;
                }
            else
                while(i<na)
                {
                    ans=min(abs(a[i]-b[j-1])+abs(b[j-1]-c[k-1])+abs(c[k-1]-a[i]), ans);
                    i++;
                }
        }
        else
        {
            while(j<nb and i<na)
            {
                ans=min(abs(a[i]-b[j])+abs(b[j]-c[k-1])+abs(c[k-1]-a[i]), ans);
                int temp=min(b[j], a[i]);
                if(b[j]==temp)
                    j++;
                else
                    j++;
            }
            if(j==nb)
                while(i<na)
                {
                    ans=min(abs(a[i]-b[j-1])+abs(b[j-1]-c[k-1])+abs(c[k-1]-a[i]), ans);
                    i++;
                }
            else
                while(j<nb)
                {
                    ans=min(abs(a[i-1]-b[j])+abs(b[j]-c[k-1])+abs(c[k-1]-a[i-1]), ans);
                    j++;
                }
        }
        write(ans);
    }
    return 0;
}

