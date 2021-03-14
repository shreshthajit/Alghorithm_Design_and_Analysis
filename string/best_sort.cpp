#include<bits/stdc++.h>
using namespace std;



bool operator<(const pair<int,pair<int,int>> &a, const pair<int,pair<int,int>> &b)
{
    if(a.first==b.first)
    {
        if(a.second.first<b.second.first)
            return a.second.second<b.second.second;
        else
            return a.second.second>b.second.second;
    }
    else
    {
        return a.first<b.first;
    }
}

int main()
{
    int n;
    cin>>n;
    map<pair<int,pair<int,int> >,string>mp;
    string name;
    int day,month,year;
    while(n--)
    {
        cin>>name>>day>>month>>year;
        mp[ {year,{month,day}}]=name;
    }
    cout<<(*mp.rbegin()).second<<endl;
    cout<<(*mp.begin()).second<<endl;

}

