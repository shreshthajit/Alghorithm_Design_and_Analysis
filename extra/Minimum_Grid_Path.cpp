#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
         vector<ll>c(n);
        priority_queue<ll, vector<ll>, greater<ll>>even_pq , odd_pq;
        ll pre=0;
        ll ans=LLONG_MAX;
        for(ll i=0; i<n; i++)
        {
            cin>>c[i];
            if(i%2)
            {
                odd_pq.push(c[i]);
            }
            else
            {
                even_pq.push(c[i]);
            }
            pre=pre+c[i];
            if(i)
            ans=min(ans,pre+((n - (ll)even_pq.size()) * even_pq.top()) +( (n - (ll)odd_pq.size())*odd_pq.top()));
        }
        cout<<ans<<endl;
    }
    return 0;
}
