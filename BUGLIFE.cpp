#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
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
bool bfs(vector<int> adj[],int v,int src)
{
    int i,temp;
    int color[v+1];
    REP(j,v+1)
        color[j]=-1;
    queue<int> q;
    q.push(src);
    color[src]=1;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        for(i=0;i<adj[temp].size();i++)
            if(color[adj[temp][i]]==-1)
            {
                color[adj[temp][i]]=1-color[temp];
                q.push(adj[temp][i]);
            }
            else if(color[adj[temp][i]]==color[temp])
                return false;
    }
    return true;
}
int main()
{
    int t,v,n,b,a;
    t=read();
    REP(j,t)
    {
        bool flag=true;
        v=read();
        n=read();
        vector<int> adj[v+1];
        REP(i,n)
        {
            a=read();
            b=read();
            adj[a].PB(b);
            adj[b].PB(a);
        }
        FOR(i,1,v+1)
            if(!bfs(adj,v,i))
            {
                flag=false;
                break;
            }
        printf("Scenario #%d:\n",j+1);
        if (!flag)
            printf("Suspicious bugs found!\n");
        else
            printf("No suspicious bugs found!\n");
    }
    return 0;
}
