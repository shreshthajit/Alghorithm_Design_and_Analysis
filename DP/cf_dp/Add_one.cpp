so as per the statement we need to increase every digit of a number .
so we can precalculte those length by dp.
	
	
	here is dp is storing the length of the one digit number after it is creased m times
	
	
  
     if n=88 and m=2
     then if we increase
     8----9---10
     here we can precalculate the length of 8 after increase m times which is 2 and the number is 10.
      
     if n=12  m=1
     we have store the length of 0-9 as 1.
       
     so length of 11 after increase will be dp[11-10]=1 + dp[11-9]=1;
      

     length of  25 will be the (dp[21-10]=dp[11]) + (dp[21-9]=dp[12])
     so if we know dp[11] and dp[12] we can easily calculate dp[21] which is the length of 21 after increasing by one.
	     
     
	     
	     
     suppose we need to find 192 after m operations.
     we can take the last digit and add dp[n%10+m] every time we divide the number by 10.   
	  
------------------------------------------------------------------------------------------------------------------------



#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int max_n = 2e5+1000;

const ll mod = 1e9+7;
ll dp[max_n];
int n,m;
int main()
{
	ios::sync_with_stdio(0);
	for (int i=0;i<=9;++i)
    dp[i]=1;

	for (int i=10;i<max_n;++i)
    dp[i]=(dp[i-9]+dp[i-10])%mod;

	int t;
	cin>>t;
	while (t--)
	{
		cin>>n>>m;
		ll ans = 0;
		while (n)
		{
			ans = (ans+dp[n%10+m])%mod;
			n/=10;
		}
		cout<<ans<<endl;
	}
}
