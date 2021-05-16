#https://codeforces.com/contest/1525/problem/A

In this problem we will given k and we have to make a solution where essence will be k% and water (100-k)%
so we need to find the minimum number of steps to make this k% and we need to just maintain the ratio.
  
k=2  2%=2/100=1/50  so we need just 50 steps as 50*0.02=1 which gives us 2%
k=3 3%=3/100=3/100  so we need exactly 100 steps as 3/100=3%
k=25 25%=25/100=1/4 so we need just 4 steps in way like 1 liter for the essence and 3 litre for the water.
k=50  50%=50/100=1/2 so we need just 2 steps as 1/2=50%
k=11  11%=11/100 so we need 100 steps as we can't fractionize it more and thus we need 11 + 89 is total 100 and gives us 11% for essence

so we need to find the gcd of k and 100 and k and dividing 100 by this gcd will give us the answer.
because gcd will divide k and 100 as we need to fractionize it more and thus the denominator will give us the answer.
------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mx=1000002;
int f[mx],k;
ll prime[78500];


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        if(__gcd(100,k)==1){
            cout<<100<<endl;
        }
        else{
            cout<<100/(__gcd(100,k))<<endl;
        }
    }
}
