#https://codeforces.com/contest/1497/problem/B


In this problem we have to divide the element of the array into some arrays so that every two adjacent element is divided 
by k and note that a array with a single element will be considered as k divisible.

so we will use the modulo idea.
  
we can take an example:
6 4
2 2 8 6 9 4 7

here we can see that 4 and 8 is divisible by k=4. So we will those element in a single array which are divided by k.

if the element is not divisible k then
1. we will take the mod of those value.
 so 
 so the mod value will be from 0 to k-1;
 2%4=2;
 2%4=2;
 8%4=0;
 6%4=2;
 9%4=1;
 4%4=0;
 7%4=3'
 

 1.so we will take 4 and 8 into a sigle array.
 2. if 2*mod==k then we can store them in a single array because then every two element will be divisible by k.
 3. if 2*mod<k then we will take k-mod and mod value in a array and this will give us an k divisible array and the rest
  element we will put in single array.
----------------------------------------------------------------------------------------
#include<bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;

        map<int,int>mp;
        int a;
        for(int i=0; i<n; i++)
        {
            cin>>a;
            mp[a%k]++;
        }
        int ans=0;

        for(auto c:mp)
        {
            if(c.first==0)
            {
                ans++;
            }
            else if(2*c.first==k)
            {
                ans++;
            }
            else if(2*c.first<k || mp.find(k-c.first)==mp.end())if c.first< k or c.first>k then this condition will work
              //because we will take c.first and k-c.first in a array and the rest element we will take in different array.
              //so there is no possibility for counting the complement value twice.
            {
                int x=c.second;
                int y=mp[k-c.first];
                ans=ans+1+max(0,abs(x-y)-1);
            }

        }
        cout<<ans<<endl;
    }
}
