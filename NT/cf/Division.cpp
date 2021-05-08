 #https://codeforces.com/contest/1445/problem/C

In this problem we  will be given two numbers p and q.
We need to find a geteast number x such that it is divisible by p and x is not divisble by q.
  
If we observe the fact that if the number p is not divisible by q than the answer is always p.
  
But the problem arose when p is  divisble by q.

for example we can take an exaple .....
  if p= 2 x 2 x 2 x 3 x 3 x 3 x 5
    q=2 x 2 x 3 x 3 
  
    so we can remove such elements such that q can't divide p then we will get our answer.
    so we will take the prime number from q and if it is divisble by q then we will remove this number from p by dividing
    but we have to remove number untill p%q!=0 because if we remove 2 from this p then we can see that the number of 2 is 
    more than q and thus q will divide p and so we have to divide q by that i and take the maximum p and thus we will get
    our answer.
   
--------------------------------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define int long long

int p,q;
int ans;
int solve(int k)
{
    int temp=p;

    while(temp%k==0)
    {
        temp=temp/k;

        if(temp%q)
        {
            ans=max(ans,temp);
            break;
        }
    }
    return temp;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ans=1;
        cin>>p>>q;
        if(p%q)
        {
            cout<<p<<endl;
            continue;
        }
        else
        {
            for(int i=1; i*i<=q; i++)
            {
                if(q%i==0)
                {
                    if(i!=1)
                    ans=max(ans,solve(i));

                    ans=max(ans,solve(q/i));
                }

            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
