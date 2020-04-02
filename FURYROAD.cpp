#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define TR(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define pc putchar_unlocked
#define gc getchar_unlocked
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
int x[10005], y[10005];
bool m[1005][1005], flag[1005][1005];
void bfs(int i)
{
    queue< pair<int, int> > q;
    flag[x[i]][y[i]]=true;
    q.push(mp(x[i], y[i]));
    while(!q.empty())
    {
        int a=(q.front()).ff, b=(q.front()).ss;
        q.pop();
        FOR(dx, -1, 2)
            FOR(dy, -1, 2)
                if(!(!dx and !dy))
                {
                    int newx=a+dx, newy=b+dy;
                    if(newx>=0 and newy>=0 and newx<1001 and newy<1001)
                        if(m[newx][newy] and !flag[newx][newy])
                        {
                            flag[newx][newy]=true;
                            q.push(mp(newx, newy));
                        }
                }
    }
}
int main()
{
    int t=read();
    FOR(test, 1, t+1)
    {
        REP(i, 1005)
            REP(j, 1005)
                m[i][j]=flag[i][j]=false;
        int n=read(), ans=0;
        REP(i, n)
        {
            x[i]=read();
            y[i]=read();
            m[x[i]][y[i]]=true;
        }
        REP(i, n)
            if(!flag[x[i]][y[i]])
            {
                bfs(i);
                ans++;
            }
        printf("Case %d: %d\n", test, ans);
    }
    return 0;
}

