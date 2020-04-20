#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FOR0(i,n) FOR(i,0,n)
#define PB push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define pc putchar_unlocked
#define gc getchar_unlocked
using namespace std;
typedef long long int lld;
inline string add(string a, string b)
{
    string c;
    int l1,l2,x,i,carry=0;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    l1=a.size();
    l2=b.size();
    if(l1>l2)
        b.resize(l1,'0');
    else
        a.resize(l2,'0');
    for(i=0;i<max(l1,l2);i++)
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
inline string divide(string a,int c)
{
    string b;
    int l,i,carry=0;
    l=a.size();
    for(i=0;i<l;i++)
    {
        b+=(10*carry+a[i]-48)/c+48;
        carry=(a[i]-48)%c;
    }
    b[i]='\0';
    while(*b.begin()==48)
        b.erase(b.begin());
    if(b.empty())
        return "0";
    return b;
}
inline string subtract(string a,string b)
{
    string c;
    int l1,l2,x,i,borrow=0;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    l1=a.size();
    l2=b.size();
    if(l1>l2)
        b.resize(l1,'0');
    else
        a.resize(l2,'0');
    for(i=0;i<max(l1,l2);i++)
    {
        bool flag=false;
        if(borrow&&a[i]>48)
            a[i]--;
        else if(borrow&&a[i]==48)
        {
            a[i]=57;
            flag=true;
        }
        if(a[i]<b[i])
            borrow=1;
        else
            borrow=0;
        c+=borrow*10+a[i]-b[i]+48;
        if(flag)
            borrow=1;
    }
    c[i]='\0';
    reverse(c.begin(),c.end());
    while(*c.begin()==48)
        c.erase(c.begin());
    if(c.empty())
        return "0";
    return c;
}
int main()
{
    int t=10;
    while(t--)
    {
        string sum,diff,x,y;
        cin>>sum>>diff;
        x=add(sum,diff);
        y=subtract(sum,diff);
        x=divide(x,2);
        y=divide(y,2);
        ITER(i,x)
            pc(*i);
        pc('\n');
        ITER(i,y)
            pc(*i);
        pc('\n');
    }
    return 0;
}
