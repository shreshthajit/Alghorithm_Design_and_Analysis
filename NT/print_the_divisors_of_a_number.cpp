#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mx=1000002;
int f[mx],k;
ll prime[78500];
void sieve()
{
    for(int i=4; i<mx; i+=2)f[i]=1;
    for(int i=3; i*i<mx; i+=2)
        if(!f[i])
            for(int j=i*i; j<mx; j+=i+i)
                f[j]=1;
    for(int i=2; i<mx; i++)if(!f[i])prime[k++]=i;
}

pair<ll,int> fac[100];
int id;
ll factorize(ll N)
{
    id=0;
    ll an=1;
    for(int i=0; i<k && prime[i]*prime[i]<=N; i++)
    {
        if(N%prime[i]==0)
        {
            int c=0;
            while(N%prime[i]==0)
            {
                N/=prime[i];
                c++;
            }
            fac[id++]= {prime[i],c};
            an=(an*(c+1));
        }
    }
    if(N!=1)
    {
        fac[id++]= {N,1};
        an*=2;
    }
    return an;
}
ll divi[1000000],idx=0;
void backtrack(int pos,ll val)
{
    if(pos==id)
    {
        divi[idx++]=val;
        return;
    }
    for(int i=0; i<=fac[pos].second; i++)
    {
        backtrack(pos+1,val);
        val*=fac[pos].first;
    }
}
void pre(ll n)
{
    ll di=factorize(n);
    idx=0;
    backtrack(0,1);
}
int main()
{
    sieve();
    ll n;
    cin>>n;
    pre(n);
    for(int i=0; i<idx; i++)cout<<divi[i]<<endl;
}

