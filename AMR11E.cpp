#include<bits/stdc++.h>
#define pc putchar_unlocked
#define gc getchar_unlocked
#define MAX 3600
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
vector<bool> flag(MAX, false);
vector<int> primes;
vector<int> lucky;
void sieve()
{
    lld i,j;
    for(i=3;i*i<=MAX;i+=2)
    {
        if(flag[i])
            continue;
        for(j=i*i;j<=MAX;j+=2*i)
            flag[j]=true;
    }
    primes.push_back(2);
    for(i=3;i<MAX;i+=2)
        if(!flag[i])
            primes.push_back(i);
}
void lucky_store()
{
    lld i,j,x;
    for(i=10;i<=3000;i++)
    {
        x=0;
        for(j=0;primes[j]<=i;j++)
        {
            if(!(i%primes[j]))
                x++;
            if(x==3)
            {
                lucky.push_back(i);
                break;
            }
        }
    }
}
int main()
{
    sieve();
    lucky_store();
    int t;
    t=read();
    while(t--)
    {
        int n;
        n=read();
        write(lucky[n-1]);
    }
    return 0;
}
