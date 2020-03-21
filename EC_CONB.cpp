#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
int revBit(int n)
{
    string s="";
    while(n)
    {
        char ch=n%2+48;
        s+=ch;
        n/=2;
    }
    int ans=0, len=s.size();
    FORD(i, len-1, 0)
    {
        ans+=pow(2, len-1-i)*(s[i]-48);
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int a;
        scanf("%d", &a);
        if(a&1)
            printf("%d\n", a);
        else
            printf("%d\n", revBit(a));
    }
    return 0;
}

