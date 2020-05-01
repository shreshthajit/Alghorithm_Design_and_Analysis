#include<bits/stdc++.h>

using namespace std;

int T[1000][1000];


int pal(string str)
{
    int length=str.length();

    for(int i=0; i<length; i++)
    {
        T[i][i]=1;
    }


    for(int l=2; l<=length; l++)
    {
        for(int i=0; i<length-l+1; i++)
        {
            int j=i+l-1;
            if(l==2 && str[i]==str[j])
                T[i][j]=2;
            else if(str[i]==str[j])
            {
                T[i][j]=2+T[i+1][j-1];
            }
            else
            {
                T[i][j]=max(T[i][j-1],T[i+1][j]);
            }
        }
    }
    return T[0][length-1];
}














int main()
{
    string s;
    cin>>s;
    int length=pal(s);
    cout<<length<<endl;
    char pal[length+1];
    int Start=0;
    int End=length-1;
    int i=0,j=s.length()-1;

    while(End-Start>=1)
    {
        if(s[i]==s[j])
        {
            pal[Start]=s[i];
            pal[End]=s[i];
            Start +=1;
            End--;
            i=i+1;
            j=j-1;
        }
        else
        {
            if(T[i+1][j]>T[i][j-1])
            {
                i++;
            }
            else
            {
                j=j-1;
            }
        }
    }
    if(Start==End)
    {
        pal[Start]=s[i];
    }
    cout<<pal;

}
// abbbxbbcxbbba






