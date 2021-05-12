#https://codeforces.com/contest/630/problem/K


 We need to find how many numbers are from 1 to n such that they are not divisible by 2 to 10.
  
 We can observe the face that if a number is divisbile by 4,6,8,10 then it must be divisible by 10 and the same for the rest
 of the number.
 so we can check weather a number is divisible by 2,3,5 or 7
 Here we can use principle of inclusion-exclusion.
 
 If we would  have taken number 2,3,5 and the n=30 then we can check what is the formula.
   and=30-n/2-n/3-n/5+n/(2*3)+n/(2*5)+n/(3*5)-n/(2*3*5)
   
   because 
   30/2=2 4 10 12 14 16 18 20 22 24 26 28 30
   30/3=3 6 9 12 15 18 21 24 27 30
   30/5=5 10 15 20 25 30
   30/(2*3)=6 12 18 24 30
   30/(2*5)=10 20 30 
   30/(3*5)=15 30
   30/(2*3*5)=30
   and now we can clearly check what is happening.
   and the same approach we have used in the following problem.
   ----------------------------------------------------------------------------------

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
        ll n;
        cin>>n;
        ll ans=n-n/2-n/3-n/5-n/7
         +n/(2*3)+n/(2*5)+n/(2*7)+n/(3*5)+n/(3*7)+n/(5*7)
         -n/(2*3*5)-n/(2*3*7)-n/(2*5*7)-n/(3*5*7)
         +n/(2*3*5*7);
        cout<<ans<<endl;
}

