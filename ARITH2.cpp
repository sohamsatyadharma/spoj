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
inline void write(lld n)
{
    lld s=n,rev,c=0;
    if(s<0) { pc('-'); s=-s; }
    rev=s;
    if(!s){ pc('0'); pc('\n'); return;}
    while(!(rev%10)){ c++; rev/=10;}
    rev=0;
    while(s) { rev=(rev<<3)+(rev<<1)+s%10; s/=10; }
    while(rev){ pc(rev%10+'0'); rev/=10;}
    while(c--) pc('0');
    pc('\n');
}
lld convert(string s)
{
    lld r=0;
    TR(i,s)
        if(!isdigit(*i)) return -1;
        else
            r=(r<<3)+(r<<1)+(*i-48);
    return r;
}
lld operate(lld a,string b,string c)
{
    if(b=="+")
        return a+convert(c);
    else if(b=="-")
        return a-convert(c);
    else if(b=="*")
        return a*convert(c);
    else if(b=="/")
        return a/convert(c);
    else if(b=="^")
        return a^convert(c);
}
int main()
{
    int t;
    t=read();
    while(t--)
    {
        string s;
        vector<string> v;
        while(s!="=")
        {
            cin>>s;
            v.push_back(s);
        }
        v.erase(v.end());
        lld ans=convert(v[0]);
        TR(i,v)
            if(convert(*i)==-1)
                ans=operate(ans,*i,*(i+1));
        write(ans);
    }
    return 0;
}
