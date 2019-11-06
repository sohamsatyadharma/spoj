#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() 
{
    int t;
    scanf("%d", &t);
	while(t--)
	{
	    ll n, ans=-1;
        scanf("%lld", &n);
        ll r[n], R[n];
        priority_queue< pair<ll, ll> > inner, outer;
        for(ll i=1; i<=n; i++)
        {
            scanf("%lld %lld", &r[i], &R[i]);
            inner.push({r[i], i});
            outer.push({R[i], i});
        }
        outer.pop();
        if(inner.top().first>outer.top().first)
            ans=inner.top().second;
        printf("%lld\n", ans);
	}
	return 0;
}
