#include<bits/stdc++.h>
using namespace std;

int findmod(char ara[])
{
    int sum=0,i;
    for(i=0; ara[i]; i++)
    {
        sum=sum*10+ara[i]-'0';///as we can divide the number by 4 weather it is divisible by 4 or not
        sum=sum%4;
    }
    return sum;
}
int main()
{
    char ara[100005];
    gets(ara);
    ///we know that (a^b)mod m=a^(b mod pi(m))
    int sum=findmod(ara);
    int ans=1+pow(2,sum)+pow(3,sum)+pow(4,sum);
    ans=ans%5;
    printf("%d",ans);
}

