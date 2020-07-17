#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long  t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;
        int ans=0;
        while(n>=5)
        {
            ans=ans+n/5;
            n=n/5;
        }
        cout<<ans<<endl;
    }

}
