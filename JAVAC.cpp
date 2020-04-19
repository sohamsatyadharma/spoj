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
int main()
{
    string s;
    int j;
    bool flag1,flag2;
    while(cin>>s)
    {
        string temp;
        flag1=flag2=true;
        int l=s.length();
        if(!islower(s[0])) //all identifiers should begin with a lowercase letter
            flag1=flag2=false;
        for(j=1;j<l;j++)
        {
            if(!isalpha(s[j])) flag1=false;
            if(s[j]=='_')
            {
                if(!islower(s[j+1])) flag2=false;
            }
            else if(!islower(s[j])) flag2=false;
        }
        if(!flag1 and !flag2)
        {
            printf("Error!\n");
            continue;
        }
        else if(flag1 and flag2)
        {
            TR(i,s)
                pc(*i);
            pc('\n');
            continue;
        }
        if(flag1)
        {
            pc(s[0]);
            for(j=1;j<l;j++)
                if(isupper(s[j]))
                {
                    pc('_');
                    pc(char(tolower(s[j])));
                }    
                else pc(s[j]);
            pc('\n');
        }
        else
        {
            pc(s[0]);
            for(j=1;j<l;j++)
                if(islower(s[j]))
                {
                    if(s[j-1]=='_')
                        pc(char(toupper(s[j])));
                    else
                        pc(s[j]);
                }
            pc('\n');
        }
    }
    return 0;
}
