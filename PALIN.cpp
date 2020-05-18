#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FOR0(i,n) FOR(i,0,n)
#define PB push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define pc putchar
#define gc getchar
using namespace std;
typedef long long int lld;
inline string add(string a)
{
    string c,b="1";
    int l1,x,i,carry=0;
    reverse(a.begin(),a.end());
    l1=a.size();
    b.resize(l1,'0');
    for(i=0;i<l1;i++)
    {
        x=a[i]+b[i]+carry-96;
        c+=x%10+48;
        carry=x/10;
    }
    while(carry)
    {
        c+=carry%10+48;
        carry/=10;
        i++;
    }
    c[i]='\0';
    reverse(c.begin(),c.end());
    return c;
}
inline void print(string s)
{
    ITER(i,s)
        pc(*i);
    pc('\n');
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string s,ans,a,b,c;
        bool flag=true;
        int l;
        cin>>s;
        l=s.size();
        ITER(i,s)
            if(*i!=57)
                flag=false;
        if(flag)
        {
            ans=add(s);ans=add(ans);
            print(ans);
            continue;
        }
        if(l%2)
        {
            a=s.substr(0,l/2);
            c=a;
            reverse(c.begin(),c.end());
            b=s.substr(l/2+1,l);
            if(c>b)
            {
                ans+=a;
                ans+=s[l/2];
                ans+=c;
            }
            else
            {
                a+=s[l/2];
                a=add(a);
                ans+=a;
                c=a;
                reverse(c.begin(),c.end());
                c.erase(c.begin());
                ans+=c;
            }
            print(ans);
        }
        else
        {
            a=s.substr(0,l/2);
            c=a;
            reverse(c.begin(),c.end());
            b=s.substr(l/2,l);
            if(c>b)
            {
                ans+=a;
                ans+=c;
            }
            else
            {
                a=add(a);
                ans+=a;
                c=a;
                reverse(c.begin(),c.end());
                ans+=c;
            }
            print(ans);
        }
    }
    return 0;
}
