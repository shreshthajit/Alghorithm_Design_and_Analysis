#https://atcoder.jp/contests/abc201/tasks/abc201_b


#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int>& a,
         pair<string, int>& b)
{
    return a.second > b.second;
}
void sort(map<string, int>& M)
{
    vector<pair<string, int> > A;

    for (auto& it : M)
    {
        A.push_back(it);
    }

    sort(A.begin(), A.end(), cmp);
    int c=0;
    for (auto& it : A)
    {
        c++;
        if(c==2)
        {
            cout<<it.first<<endl;
            break;
        }
    }
}
int main()
{
    map<string, int> M;

    int n;
    cin>>n;
    string s;
    int a;
    for(int i=0; i<n; i++)
    {
        cin>>s>>a;
        M[s]=a;
    }
    sort(M);
    return 0;
}
