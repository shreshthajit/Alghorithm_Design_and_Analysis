#https://codeforces.com/contest/1499/problem/C

as per the problem statement we need to find the minimum cost from 0,0 to n,n;
we can move up or right.
the observation is however we move up or right  the value of up and right must have to be n after reaching n,n;
we will use a priority queue to maintain the smaller cost which we will use to travel as we have to multiply the length of the segment
by the minimum cost.

so if the direction is U R U R U or R U R U R or whatever ,we can see that in the even postion all of them are weather up or right.
and in the odd position all of them are weather up or right.so if we loop through n and store the cost of the even position in a priority
queue and the cost of the odd position in another priority queue.
    
So, we can complete our path from k=2 to n segments
and so we will take the minimum of all those ans and print it.
 
 So how do we calculate it?
 
 we will use a pre variable which will store the sum every time we take a value from c
 it means that we have all the values that we have taken recently and we will add the minimum value from priority queue and
 multiply it by n-pq.size  both for odd and even priority queue.
 It  means that we will take first ci values one times which have stored in the pre variable and add the rest of the segments which is
 n-taken values(pq.size) and multiple by the minimum value.we are multiplying the large portion with the minimum cost everytime
 and thus we will get a minimum answer.
     
   so we have taken the minimum value for the larger segment by multiplyring the larger segment by the minimum value and 
   rest value we have taken just one times.


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
