#https://codeforces.com/contest/1512/problem/E

The input will consist n,l,r,sum which means we have to find such sum that is made from  the sum from position l to r.
So the code that we have used is working because we are checking from the left and from the right serially and if the 
sum including n exist between those checking then there must be an answer.
  
for example if n=5
 1 2 3 4 5
 sum=1 2 3 4 5 8 9 10 11 12.......
 8-->1 2 5
     1 3 4
 
 9-->1 3 5
     2 3 4
 
 10-->1 4 5
      2 3 5
  
  
  and we can take many more example and check that if the sum between those two kinds of checking then there must an answer.
   -----------------------------------------------------------------------------------------------------------------------------


#include<bits/stdc++.h>
using namespace std;
bool possible(int l,int sum,int n)
{
    int maxi=0,mini=0,c=1,d=n;
    for(int i=0; i<l; i++)
    {
        maxi+=d--;
        mini+=c++;
    }
    if(sum>maxi || sum<mini)
        return false;
    return true;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,l,r, sum;
        int maxi=0,mini=0;
        cin>>n>>l>>r>>sum;

        int c=1,d=n;
        for(int i=0; i<r-l+1; i++)
        {
            maxi +=d;
            mini+=c;
            d--;
            c++;
        }
        int length=r-l+1;

        if(sum>maxi || sum<mini)
        {
            cout<<-1<<endl;
            continue;
        }
        vector<int>v1,v2;
        map<int,int>mp;
        for(int i=n; i>=1; i--)
        {
            if(sum-i>=0 && possible(length-1,sum-i,i-1))
            {
                sum=sum-i;
                mp[i]++;
                length--;
                v1.push_back(i);
            }
            if(sum==0)
                break;
        }
        if(sum!=0)
        {
            cout<<-1<<endl;
            continue;
        }

        for(int i=1; i<=n; i++)
        {
            if(mp.find(i)==mp.end())
            {
                v2.push_back(i);
            }
        }
        int j=0,k=0;
        for(int i=1; i<l; i++)
        {
            cout<<v2[j++]<<" ";
        }
        for(int i=l; i<=r; i++)
        {
            cout<<v1[k++]<<" ";
        }
        for(int i=r+1; i<=n; i++)
        {
            cout<<v2[j++]<<" ";
        }
        cout<<endl;
    }
}
