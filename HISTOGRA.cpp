#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll getMaxArea(ll hist[], ll n)
{
    stack<ll> s;
    ll max_area = 0, tp, area_with_top;
    ll i = 0;
    while (i < n)
    {
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
        else
        {
            tp = s.top(); 
            s.pop();  
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
    while (!s.empty())
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
    return max_area;
}
int main() 
{
	while(1)
	{
	    ll n;
        scanf("%lld", &n);
        if(!n)
            break;
        ll hist[n];
	    for(ll i=0; i<n; i++)
	        scanf("%lld", &hist[i]);
	   ll ans=getMaxArea(hist, n);
	   printf("%lld\n", ans);
	}
	return 0;
}
