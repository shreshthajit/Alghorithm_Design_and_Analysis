#include<bits/stdc++.h>

using namespace std;

void calculate(string str,int pos=0,string temp="")
{
    if(pos==str.length())
    {
        cout<<temp<<endl;
        return;
    }
    calculate(str,pos+1,temp+str[pos]);
    calculate(str,pos+1,temp);
}
int main()
{
    string s;
    cin>>s;
    calculate(s);
}
