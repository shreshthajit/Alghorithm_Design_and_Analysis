Idea 1:
Put a rook in row 1 , so there are c ways (c columns) to do that c * solve(r-1,c-1,k-1)
and don’t put a rook in row 1 , so there are r-1 rows solve(r-1,c,k)
So , ans = c * solve(r-1,c-1,k-1) + solve(r-1,c,k)

Idea 2:
take k row from n row = nCk
take k col from n col = nCk
how many ways k rook arrange among themselves = k!
ans = nCk * nCk * k!

comb[n][k] = comb[n-1][k] + comb[n-1][k-1]

---------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll nCr(int n, int k)
{
    ll ans[n+1][k+1];
    int i,j;

    for(int i = 0; i <= n; i++){

        for(int j = 0; j <= min(i,k); j++){

            if(j == 0 || j == i)
                ans[i][j] = 1;
            else{
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
    }
    return ans[n][k];
}

int main()
{
 int T;
    scanf("%d", &T);
    for(int cs = 1; cs <= T; cs++)
    {
        ll n,k;
        cin >> n >> k;
        ll res = nCr(n,k);
        cout<<res<<endl;
        for(int i =0; i < k; i++){
            res *= n;
            n--;
        }
        printf("Case %d: ",cs);
        cout << res << endl;
    }
    return 0;
}

-----------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define LPII pair<LL, pair<int,int> >
#define MP make_pair
#define F first
#define S second
#define LINF LLONG_MAX


LL shomadhan(LL r,LL c,LL k)
{
   if(k > r || k > c)
       return 0;
   else if(k==(LL)0)
       return 1;
   else if(r==(LL)1)
       return c;
   else return c*shomadhan(r-1,c-1,k-1)+shomadhan(r-1,c,k);
}

int main()
{
   int tc;
   scanf("%d",&tc);

   for(int i=1; i<=tc; i++)
   {
       LL n,k;
       scanf("%lld %lld",&n,&k);

       LL ans=shomadhan(n,n,k);

       printf("Case %d: %lld\n",i,ans);
   }

   return 0;
}

