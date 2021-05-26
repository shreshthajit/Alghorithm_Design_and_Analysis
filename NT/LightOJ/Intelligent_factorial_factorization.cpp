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


vector<long long>  prime_factorization(long long N,vector<long long>prime)
{
    vector<long long>factor;

    for(int k=2; k<=N; k++)
    {
        int p=k;
        for(int i=0; prime[i]<=k; i++)
        {
            if(p%prime[i]==0)
            {
                while(p%prime[i]==0)
                {

                    factor.push_back(prime[i]);
                    p=p/prime[i];
                }
            }
        }
    }
    return factor;
}
int main()
{
    /////long long t;
    ///cin>>t;

    ll t;
    cin>>t;

    vector<long long >prime=sieve(100);

    sort(prime.begin(),prime.end());
    long long k=1;

    while(t--)
    {


        long long N;
        cin>>N;


        vector<long long >factor=prime_factorization(N,prime);

        sort(factor.begin(),factor.end());


        map<long long,long long>mp;
        map<long long,long long>::iterator it;

        for(long long  i=0; i<factor.size(); i++)
        {
            mp[factor[i]]++;
        }

        cout<<"Case "<<k++<<": "<<N<<" = ";


        vector<long long>first;
        vector<long long>second;

        for(auto it=mp.begin(); it!=mp.end(); it++)
        {
          ///cout<<it->first<<" ("<<it->second<<") *";
          first.push_back(it->first);
          second.push_back(it->second);
        }
        for(int i=0;i<first.size()-1;i++)
        cout<<first[i]<<" ("<<second[i]<<") * ";

        cout<<first[first.size()-1]<<" ("<<second[first.size()-1]<<")";

        cout<<endl;
        mp.clear();
    }
    return 0;
}
