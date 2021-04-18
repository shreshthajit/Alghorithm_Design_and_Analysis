#https://codeforces.com/contest/1497/problem/C1


In this version we need to find 3 different element such that lcm(a1,a2,a3)<=n/2 and here k=3.
 
if n is odd we will take n/2,n/2 and 1 because we have to find lcm with 1 and two same number n/2 which will gave us lcm which 
will satisfy our condition. if n is even then n/2 will give us odd number and then we can subtrace 1 it will give us even number
and thus we can take (n/2-1) (n/2-1) 2 and this will give us lcm<=n/2.
 but if n is divisible by 4 suppose we take 8 and then 8/2 -1 is an odd number so we can take it .
   so the answer will be n/4 n/4 n/2;
 














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
        if(n%4==0){
            cout<<n/4<<" "<<n/4<<" "<<n/2<<endl;
        }
        else if(n%2==0){
            cout<<n/2-1<<" "<<n/2-1<<" "<<2<<endl;
        }
        else{
            cout<<n/2<<" "<<n/2<<" "<<1<<endl;
        }
    }
}
