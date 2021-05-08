#https://codeforces.com/contest/1521/problem/A

We can read the statement form the above link.
  
Here we have given two number A and B.

We need to find three number x,y,z such that exactly one of them is good and other two are nearly good.
  so if we write 
  x=A y=A x B and z= B
  then x + y = z
       A + A x B = B
       A(1 + B)= B
       and we can see that if B==1 then there is no answer satisfying this condition
       so our answer is x=A,  y=A x B , z=A x B + A;
---------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main()
{
     int t;
     cin>>t;
     while(t--){
        int a,b;
        cin>>a>>b;
         if(b==1){
            cout<<"NO"<<endl;
         }
         else{
            cout<<"YES"<<endl;
            cout<<a<<" "<<a*b<<" "<<a*b+a<<endl;
         }
     }

}
