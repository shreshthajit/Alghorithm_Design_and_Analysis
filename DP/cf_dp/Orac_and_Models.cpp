#https://codeforces.com/contest/1350/problem/B



In this problem we need to find the maxium length of increasing elements such that the in original array the indices i+1
  is divisible by i and here we have used the dp approch.
  
7
1 4 2 3 6 4 9

index  1 2 3 4 5 6 7
       1 4 2 3 6 4 9
 i=1-> 1 2 2 2 2 2 2
 i=2->       3   3 
 i=3->           3
  
if i==1 we have stored for each indx if the value in that index is greater than a[1] and if it is true we have increased it by 1

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool isprime(ll n)
{
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n+1];
        ll ans[n+1];
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            ans[i]=1;
        }
        ll mx=1;
        for(int i=1; i<=n; i++)
        {
            for(int j=i+i; j<=n; j=j+i)
            {
                if(a[j]>a[i])
                {
                    ans[j]=max(ans[j],ans[i]+1);
                    mx=max(mx,ans[j]);
                }
            }
        }
        cout<<mx<<endl;
    }
}
 
