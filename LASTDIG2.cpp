#include<stdio.h>
#include<string.h>
int main()
{
    char base[1005];
    unsigned long long index;
    int t,l,i;
    scanf("%d",&t);
    while(t--)
    {
        int ans=1,temp;
        scanf("%s",base);
        scanf("%llu",&index);
        l=strlen(base);
        temp=base[l-1]-48;
        index=(index%4||!index)?(index%4):4;
        for(i=0;i<index;i++)
            ans*=temp;
        ans%=10;
        printf("%d\n",ans);
    }
    return 0;
}
