# https://atcoder.jp/contests/arc119/tasks/arc119_b

#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << '=' << x << endl
#define rep(i, b, e) for (int i = b; i <= e; i++)

char s1[512345], s2[512345];
vector<int> a(1234);
vector<int> b(1234);
signed main(void)
{
    int n, cnt = 0;
    cin >> n;
    scanf("%s%s", s1 + 1, s2 + 1);
    rep (i, 1, n)
    {
        if (s1[i] == '0')
        {
            cnt++;
        }
        if (s2[i] == '0')
        {
            cnt--;
        }
    }
    if (cnt != 0)
    {
        puts("-1");
        return 0;
    }
    int ans = 0;
    rep (i, 1, n)
    {
        if (s1[i] == '0')
        {
            a.push_back(i);
        }
        if (s2[i] == '0')
        {
            b.push_back(i);
        }
    }
    for (int i = 0; i <= min(a.size(), b.size()) - 1; i++)
    {
        if (a[i] != b[i])
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}

