#include<bits/stdc++.h>

using namespace std;
int main()
{
    string s;
    cin>>s;
    vector<char>v;
    set<char>st;
    for(int i=0;i<s.size();i++)
    {
        st.insert(s[i]);
    }
    v.assign(st.begin(),st.end());
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
}

