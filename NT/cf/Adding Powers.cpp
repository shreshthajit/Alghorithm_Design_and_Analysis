#https://codeforces.com/problemset/problem/1312/C



1.If there is same element we can’t make them equal.
2.if all element is zero then we don’t need to make any more step
3.We can skip step as many step as we can
4. We can’t make same step twice


3 9
0 59049 810

We don’t need to use bitmask here.
if we observe how 810 is created
810=9^2+9^3
   =9^(1+9)
so if divide 810 by 9 then the remainder will be 1

if 9^2+9^3+9^4=9^2(1+9+9^2)
so if we divide 91(1+9+9^2) by 9 then the modulo will be 1 so every time
if the number is divided by 9 then the modulo will must be 1 and if not
then there is no answer.

a sample from the terminal is given below:
34
2 9
81 810
temp=81
9 1 0 
temp=810
90 10 1 0 
0 0 2 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
NO




*********************************************************************************************************************************
#include<bits/stdc++.h>

using namespace std;
typedef long long  ll;
int main()
{

    ll T;
    cin>>T;
    while(T--)
    {
        ll n,k;
        cin>>n>>k;
        ll aRR[100];
        memset(aRR,0,sizeof(aRR));
         bool ck=true;

        for(ll i=1; i<=n; i++)
        {
            ll valuE;
            cin>>valuE;
            ll cnt=0;
            while(valuE)
            {
                aRR[cnt]+=valuE%k;
                valuE=valuE/k;
                if(aRR[cnt]>=2){
                    ck=false;
                }
                cnt++;
            }
        }
        if(ck)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }


}


