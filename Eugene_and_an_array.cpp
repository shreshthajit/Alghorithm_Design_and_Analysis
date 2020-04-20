#include<bits/stdc++.h>

using namespace std;


vector< pair<unsigned long long,unsigned long long>> find_subarrays(vector<unsigned long long>arr,unsigned long long  n)
{
    unordered_map<unsigned long long,vector<unsigned long long >> map;

    unsigned long long  sum=0;

    vector<pair<unsigned long long,unsigned long long >>out;

    for(int i=0; i<n; i++)
    {
        sum +=arr[i];

        if(sum==0)
            out.push_back(make_pair(0,i));

        if(map.find(sum)!=map.end())
        {
            vector<unsigned long long >v=map[sum];
            for(auto it=v.begin(); it!=v.end(); it++)
            {

                out.push_back(make_pair(*it+1,i));

            }
        }

        map[sum].push_back(i);
    }

    return out;
}




int main()
{
    unsigned long long n;
    cin>>n;

    ///int arr[n];
    vector<unsigned long long>arr;

    unsigned long long num=0,i,ans=0,x;

    for(i=0; i<n; i++){
        cin>>x;
        arr.push_back(x);
        }

    vector<pair<unsigned long long,unsigned long long> >zero_sum;

    zero_sum = find_subarrays(arr,n);

    /// zero_sum.size();

    vector<unsigned long long>store;
    for(auto it=zero_sum.begin();it!=zero_sum.end();it++)
    {
     num=it->second;
     store.push_back(num);
    }

    sort(store.begin(),store.end());

    reverse(store.begin(),store.end());
    ///cout<<"num="<<num<<endl;


    if(zero_sum.size()!=0)
    ans=((n*(n+1))/2)-(zero_sum.size()+(store[0]-store[store.size()-1]));

    else
    ans=((n*(n+1))/2);


    cout<<ans<<endl;
}
