#include<iostream>
#define MAX 1005
using namespace std;
bool visited[MAX][MAX];
string s[MAX];
struct point
{
    int x, y;
};
bool operator==(point p1, point p2)
{
    return p1.x==p2.x && p1.y==p2.y;
}
int valid(int r, int c, int m, int n)
{
    return r>=0 && c>=0 && r<n && c<m;
}
point next(point p, char ch, int m, int n)
{
    point temp;
    if(ch=='S' && valid(p.x+1, p.y, m, n))
    {
        temp.x=p.x+1;
        temp.y=p.y;
    }
    else if(ch=='N' && valid(p.x-1, p.y, m, n))
    {
        temp.x=p.x-1;
        temp.y=p.y;
    }
    else if(ch=='E' && valid(p.x, p.y+1, m, n))
    {
        temp.x=p.x;
        temp.y=p.y+1;
    }
    else if(ch=='W' && valid(p.x, p.y-1, m, n))
    {
        temp.x=p.x;
        temp.y=p.y-1;
    }
    else
        temp.x=temp.y=-1;
    return temp;

}
int row[]={-1, 0, 0, 1};
int col[]={0, -1, 1, 0};
void dfs(point p, int m, int n)
{
    visited[p.x][p.y]=true;
    point p1, p2, p3;
    for(int i=0; i<4; i++)
    {
        int x=row[i]+p.x;
        int y=col[i]+p.y;
        if(valid(x, y, m, n))
        {
            p1.x=x;
            p1.y=y;
            p2=next(p1, s[x][y], m, n);
            p3=next(p, s[p.x][p.y], m, n);
            if(!visited[x][y] && (p2==p || p3==p1))
                dfs(p1, m, n);
        }
    }
}
int main()
{
    int n, m, c=0;
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>s[i];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            visited[i][j]=false;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(!visited[i][j])
            {
                point p;
                p.x=i;
                p.y=j;
                //cout<<"soham "<<i<<" "<<j<<endl;
                dfs(p, m, n);
                c++;
            }
    cout<<c<<endl;
    return 0;
}
