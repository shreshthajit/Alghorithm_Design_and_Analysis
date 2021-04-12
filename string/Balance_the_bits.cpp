
#observation:

Any balanced bracket sequence must begin with '(' and end with ')'.
  
Therefore, 𝑎 and 𝑏 must agree in the first and last positions, so we require 𝑠1=𝑠𝑛=1 or a solution doesn't exist.

  
The total number of open brackets in 𝑎 and 𝑏 must be 𝑛, which is even. Each 1 bit in 𝑠 creates an even number of open
brackets and each 0 bit creates an odd number of open brackets. Therefore, there must be an even number of 0 bits, 
or a solution doesn't exist. Note that the number of 1 bits also must be even.

  
Assuming these conditions hold, let's construct a solution. Suppose there are 𝑘 positions where 𝑠𝑖=1.
We will make the first 𝑘/2 positions open in both 𝑎 and 𝑏, 
and we will make the last 𝑘/2 positions closed in both 𝑎 and 𝑏.
Then, the 0 bits in 𝑠 will alternate between which string gets the open bracket.




#include<bits/stdc++.h>
#define forr(i,start,count) for (int i = (start); i < (start)+(count); ++i)
#define set_map_includes(set, elt) (set.find((elt)) != set.end())
#define readint(i) int i; cin >> i
#define readll(i) ll i; cin >> i
typedef long long ll;
using namespace std;
string q;

void solve()
{
    int n;
    cin>>n;

    string s;
    cin>>s;
    string a,b;
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='1')
            cnt++;
    }
    if(cnt%2==1 || s[0]=='0'  || s.back()=='0')
    {
        cout<<"NO"<<endl;
        return ;
    }

    bool flip=true;
    int k=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='1')
        {
            if(k<cnt/2)
            {
                a.push_back('(');
                b.push_back('(');
                k++;
            }
            else
            {
                a.push_back(')');
                b.push_back(')');
            }
        }
        else
        {
            if(flip)
            {
                a.push_back(')');
                b.push_back('(');
            }
            else
            {
                a.push_back('(');
                b.push_back(')');
            }
            flip=!flip;
        }
    }
    cout<<"YES"<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
}
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

