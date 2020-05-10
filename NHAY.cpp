#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define TR(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define pc putchar_unlocked
#define gc getchar_unlocked
using namespace std;
typedef unsigned long long int llu;
int main()
{
    int n;
    llu l,i;
    while(scanf("%d",&n)!=EOF)
    {
        llu s=0;
        string needle,hay;
        cin>>needle;
        cin>>hay;
        l=hay.size();
        if(l<n)
        {
            pc('\n');
            continue;
        }
        for(i=0;i<l-n+1;i++)
            if(needle==hay.substr(i,n))
                printf("%llu\n",i);
        pc('\n');
    }
    return 0;
}
