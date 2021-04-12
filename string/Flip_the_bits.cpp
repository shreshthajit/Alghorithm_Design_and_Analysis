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
    string a,b;
    cin>>a>>b;
    int one=0,zero=0;

    int j=0;
    vector<pair<int,int>>v;

    for(int i=0; i<n; i++)
    {
        if(a[i]=='1')
            one++;
        else
            zero++;
        if(one==zero)
        {
            v.push_back(make_pair(j,i));
            j=i+1;
        }
    }
    for(auto x:v)
    {
        int start=x.first;
        int end=x.second;

        if(a[start]==b[start])
        {
            continue;
        }
        else
        {
            for(int j=start; j<=end; j++)
            {
                if(a[j]=='0')
                    a[j]='1';
                else
                    a[j]='0';
            }

        }
    }
    for(int i=0; i<n; i++)
    {
        if(a[i]!=b[i])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;

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

