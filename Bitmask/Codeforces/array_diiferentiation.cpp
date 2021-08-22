
#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& nums)
{

    map<int,int>mp;
    int siz=nums.size();
    int subsetNum=1<<siz;
    for(int mask=0; mask<subsetNum; mask++)
    {
         int sum=0;
        for(int i=0; i<siz; i++)
        {
            if(mask&(1<<i))
            {
                sum+=nums[i];
            }
        }
        mp[sum]++;
    }
    for(auto it:mp)
    {
        if(it.second>1){
            cout<<"YES"<<endl;
        return;
        }

    }
    cout<<"NO"<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++)
            cin>>nums[i];

        solve(nums);


    }
}
/*



*/
