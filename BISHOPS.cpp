#include<bits/stdc++.h>
using namespace std;
typedef long long int lld;
string mul(string s)
{
    int x,carry=0,i,l=s.size();
    string temp;
    reverse(s.begin(),s.end());
    for(i=0;i<l;i++)
    {
        x=(s[i]-48)*2+carry;
        temp+=x%10+48;
        carry=x/10;
    }
    while(carry)
    {
        temp+=carry%10+48;
        carry/=10;
        i++;
    }
    temp[i]='\0';
    reverse(temp.begin(),temp.end());
    return temp;
}
string subtract(string s)
{
    string temp;
    int x,i=1,l;
    bool flag=false;
    l=s.size();
    reverse(s.begin(),s.end());
    if(s[0]==48)
    {
        temp+=56;
        flag=true;
    }
    else if(s[0]==49)
    {
        temp+=57;
        flag=true;
    }
    else
        temp+=s[0]-2;
    for(;i<l;i++)
    {
        if(flag&&s[i]>48)
        {
            s[i]--;
            flag=false;
        }
        else if(flag&&s[i]==48)
        {
            s[i]=57;
            flag=true;
        }
        temp+=s[i];
    }
    temp[i]='\0';
    reverse(temp.begin(),temp.end());
    while(*temp.begin()==48)
        temp.erase(temp.begin());
    if(temp.empty())
        return "0";
    return temp;
}
int main()
{
    string s;
    while(cin>>s)
    {
        if(s=="1")
            cout<<1<<endl;
        else
            cout<<subtract(mul(s))<<endl;
    }
    return 0;
}
