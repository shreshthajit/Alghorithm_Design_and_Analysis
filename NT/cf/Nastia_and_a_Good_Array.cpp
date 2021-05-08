#https://codeforces.com/contest/1521/problem/B


In this problem we will select two indices and can the value of those indices with two values x and y such that
min(ai,bi)=min(x,y) and every i from 2 to n gcd(ai,a[i-1])=1
 
We obesrve the fact that every time the minimum value is not chaning that means we can change only the maximum value of 
(ai,bi) and replace it with other element.And so the solution is quite simple. We can take the minimum value from the array.
  and replace the next value with the next value of that value and the same thing we will do when will go to the right of that
  min value.
    
for exaple we can take this sample
5
9 6 3 11 15
in this array the minimum value is 3 and when we will move to the right we will replace the value with 4 and 5
  and the same thing when we will move to the left.And thus our gcd will also be 1.
------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+1];
        int mn=INT_MAX;
        int indx=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i]<mn)
            {
                mn=a[i];
                indx=i;
            }
        }
        int k=mn+1;
        if(indx==0)
        {
            cout<<n-1<<endl;
            for(int i=1; i<n; i++)
            {
                cout<<1<<" "<<i+1<<" "<<mn<<" "<<k++<<endl;
            }
        }
        else
        {
            cout<<n-1<<endl;
            for(int i=indx+1; i<n; i++)
            {
                cout<<indx+1<<" "<<i+1<<" "<<mn<<" "<<k++<<endl;
            }
            k=mn+1;
        for(int i=indx-1;i>=0;i--){
            cout<<indx+1<<" "<<i+1<<" "<<mn<<" "<<k++<<endl;
        }
        }



    }

}
