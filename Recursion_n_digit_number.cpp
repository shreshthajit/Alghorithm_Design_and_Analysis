#include<bits/stdc++.h>

using namespace std;

void print(int n,int pos=1,string str="")
{
    if(n==str.length())
    {
        cout<<str<<endl;
        return;
    }

    for(int i=0; i<=9; i++)
    {
        if(pos==1 && i==0)
        {
            continue;
        }
        print(n,pos+1,str+to_string(i));
    }
}

int main()
{

    int n;
    cin>>n;
    print(n);
}

