#https://codeforces.com/contest/1514/problem/B



suppose we have k bits and we have to find the number of arrays with n elements.
so we have to make and of these elements in every array equals to zero and sum of these elements as large as possible.
  
suppose we have k=4 then we have k bits and if the n=6 then

  1 1 1 1 ------->1 1 1 0 so every element we have 6 options means we can choose 6c1 and make it zero
  1 1 1 1 ------->1 1 0 1 as there are k postions in an element so we can change 6c1 x 6c1 x 6c1 x 6c1 x 6c1 x 6c1=6^k ways we
  1 1 1 1 ------->1 0 1 1 can make arrays.
  1 1 1 1 ------->0 1 1 1
  1 1 1 1 ------->1 1 1 1
  1 1 1 1 ------->1 1 1 1
  we have       6c1x6c1x6c1x6c1=6^k options
  

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
        long long ans=1;
        for(int i=0; i<k; i++)
        {
            ans=(ans*n)%(1000000007);
        }
        cout<<ans<<endl;
    }

}
