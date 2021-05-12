#https://codeforces.com/problemset/problem/1349/A

We can take example:
N=4
10 24 40 80
lcm={120 40 80 120 240 80}

10={(2,1),(5,1)}
24={(2,3),(3,1)}
40={(2,3),(5,1)}
80={(2,4),(5,1)}

1.If a Prime P appears N-2 times or less than N-2 then  this prime P will not be included in the answer.
for exaple if lcm(10,24)=120 and lcm(24,40)=120 and lcm(24,80)=240 so 3 is included only this three lcm
and when we take gcd of every lcm  we will notice that the lcm which does not contain 3  will not be a part of gcd.
Because if 3 doesn't contain in two number than this two number will generate a lcm which will not contain 3.
 
  
  
4
3 5 25 125
lcm={15 75 375 25 125 125}
  
3={(3,1)}
5={(5,1)}
25={(5,2)}
125={(5,3)}

2.So we can see that 5 appears n-1 times which is 3 times.
So if a number appears n-1 times than the answer would have p^k where k is the smallest power
and here the lcm 15 contains 5 just ones times which is the smallest power.
Because the number which doesnot contain 5 will get a 5 when doing lcm with that number.
  
 
3
5 25 125
lcm={25  125 125}
 
5={(5,1)}
25={(5,2)}
125={(5,3)}

3.So if Prime P appears in N number than we will add P^k to the answer where k is the second smallest power.

---------------------------------------------------------------------------------------------------------------------------------  
 
#include <bits/stdc++.h>
using namespace std;

using ll = long long int ;

ll Pow(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b%2)
            res=res*a;

        a=a*a;
        b=b/2;
    }
    return res;
}
int main()
{
    ll n;

    cin>>n;

    map<ll,vector<ll>>mp;

    set<ll>uni;
    ll a;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        ll num=a;
        for(int i=2; i*i<=num; i++)
        {
            if(num%i==0)
            {
                ll cnt=0;
                uni.insert(i);
                while(num%i==0)
                {
                    num=num/i;
                    cnt++;
                }
                mp[i].push_back(cnt);
            }
        }
        if(num>1)
        {
            uni.insert(num);
            mp[num].push_back(1);
        }
    }

    ll ans=1;
    for(auto& it:uni)
    {
        ll  x=it;
        if(mp[x].size()<n-1)
        {
            continue;
        }
        sort(mp[x].begin(),mp[x].end());

        if(mp[x].size()==n-1)
        {
            ans=ans*Pow(x,mp[x][0]);
        }
        else if(mp[x].size()==n)
        {
            ans=ans*Pow(x,mp[x][1]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
