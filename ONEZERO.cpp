#include<stdio.h>
#include<iostream>
#include<string>
//#include<queue>
#define MAX 100005
using namespace std;
typedef long long int ll;
struct node
{
    string s;
    int r;
};
class queue
{
    int f, r, size;
    node arr[MAX];
    bool full()
    {
        return size==MAX;
    }
public:
    queue()
    {
        f=size=0;
        r=MAX-1;
    }
    bool empty()
    {
        return size==0;
    }
    node front()
    {
        return arr[f];
    }
    void push(node x)
    {
        if(full())
            return;
        r=(r+1)%MAX;
        arr[r]=x;
        size++;
    }
    void pop()
    {
        if(empty())
            return ;
        f=(f+1)%MAX;
        size--;
    }
};
bool visited[20001];
int modulo(string s, int n)
{
    int l=s.length(), r=0;
    for(int i=0; i<l; i++)
        r=(r*10+s[i]-'0')%n;
    return r;
}
void bfs(int n)
{
    queue q;
    node temp;
    temp.s="1";
    temp.r=1%n;
    q.push(temp);
    visited[temp.r]=true;

    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        visited[temp.r]=true;
        if(!temp.r)
        {
            cout<<temp.s<<endl;
            break;
        }
        string s0=temp.s+'0', s1=temp.s+'1';
        int r0=modulo(s0, n);
        int r1=modulo(s1, n);
        if(!visited[r0])
        {
            node t;
            t.s=s0;
            t.r=r0;
            q.push(t);
            //visited[r0]=true;
        }
        if(!visited[r1])
        {
            node t;
            t.s=s1;
            t.r=r1;
            q.push(t);
            //visited[r1]=true;
        }
    }
    //return str;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i=0; i<20001; i++)
            visited[i]=false;
        bfs(n);
    }
    return 0;
}
