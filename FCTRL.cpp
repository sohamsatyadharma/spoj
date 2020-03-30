#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    long t;
    cin>>t;
    while(t--)
    {
        long a,s=0,i,x=0;
        cin>>a;
        while(pow(5,x)<a)
            x++;
        for(i=1;i<=x;i++)
            s+=a/pow(5,i);
        cout<<s<<endl;
 
    }
 
    return 0;
}
