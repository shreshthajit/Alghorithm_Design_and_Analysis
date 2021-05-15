#include <bits/stdc++.h>
#include <iostream>
using namespace std;

using ll = long long;
const int MAX = 32002;

vector<vector<int>>primes;
void sieve()
{
    bool isPrime[MAX];
    for (int i = 0; i < MAX; ++i) isPrime[i] = true;

    for (int i = 3; i * i <= MAX; i += 2)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    vector<int>v;
    for(int i=3; i<MAX; i+=2)
    {

        if(isPrime[i])
        {
            if(v.size()==0 || v.size()==1)
            {
                v.push_back(i);
                continue;
            }
            else
            {
                if(v[1]-v[0]==i-v.back())
                {
                    v.push_back(i);
                    continue;
                }
                if(v.size()>2)
                {
                    primes.push_back(v);
                }
                int a=v.back();
                v.clear();
                v.push_back(a);
                v.push_back(i);
            }
        }
    }
}

signed main()
{
    sieve();
    int  a,b;
    while (cin>>a>>b && (a || b))
    {
        if(a>b)
            swap(a,b);


        int sz=primes.size();
        for(int i=0; i<sz; i++)
        {
            if(a>primes[i][0] || primes[i].back()>b )
            {
                continue;
            }
            cout<<primes[i][0];
            for(int j=1; j<primes[i].size(); j++)
            {
               cout<<" "<<primes[i][j];
            }
            cout<<endl;

        }
    }
    return 0;
}
