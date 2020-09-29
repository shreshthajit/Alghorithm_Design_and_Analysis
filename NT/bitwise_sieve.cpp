#include<bits/stdc++.h>

using namespace std;

bitset<100>bt;
vector<int>prime;

void sieve()
{
    bt.set();
    prime.push_back(2);

    for(long long i=3; i<=100; i=i+2)
    {
        if(bt[i])
        {
            for(long long j=i*i; j<=100; j=j+i)
            {
                bt[j]=0;
            }
            prime.push_back((int)i);
        }
    }
}

int main()
{
    sieve();
    for(int i=0;i<prime.size();i++)
        cout<<prime[i]<<" ";

}
