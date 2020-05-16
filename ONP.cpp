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
inline int priority(char ch)
{
    int p;
    switch(ch)
    {
        case '^': p=1;break;
        case '/': p=2;break;
        case '*': p=2;break;
        case '+': p=3;break;
        case '-': p=3;break;
        default: p=0;break;
    }
    return p;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string infix,postfix;
        cin>>infix;
        stack<char>s;
        s.push('(');
        infix+=')';
        ITER(i,infix)
        {
            if(*i=='(')
                s.push(*i);
            else if((*i>=97&&*i<=122)||(*i>=65&&*i<=90))
                postfix+=*i;
            else if(*i=='^'||*i=='/'||*i=='*'||*i=='+'||*i=='-')
            {
                while(priority(s.top())>=priority(*i))
                {
                    postfix+=s.top();
                    s.pop();
                }
                s.push(*i);
            }
            else
            {
                while(s.top()!='(')
                {
                    postfix+=s.top();
                    s.pop();
                }
                s.pop();
            }
        }
        ITER(i,postfix)
            pc(*i);
        pc('\n');
    }
    return 0;
}
