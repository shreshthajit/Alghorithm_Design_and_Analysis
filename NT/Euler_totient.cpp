#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<long long > sieve(long long N)
{
    long long status[N];
    long long  i, j,sqrtN;

    for( i = 2; i <= N; i++ ) status[i] = 0;

    sqrtN = sqrt(N);

    for(i = 3; i <= sqrtN; i += 2 )
    {
        if( status[i] == 0)
        {
            for( j = i * i; j <= N; j += i + i )

                status[j] = 1; // status of the multiple is 1
        }
    }
    vector<long long >prime;
    prime.push_back(2);
    for( i = 3; i <= N; i += 2 )
    {
        if( status[i] == 0 )
            prime.push_back(i);
    }

    return prime;
}

long long euler_totient(vector<long long>prime,long long n)
{
    long long root=sqrt(n);
    long long rest=n;
    for(long long i=0; i<prime.size() && prime[i]<=root; i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
                n=n/prime[i];

            root=sqrt(n);
            rest=rest-rest/prime[i];
        }
    }
    if(n>1)
    {
        rest=rest-rest/n;
    }
    return rest;
}




int main()
{

    long long n;
    cin>>n;
    vector<long long>prime;
    prime=sieve(n);

    long long ans=euler_totient(prime,n);

    cout<<ans<<endl;
}














