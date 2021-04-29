#https://codeforces.com/contest/995/problem/B

so we need to make every same element in adjacent.
We can set an element at the end and find it's mirror in the ith position and swap that mirror to the end untill it reaches
before the end.And then we will decrease n by 2 and continue the same process as result we will get our answer.

-----------------------------------------------------------------------
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,ans=0,a[205]= {0};
    cin>>n;
    n=n*2;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    int k=n;
    while(n!=0)
    {
        int i;
        for (i=1; i<n; i++)
        {
            if (a[i]==a[n])
            {
                break;
            }
        }
        ans+=n-i-1;
        for (; i<n; i++)
            swap(a[i],a[i+1]);

        n=n-2;
    }

    cout<<ans<<endl;
}
