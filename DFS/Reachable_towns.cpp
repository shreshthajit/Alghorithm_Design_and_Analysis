#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

const int maxn = 2e5+7;
int ans[maxn], k;
vector<int> edges[maxn], v;
bitset<maxn> done;

void dfs(int c)
{
    done[c]=1;
    ++k;
    v.push_back(c);
    for (int i : edges[c])
        if (!done[i])
            dfs(i);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,mini;
    cin>>n;
    pair<pii,int> p[n];
    for (int i=0;i<n;++i)
    {
        cin>>p[i].f.f>>p[i].f.s;
        p[i].s=i+1;
    }

    sort(p,p+n);
    stack<pii> st;

    for (int i=0;i<n;++i)
    {
        mini=p[i].f.s;
        while (sz(st)&&st.top().f<p[i].f.s)
        {
            edges[st.top().s].push_back(p[i].s);
            edges[p[i].s].push_back(st.top().s);
            mini=min(mini,st.top().f);
            st.pop();
        }
        st.push({mini,p[i].s});
    }
    for (int i=1;i<=n;++i)
    {
        if (!done[i])
        {
            k=0;
            v.clear();
            dfs(i);
            for (int i : v)
                ans[i]=k;
        }
        cout<<ans[i]<<"\n";
    }
    return 0;
}

