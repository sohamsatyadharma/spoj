#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define MP make_pair
#define TR(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define pc putchar_unlocked
#define gc getchar_unlocked
using namespace std;
typedef long long int lld;
inline lld read()
{
	lld x=0,neg=0;
	register lld c=gc();
	for(;((c<48 || c>57) && c!='-');c=gc());
	if(c=='-') { neg=1; c=gc();}
	for(;c>=48 && c<=57;c=gc()) x=(x<<1)+(x<<3)+c-48;
	if(neg==1) return -x;
	return x;
}
int n,m,a[185][185];
void bfs(pair<int,int> &p)
{
    int d,x,y;
    queue< pair<int,int> > q;
    q.push(p);
    a[p.first][p.second]=0;
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        d=a[x][y]+1;
        if(x-1>=0&&d<a[x-1][y])
        {
            q.push(MP(x-1,y));
            a[x-1][y]=d;
        }
        if(x+1<m&&d<a[x+1][y])
        {
            q.push(MP(x+1,y));
            a[x+1][y]=d;
        }
        if(y-1>=0&&d<a[x][y-1])
        {
            q.push(MP(x,y-1));
            a[x][y-1]=d;
        }
        if(y+1<n&&d<a[x][y+1])
        {
            q.push(MP(x,y+1));
            a[x][y+1]=d;
        }
    }
}
int main()
{
    int t;
    t=read();
    while(t--)
    {
        vector< pair<int,int> > v;
        char ch;
        m=read();
        n=read();
        REP(i,m)
            REP(j,n)
            {
                cin>>ch;
                if(ch=='1')
                {
                    v.PB(MP(i,j));
                    a[i][j]=INT_MIN;
                }
                else
                    a[i][j]=INT_MAX;
            }
        TR(i,v)
            bfs(*i);
        REP(i,m)
        {
            REP(j,n)
                printf("%d ",a[i][j]);
            pc('\n');
        }
        pc('\n');
    }
    return 0;
}
