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


vector<long long>  prime_factorization(long long N,vector<long long>prime){

   vector<long long>factor;

    for(int i=0; prime[i]<=N; i++)
    {
        if(N%prime[i]==0)
        {
            while(N%prime[i]==0)
            {

                factor.push_back(prime[i]);
                N=N/prime[i];
            }
        }
    }
    return factor;

}


int main()
{
    long long N;
    cin>>N;

    vector<long long >prime=sieve(N);
    ///for(int i=0; i<print_prime.size(); i++)
    /// cout<<print_prime[i]<<" ";


    vector<long long >factor=prime_factorization(N,prime);


    for(int i=0;i<factor.size();i++)
    cout<<factor[i]<<" ";

    return 0;
}
