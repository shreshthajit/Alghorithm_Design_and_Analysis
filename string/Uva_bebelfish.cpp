#include<bits/stdc++.h>
using namespace std;

bool comp(const pair<int,int> &a,const pair<int,int> &b)
{
    if(a.first==b.first)
    {
        return a.second<b.second;
    }
    else
        return a.first>b.first;
}


int main()
{

    string str;
    map<string,string>mp;

    while(1)
    {
        getline(cin,str);
        stringstream s(str);
        if(str=="")
            break;
        string a,b;
        s>>a>>b;
        if(a=="")
            break;
        mp[b]=a;
    }

    while(1)
    {
        cin>>str;
        if(mp.find(str)!=mp.end())
            cout<<mp[str]<<endl;
        else
            cout<<"eh"<<endl;
    }


}




