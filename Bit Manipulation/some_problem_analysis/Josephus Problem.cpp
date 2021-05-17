1. You are given an integer N which represents the total number of soldiers standing in a circle having position marked from 1 to N.
2. A cruel king wants to execute them but in a different way.
3. He starts executing soldiers from 1st position and proceeds around the circle in clockwise direction.
4. In each step, every second soldier is executed.
5. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed soldiers are removed), until only the last soldier remains, who is given freedom.
6. You have to find the position of that lucky soldier.
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll sum(ll n)
{
    ll ans=0;
    while(n>0)
    {
        ans=ans+n%10;
        n=n/10;
    }
    return ans;

}
ll power_of_two(ll n){

  ll i=1;
  while(i*2<=n){
    i=i*2;
  }
  return i;

}
int main()
{
    ll n;
    cin>>n;
    ll l=n-power_of_two(n);
    cout<<2*l+1;

}

  
  
  
  
  
  
