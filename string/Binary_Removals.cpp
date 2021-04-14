
if we loop through backwards and if we can't find any string that is 00 then we can clearly say that we can remove all those zeroes
and find a sorted string which consist only one.
  
else if we find 00 as a substring than we will store the index of that positio and break.

we will check weather there is a contiguous substing 11 before that index by looping throgh from that index

so if we find such a string that is 11 then the answer is no ....otherwise the answer is always yes.
 
so we can make an other solution by iterating from 0 to s.length and do the vice versa....

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin>>s;
        int flag=0;
        int indx=s.length();
        for(int i=s.length()-1; i>0; i--)
        {
            if(s[i]=='0' && s[i-1]=='0')
            {
                flag=1;
                indx=i-1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        int flag2=0;
        for(int i=indx; i>0; i--)
        {
            if(s[i]=='1' && s[i-1]=='1')
            {
                flag2=1;
                break;
            }
        }
        if(!flag2)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
}
