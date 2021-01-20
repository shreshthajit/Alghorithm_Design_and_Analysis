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
int sum_of_divisors(int N,vector<long long>prime)
{
    int cnt=0,sum=1;

    for(int i=0; prime[i]<sqrt(N)+1; i++)
    {
        if(N%prime[i]==0)
        {
            cnt=1;
            while(N%prime[i]==0)
            {

                cnt=cnt*prime[i];
                N=N/prime[i];
            }
               cnt=cnt*prime[i];
                sum=sum*((cnt-1)/(prime[i]-1));
        }
    }
    if(N>1)
    {
        N=((N*N)-1)/(N-1);//for example if n==33 then her n will be 11
        sum=sum*N;
        ///sum=sum*2;
    }
    return sum;
}
int main()
{
    long long n;
    cin>>n;
    vector<long long >prime=sieve(n);

    int sum=sum_of_divisors(n,prime);
    cout<<sum<<endl;
}
