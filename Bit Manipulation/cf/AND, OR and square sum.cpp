#https://codeforces.com/contest/1368/problem/D


We have to choose distinct i and j and replace ai and aj like
ai=ai AND aj
aj=ai OR aj

we can have any number of operations and we have to maximize the value of
sum(ai*ai) from 1 to n


we will consider first 2 bits of ai and aj
let it be b1 and b2 
so c1=b1 AND b2
   c2=b1 OR b2

for example
b1 b2 c1 c2
0  0  0  0
0  1  0  1
1  0  0  1
1  1  1  1
  
so we can see that in c1 and c2 the bits in b1 and b2 are are seeming like shifting to the higher bit postion
as 0 1  becomes 0 1
   1 0 becomes  0 1
    ans so on
  
  
  if A=000101001
     B=000010000
    OR=000111001
    so we will replace all of bits meaning the Number B with the corresponding OR value and it seems like we are shifting
    the set bits to the right position
     so we we do the OR operation then the bits get shifted to the right.
  
  
  as we can do AND and OR operation as many times as we want we can shift the set bit to the right position by doing
  OR operation and so we will take an array called bits and every time we will take the setbits for every element of the array
 in the first two loop.
    
  in the second loop we will take if the bits is set then we will do the OR operation.
  If the bit in the jth position is set then we will set the j th bit of x .
   for exaple 
   
   bits-> 6 5 4 3 2 1 0
          2 3 4 1 2 0 2 here the non zero number represents the number of set bits in the jth postion of every element
          so we will take that bit from that place and push it to the jth bit of x and thus we are creating the
          largest value.
     
------------------------------------------------------------------------------------------------------------------------------------
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
int main()
{
    ll n;
    cin>>n;
    vector<ll>bits(20,0);
    ll a;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        for(int j=0; j<20; j++)
        {
            if(a&(1<<j))
            {
                bits[j]++;
            }
        }
    }
    ll ans=0;
    for(int i=0; i<n; i++)
    {
        ll b=0;
        for(int j=0; j<20; j++)
        {
            if(bits[j]>0)
            {
                b=b|(1<<j);//here we are setting the jth bit of b is 1 from the left.
                bits[j]--;
            }
        }
        ans=ans+b*b;
    }
    cout<<ans<<endl;
}
