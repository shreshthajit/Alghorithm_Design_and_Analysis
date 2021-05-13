#https://codeforces.com/problemset/problem/1325/D

Given u and v
We need to find an array such that bitwise X-OR of all its elements are u and sum of all its elements are v.

  
The following statement holds for any a and b.
u=a^b
v=a+b

a + b = a ^ b + 2 * (a & b)  
  
Why is a + b = a ^ b + 2 * (a & b) true? 

a ^ b is add without considering the carries. So in order to get a + b from a ^ b we need to take the
missing carry part into account. When does carry happen? Exactly when a[k] == b[k] = 1. So we basically 
left out 2 equal part of indices where a[i] == b[i] = 1, which is exacly 2 * (a & b).
  

1.If u>v and u%2!=v%2 then the answer is -1
2.So if u==v and u==0 then the answer is 0
and the rest condition are given in the code
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#include<bits/stdc++.h>
using namespace std;

int main()
{
        long long int u,v;
        cin>>u>>v;
        if(u > v || u % 2 != v % 2)
        {
             cout<<-1<<endl;
        }
        else if(u == v)
        {
            if(u == 0)
            {
                 cout<<0<<endl;
            }
            else
            {
                cout<<1<<endl;
                cout<<u<<endl;
            }
        }
        else
        {
            long long int d = (v - u) / 2;
            if((u & d) != 0)
            {
                cout<<3<<endl;
                cout<<u<<" "<<d<<" "<<d<<endl;
            }
            else
            {
                cout<<2<<endl;
                cout<<(u+d)<<" "<<d<<endl;
            }
        }
}
