#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define TR(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define pc putchar
#define gc getchar
using namespace std;
typedef long long int lld;
int main()
{
    int t,n,i;
    scanf("%d",&t);
    map<string,int> m;
    string s;
    while(t--)
    {
        m["TTT"]=m["TTH"]=m["THT"]=m["THH"]=m["HTT"]=m["HTH"]=m["HHT"]=m["HHH"]=0;
        scanf("%d",&n);
        cin>>s;
        TR(it,m)
            for(i=0;i<38;i++)
                if(it->first==s.substr(i,3))
                    it->second++;
        printf("%d %d %d %d %d %d %d %d %d \n",n,m["TTT"],m["TTH"],m["THT"],m["THH"],m["HTT"],m["HTH"],m["HHT"],m["HHH"]);
    }
    return 0;
}
