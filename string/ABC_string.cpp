#include<bits/stdc++.h>
using namespace std;
#define mod (int) 998244353
#define MOD (int) 1e9+7
#define X 1001100011100001111ll
#define all(a) a.begin(),a.end()
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define loop(i,a,b) for (int i = a; i < b; i++)
#define bloop(i,a,b) for (int i = a ; i>=b;i--)
#define tc(t) int t; cin >> t; while (t--)
#define int long long
#define ll long long
#define pb emplace_back
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define in(x) scanf("%d", &x)
#define rr return 0
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define inf (int)(1e18)
#define ini(a, i) memset(a, i, sizeof(a))
#define vi vector<int>
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define vii vector<ii>
long long  binpow(long long  x, long  n)
{
    x %= MOD;
    long long  res = 1 ;
    while( n > 0)
    {
        if( n & 1 ) res = ( res * x ) % MOD ;
        ///n >>= 1 ;
        n=n/2;
        x = ( x * x ) % MOD;
    }
    return res ;
}

bool balanced(string s)
{
    stack<char>st;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else
        {
            if(st.empty())
            {
                st.push(s[i]);
                break;
            }
            else
            {
                st.pop();
            }
        }
    }

    if(!st.empty())
        return false;
    else
        return true;
}
signed main()
{
    tc(t)
    {
        string s;
        cin>>s;
        int len=s.length();
        if(s[0]==s[len-1])
        {
            cout<<"NO"<<endl;
            continue;
        }
        char x;
        if((s[0]=='A'  || s[len-1]=='A') && (s[0]=='B'  || s[len-1]=='B'))
        {
            x='C';
        }
        else if((s[0]=='A'  || s[len-1]=='A') && (s[0]=='C'  || s[len-1]=='C'))
        {
            x='B';
        }
        else
        {
            x='A';
        }

        char Fa=s[0],La=s[len-1];

        string s2=s;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]==Fa)
            {
                s[i]='(';
                s2[i]='(';
            }
            if(s[i]==La)
            {
                s[i]=')';
                s2[i]=')';
            }
            if(s[i]==x)
            {
                s[i]='(';
                s2[i]=')';
            }
        }
       /// cout<<s2<<endl;


        if(balanced(s))
        {
            cout<<"YES"<<endl;
            continue;
        }
        if(balanced(s2))
        {
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;

    }


}
