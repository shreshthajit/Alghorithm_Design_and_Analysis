#https://codeforces.com/contest/1391/problem/C


In this problem we need to just remove the number of permutations which can't make cycle from total permutation
	
so ans=n!-((n-1)C0+(n-1)C0+(n-1)C0+(n-1)C0+...(n-1)C(n-1))=n!-2^(n-1);

for example
nc0
1 2 3 4
	
3c1	
2 3 4 1
1 3 4 2
1 2 4 3
	
	
3c2
3 4 2 1
2 4 3 1
1 4 3 2

3c3
4 3 2 1

so ans=24-8=16



^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^6
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
ll fact[1000007],mod=1000000007;

ll bigmod(ll n,ll p){
	if(p==0) return 1;
	if(p==1)return (n)%mod;
	if(p%2)return (bigmod(n,p-1)*n)%mod;
	else{
		ll x=bigmod(n,p/2);
		return (x*x)%mod;
	}
}

ll modinverse(ll n){
	return bigmod(n,mod-2)%mod;
}
 
int main()
{
	
 
	ll n,ans=0;
	scanf("%lli",&n);
 
	fact[0]=1;
	for(ll i=1;i<=n;i++){
		fact[i]=(i*fact[i-1]);
		fact[i]%=mod;
	}

	for(ll i=0;i<n;i++){
		ans+=(fact[n-1]*modinverse((fact[i]*fact[n-i-1])%mod))%mod;
		ans%=mod;
	}
 
	printf("%lli",(fact[n]-ans+mod)%mod);
 
	return 0;
}
