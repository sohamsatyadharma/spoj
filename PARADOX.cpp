#include<bits/stdc++.h>
#define MAX 999999
using namespace std;
int main()
{
    while(1)
    {
        int n, temp;
        string s;
        cin>>n;
        if(!n)
            break;
        int dist[n+1][n+1];
        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
                dist[i][j]=MAX;
        for(int i=1; i<=n; i++)
        {
            cin>>temp>>s;
            dist[i][temp]=(s=="true")?2:1;
        }
        for(int k=1; k<=n; k++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    if(dist[i][j]>dist[i][k]+dist[k][j])
                        dist[i][j]=dist[i][k]+dist[k][j];
        bool flag=0;
        for(int i=1; i<=n; i++)
            if(dist[i][i]!=MAX && dist[i][i]&1)
            {
                flag=true;
                cout<<"PARADOX"<<endl;
                break;
            }
        if(!flag)
            cout<<"NOT PARADOX"<<endl;
    }
    return 0;
}
