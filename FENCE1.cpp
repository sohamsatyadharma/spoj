#include<bits/stdc++.h>
#define PI 3.1415926
int main()
{
    int l;
    double d;
    while(scanf("%d",&l))
    {
        if(!l)
            break;
        d=(l*l*1.0)/(2*PI);
        printf("%.2lf\n",d);
    }
    return 0;
}
