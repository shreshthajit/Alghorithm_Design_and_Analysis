In this problem we have to make a string s equal to another string t;
So the operation is like we have to go to the right first and then to the left

So in the implementation code we first select a letter which matches a letter 






#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        string t;
        cin>>s>>t;
        int i=s.size()-1;
        bool ck=false;
        for(int i=0; i<s.size(); i++)
        {
            int cur=0;
            for(int j=i; j<s.size(); j++)
            {
                if(s[j]!=t[cur])break;

                int x=++cur;
                for(int k=j-1; j<s.size() and k>=0; k--)
                {
                    if(s[k]!=t[x])
                        break;
                    x++;
                }
                if(x==t.size())
                {
                    ck=true;
                    break;
                }
            }
        }
        if(ck)
            cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }

    }

}
