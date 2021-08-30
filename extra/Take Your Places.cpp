#https://codeforces.com/contest/1556/problem/B

1. What if we just swap the element that should be in the odd position because the even elements will get in the there postion automatically
2. So we will take the odd elements postion in a vector and the even elements's postion in a vector 
3.So if we take a variable i and increase it by two and subtract the odd value's postion from it we will see that this will be our answer and do the same for 
  even elements and this will give us ans and we wil take out of this two calculation.
  
-----------------------------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;

int ans(vector<int>a)
{
    int i=0, k=0;
    ll sum=0;
    while(k<a.size())
    {
       /// cout<<a[k]<<" "<<i<<" "<<endl;
        sum+=abs(a[k++]-i);

        i+=2;
    }
    ///cout<<endl;
    return sum;
}

//0 1 2
//3 4 5
/*
0 1 2 3 4 5
1 1 1 2 2 2

0 0
1 2
2 4
*/
//even--->3 2 1

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n), odd, even;
    int i;
    for(i=0; i<n; i++) cin>>v[i];
    if(n==1)
    {
        cout<<0<<endl;
        return;
    }

    for(i=0; i<n; i++)
    {
        if(v[i]%2) odd.push_back(i);
        else even.push_back(i);
    }
    int o=odd.size(), e=even.size();
    if(abs(o-e)>1)
    {
        cout<<"-1\n";
        return;
    }
    int answers;
    if(n%2==0)
    {
        answers = min(ans(odd), ans(even));
    }
    else
    {
        if(odd.size()>even.size())
            answers=ans(odd);
        else
            answers=ans(even);
    }
    cout<<answers<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}
